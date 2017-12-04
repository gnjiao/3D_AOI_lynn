#ifndef APPSETTING_H
#define APPSETTING_H

#include <iostream>
#include <fstream>
#include <QSettings>
#include <QFile>

namespace App
{
    enum class THEME { BLACK , WHITE };
    enum class LANG { CN , EN };
    enum class LANEMODE { SIMULATOR , SINGLE_LANE , DUAL_LANE };
    enum class MACHINETYPE { SPI , AOI3D };

    /**
     *  @brief  app配置文件类，存放app配置文件中的信息，有读配置文件的功能：
     *                  1.若配置文件正常，读配置文件并且将配置文件中的信息存到成员变量中
     *                  2.若配置文件不正常，将相应的成员变量设置为默认值
     *  @author lynn
     *  @version 1.00 2017-11-29 lynn
     *                note:create it
     */
    class AppSetting
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor

        /*
        *  @brief   类的构造函数，占无内容
        *  @param   N/A
        *  @return  N/A
        */
        AppSetting();

        /*
        *  @brief   类的析构函数，占无内容
        *  @param   N/A
        *  @return  N/A
        */
        ~AppSetting();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.set & get function

        /*
        *  @brief   返回默认的程式存放路径
        *  @param   N/A
        *  @return  默认的程式存放路径
        */
        std::string jobFolderPath() { return this->m_jobFolderPath; }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.member function

        /*
        *  @brief   加载app配置文件
        *  @param   app配置文件的路径
        *  @return  N/A
        */
        void load(const QString& path);

    private:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4.member variant
        THEME m_theme{THEME::BLACK};
        LANG m_lang{LANG::CN};
        LANEMODE m_laneMode{LANEMODE::SIMULATOR};
        MACHINETYPE m_machineType{MACHINETYPE::SPI};
        std::string m_companyName{"\0"};
        std::string m_jobFolderPath{"\0"};
    };

}//End of namespace App


#endif // APPSETTING_H
