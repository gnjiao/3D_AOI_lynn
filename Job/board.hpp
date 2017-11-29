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
    /**
     *  @brief 基板类，在成员变量中存储基板的基本信息，能够将基板中的信息（含基板中元件的信息）存
     *         出为xml格式
     *  @author lynn
     *  @version 1.00 2017-11-29 lynn
     *                note:create it
     */
    class Board
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.set & get function

        /*
        *  @brief   获得基板的宽度
        *  @param   N/A
        *  @return  基板的宽度
        */
        double sizeX() { return this->m_sizeX; }

        /*
        *  @brief   修改基板的宽
        *  @param   要设置的基板宽度
        *  @return  N/A
        */
        void setSizeX(double sizeX) { this->m_sizeX = sizeX; }

        /*
        *  @brief   获得基板的长度
        *  @param   N/A
        *  @return  基板的长度
        */
        double sizeY() { return this->m_sizeY; }

        /*
        *  @brief   修改基板的长度
        *  @param   要设置的基板长度
        *  @return  N/A
        */
        void setSizeY(double sizeY) { this->m_sizeY = sizeY; }

        /*
        *  @brief   获得基板相对于机器原点的x坐标
        *  @param   N/A
        *  @return  基板相对于机器原点的x坐标
        */
        double originalX() { return this->m_originalX; }

        /*
        *  @brief   修改基板相对于机器原点的x坐标
        *  @param   要设置的x坐标值
        *  @return  N/A
        */
        void setOriginalX(double originalX) { this->m_originalX = originalX; }

        /*
        *  @brief   获得基板相对于机器原点的y坐标
        *  @param   N/A
        *  @return  基板相对于机器原点的y坐标
        */
        double originalY() { return this->m_originalY; }

        /*
        *  @brief   修改基板相对于机器原点的y坐标
        *  @param   要设置的y坐标值
        *  @return  N/A
        */
        void setOriginalY(double originalY) { this->m_originalY =originalY; }

        /*
        *  @brief   获取基板的名字
        *  @param   N/A
        *  @return  基板的名称
        */
        std::string name() { return this->m_name; }

        /*
        *  @brief   修改基板的名称
        *  @param   要设置的基板的名称
        *  @return  N/A
        */
        void setName(std::string name) { this->m_name = name; }

        /*
        *  @brief   获取基板中所有元件的信息
        *  @param   N/A
        *  @return  基板中所有元件的信息
        */
        Job::MeasuredObjList & measuredObjs(){ return this->m_measuredObjs; }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.member function

        /*
        *  @brief   将基板中的信息（含基板中元件的信息）存出为xml格式
        *  @param   导出的xml文件的路径
        *  @return  N/A
        */
        void writeToXml(std::string path);

    private:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.member variant
        Job::MeasuredObjList m_measuredObjs;
        std::string m_name;
        double m_sizeX;                 //基板宽度
        double m_sizeY;                 //基板长度
        double m_originalX;             //基板相对于机器原点的x坐标
        double m_originalY;             //基板相对于机器原点的y坐标
    };

}//End of namespace Job


#endif // BOARD_H
