#ifndef APP_H
#define APP_H

#include <time.h>
#include <QDir>

#include "DB/sqlitedb.hpp"

#include "appsetting.hpp"
#include "capturesetting.hpp"
#include "../Job/inspectiondata.hpp"
#include "./SDK/datahelper.hpp"
#include "./SDK/customexception.hpp"

namespace App
{
    /**
     *  @brief   主程序类，具有以下功能：
     *           1.加载app配置文件，若加载异常则设置为默认值
     *           2.加载标定文件，若加载异常则抛出异常
     *           3.加载程式，若程式不存在创建默认程式
     *           4.创建默认程式
     *           5.将程式信息导出为xml文件
     *  @author  lynn
     *  @version 1.00 2017-11-25 lynn
     *                note:create it
     */
    class MainWindow
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor
        MainWindow();

        /*
        *  @brief   释放链表开辟的内存空间
        *  @param   N/A
        *  @return  N/A
        */
        ~MainWindow();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.set&get function

        /*
        *  @brief   返回成员变量m_inspectionData的引用
        *  @param   N/A
        *  @return  m_inspectionData的引用
        */
        Job::InspectionData &inspectionData() { return this->m_inspectionData; }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.member function

        /*
        *  @brief   加载app配置文件，若读取错误则设置默认值
        *  @param   app配置文件的路径
        *  @return  N/A
        */
        void loadAppSetting(QString path);

        /*
        *  @brief   加载标定文件，若读取错误则抛出异常
        *  @param   标定文件的路径
        *  @return  N/A
        */
        void loadCaptureSetting(QString path);

        /*
        *  @brief   加载程式路径1.若无程式或目录，创建默认程式(目录)
        *                     2.若有程式，读取用户选择的程式
        *  @param   N/A
        *  @return  N/A
        */
        void loadJobFolder();

        /*
        *  @brief   加载检测程式
        *  @param   检测程式的路径
        *  @return  N/A
        */
        void loadInspectionData(std::string path);

        /*
        *  @brief   创建默认的检测程式（数据为随机生成）
        *  @param   创建程式的路径
        *  @return  N/A
        */
        void createDefaultJob(std::string path);

        /*
        *  @brief   将程式数据导出为xml文件
        *  @param   导出文件的路径
        *  @return  N/A
        */
        void writeToXml(std::string path);

    private:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4.member variant
        AppSetting m_appSetting;
        CaptureSetting m_captureSetting;
        Job::InspectionData m_inspectionData;
    };

}//End of namespace App


#endif // APP_H
