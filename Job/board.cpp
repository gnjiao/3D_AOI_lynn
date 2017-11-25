#include "board.hpp"

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
        if(!file.open(QFile::ReadOnly))
        {
            std::cout <<"XML文件创建不成功！！！";
            return;
        }

        //增加一个一级子节点以及元素
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();

        //创建根节点
        QDomElement root = doc.documentElement();
        //创建next子节点board
        QDomElement board = doc.createElement("基板信息");
        board.setAttribute("板名",QString::fromStdString(this->m_name));
        board.setAttribute("板宽",QString::number(this->m_sizeX));
        board.setAttribute("板长",QString::number(this->m_sizeY));
        board.setAttribute("x原点",QString::number(this->m_originalX));
        board.setAttribute("y原点",QString::number(this->m_originalX));

        //获取链表首个元素地址
        Job::MeasuredObj *pWritingObj = (this->m_measuredObjs).getHeadMeasuredObj();

        QDomElement object;        //board的子节点object

        //存入所有原件的数据
        for ( int i = 1; i <= (this->m_measuredObjs).getSize(); ++i)
        {
            //存入一个元件的数据：
            object = doc.createElement(QString::fromStdString((*pWritingObj).getName()));
            object.setAttribute("高度",QString::number(((*pWritingObj).getBody()).getHeight()) );
            object.setAttribute("宽度",QString::number(((*pWritingObj).getBody()).getWidth()) );
            object.setAttribute("x坐标",QString::number(((*pWritingObj).getBody()).getXPos()) );
            object.setAttribute("y坐标",QString::number(((*pWritingObj).getBody()).getYPos()) );

            //添加boject到board节点
            board.appendChild(object);

            //将待写入的元素指针改为指向链表的下一个元素
            pWritingObj = (*pWritingObj).getPNextMeasuredObj();
        }


        //添加board到根节点
        root.appendChild(board);

        if(!file.open(QFile::WriteOnly|QFile::Truncate))    //若打开文件失败
            return;
        //输出到文件
        QTextStream out_stream(&file);
        doc.save(out_stream,4); //以缩进4格方式输出，也有其他输出方式（格式）

        file.close();
    }

}//End of namespace Job
