#ifndef APPSETTING_H
#define APPSETTING_H

#include <iostream>
#include <fstream>
#include <QSettings>
#include <QFile>

namespace App
{
    enum class Theme { Black , White };
    enum class Lang { CN , EN };
    enum class LaneMode { Simulator , SingleLane , DualLane };
    enum class MachineType { SPI , AOI3D };

    class AppSetting
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor


        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.访存函数


        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.成员函数
        void load(const QString& path);

    private:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4.成员变量
        Theme m_theme;
        Lang m_lang;
        LaneMode m_laneMode;
        MachineType m_machineType;
        std::string m_companyName;
        std::string m_jobFolderPath;
    };

}//End of namespace App


#endif // APPSETTING_H
