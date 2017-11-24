#include "board.h"

namespace Job
{
    Board::Board()
    {
        this->m_sizeX = 0;
        this->m_sizeY = 0;
        this->m_originalX = 0;
        this->m_originalY = 0;
        this->m_name = "\0";
    }

    void Job::Board::randomMeasuredObjs()
    {
        char name[10];
        char namePrefixArr[][5]={"chip","ic"};

        for ( int i = 1; i <= 50; ++i)
        {
            //1.生成元件名：
            if ( i <= 30 ){
                std::sprintf(name,"%s%02d",namePrefixArr[1],i);
            }
            else {
                std::sprintf(name,"%s%02d",namePrefixArr[0],i - 30);
            }

            //2.生成要push到元件（元件数据为随机生成）
            Job::MeasuredObj pushingMeasuredObj;
            pushingMeasuredObj.randomRectangle();           //随机生成元件的数据
            pushingMeasuredObj.setName(name);               //给元件赋元件名

            //3.将刚生成的元件加入列表
            this->m_measuredObjs.pushHead(pushingMeasuredObj);
        }
    }

    void Board::writeToXml(std::string path)
    {
        QFile file(QString::fromStdString(path));
        if(!file.open(QIODevice::WriteOnly|QIODevice::Append))  //打开传入路径文件
        {
            std::cout << "XML文件打开不成功！！！" << std::endl;
            return;
        }

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartElement("元件信息");

        Job::MeasuredObj *pWritingObj = (this->m_measuredObjs).getHeadMeasuredObj();
        for ( int i = 1; i <= (this->m_measuredObjs).getSize(); ++i)
        {
            //存入元件名
            xmlWriter.writeTextElement("元件"+QString::number(i),QString::fromStdString((*pWritingObj).getName()));
                            //TBC:board的信息漏了，补上
            //存入元件的相关数据
            xmlWriter.writeStartElement("属性");
            xmlWriter.writeTextElement("高度",QString::number(((*pWritingObj).getBody()).getHeight()) );
            xmlWriter.writeTextElement("宽度",QString::number(((*pWritingObj).getBody()).getWidth()) );
            xmlWriter.writeTextElement("x坐标",QString::number(((*pWritingObj).getBody()).getXPos()) );
            xmlWriter.writeTextElement("y坐标",QString::number(((*pWritingObj).getBody()).getYPos()) );
            xmlWriter.writeEndElement();

            //将待写入的元素指针改为指向链表的下一个元素
            pWritingObj = (*pWritingObj).getPNextMeasuredObj();
        }

        xmlWriter.writeEndElement();
        file.close();
    }

}//End of namespace Job
