#ifndef BOARD_H
#define BOARD_H

#include <QFile>
#include <QDoubleValidator>
#include <QDomDocument>
#include <QXmlStreamWriter>
#include <QTextStream>

#include"measuredobjlist.hpp"

namespace Job
{

    class Board
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor
        Board();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.访存函数
        double getSizeX() { return this->m_sizeX; }
        void setSizeX(double sizeX) { this->m_sizeX = sizeX; }

        double getSizeY() { return this->m_sizeY; }
        void setSizeY(double sizeY) { this->m_sizeY = sizeY; }

        double getOriginalX() { return this->m_originalX; }
        void setOriginalX(double originalX) { this->m_originalX = originalX; }

        double getOriginalY() { return this->m_originalY; }
        void setOriginalY(double originalY) { this->m_originalY =originalY; }

        std::string getName() { return this->m_name; }
        void setName(std::string name) { this->m_name = name; }

        Job::MeasuredObjList & getMeasuredObjs(){ return this->m_measuredObjs; }
        void setMeasuredObjs(Job::MeasuredObjList measuredObjs)         //TBC:将这里的参数改为引用
        {
            this->m_measuredObjs = measuredObjs;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.成员函数
        void randomMeasuredObjs();
        void writeToXml(std::string path);

    private:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4.成员变量
        Job::MeasuredObjList m_measuredObjs;
        std::string m_name;
        double m_sizeX;
        double m_sizeY;
        double m_originalX;
        double m_originalY;
    };

}//End of namespace Job


#endif // BOARD_H
