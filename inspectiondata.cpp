#include "inspectiondata.h"

void Job::InspectionData::writeToXml(std::string path)
{
    QFile file(QString::fromStdString(path));
    if(!file.open(QFile::WriteOnly|QFile::Text))            //打开文件
    {
        std::cout <<"XML文件创建不成功！！！";
    }

    //向文件写入程式的基本信息
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("程式基本信息");
    xmlWriter.writeTextElement("版本",QString::fromStdString(this->m_version));
    xmlWriter.writeTextElement("最后修改时间",QString::fromStdString(this->m_lastEditingTime));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
    (this->getBoard()).writeToXml(path);
}
