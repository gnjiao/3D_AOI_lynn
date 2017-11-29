#ifndef CAPTURESETTING_H
#define CAPTURESETTING_H

#include <QSettings>
#include <QFile>

#include "./SDK/customexception.hpp"

namespace App
{
    enum class IMGBITS { BIT8, BIT16 };

    /**
     *  @brief  标定文件类，存放标定文件中的配置信息，能够：
     *                  1.加载标定文件，若正常则保存到相应的成员变量
     *                  2.加载标定文件，若不正常则抛出异常
     *  @author lynn
     *  @version 1.00 2017-11-29 lynn
     *                note:create it
     */
    class CaptureSetting
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor
        CaptureSetting();

        ~CaptureSetting();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.member function
        /*
        *  @brief   加载标定文件，若加载异常就抛出异常，若正常保存到相应的成员变量
        *  @param   标定文件路径
        *  @return  N/A
        */
        void load(const QString& path);

    private:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.member variant
        int m_imgWidth;
        int m_imgHeight;
        IMGBITS m_imgBits;
    };

}//End of namespace App

#endif // CAPTURESETTING_H
