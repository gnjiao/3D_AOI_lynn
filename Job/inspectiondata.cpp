#include "inspectiondata.hpp"

void Job::InspectionData::writeToXml(std::string path)
{
    QFile file(QString::fromStdString(path));
    if(!file.open(QFile::WriteOnly|QFile::Text))            //打开传入路径文
    {
        std::cout <<"XML文件创建不成功！！！";
        return;
    }

    //向文件写入程式的基本信息
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("程式基本信息");
    xmlWriter.writeAttribute("版本",QString::fromStdString(this->m_version));
    xmlWriter.writeAttribute("最后修改时间",QString::fromStdString(this->m_lastEditingTime));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();

    (this->getBoard()).writeToXml(path);
}
