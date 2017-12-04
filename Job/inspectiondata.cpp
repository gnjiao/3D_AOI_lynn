#include "inspectiondata.hpp"

Job::InspectionData::InspectionData()
{

}


Job::InspectionData::~InspectionData()
{

}


void Job::InspectionData::writeToXml(std::string path)
{
    QFile file(QString::fromStdString(path));
    if(!file.open(QFile::WriteOnly|QFile::Text))//打开传入路径文
    {
        std::cout <<"XML文件创建不成功！！！";
        return;
    }

    QXmlStreamWriter xmlWriter(&file);          //向文件写入程式的基本信息

    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("程式基本信息");
    xmlWriter.writeAttribute("版本",QString::fromStdString(this->m_version));
    xmlWriter.writeAttribute("最后修改时间",QString::fromStdString(this->m_lastEditingTime));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();

    (this->board()).writeToXml(path);           //写入基板及所有元件信息
}
