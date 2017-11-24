#ifndef INSPECTIONDATA_H
#define INSPECTIONDATA_H

#include <QFile>
#include <QDoubleValidator>
#include <QDomDocument>
#include <QXmlStreamWriter>

#include"board.hpp"

namespace Job
{
    class InspectionData
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.访存函数
        Job::Board &getBoard() { return this->m_board; }        //TBC:此处直接返回了个引用，不合理，想想修改办法
        void setBoard(Job::Board board) { this->m_board = board; }

        std::string getVersion() { return this->m_version; }
        void setVersion(std::string version) { this->m_version = version; }

        std::string getLastEditingTime() { return this->m_lastEditingTime; }
        void setLastEditingTime(std::string lastEditingTime)
        {
            this->m_lastEditingTime = lastEditingTime;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.成员函数
        void writeToXml(std::string path);

    private:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4.成员变量
        Job::Board m_board;
        std::string m_version;
        std::string m_lastEditingTime;
    };

}//End of namespace Job

#endif // INSPECTIONDATA_H
