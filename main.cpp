#include <iostream>

#include "./SDK/customexception.hpp"
#include "./Job/measuredobj.hpp"
#include "./Job/measuredobjlist.hpp"
#include "./SDK/rectangle.hpp"
#include "./Job/board.hpp"
#include "./Job/inspectiondata.hpp"
#include "./App/appsetting.hpp"
#include "./App/capturesetting.hpp"
#include "./App/mainwindow.hpp"

using namespace std;

int main()
{
   try
   {
       //配置文件的路径：
       QString appSettingPath = "./init/appSetting.init";
       QString captureSettingPath = "./init/captureSetting.init";

       //>>>-------------------------------------------------------------------------------------------------------------------------------------
       //1.加载配置文件
       App::MainWindow mainWindow;
       mainWindow.loadAppSetting(appSettingPath);
       mainWindow.loadCaptureSetting(captureSettingPath);

       //>>>-------------------------------------------------------------------------------------------------------------------------------------
       //2.加载程式，将程式信息导出为xml文件
       mainWindow.loadJobFolder();

       //>>>-------------------------------------------------------------------------------------------------------------------------------------
       //3.打印程式中的元件信息
       mainWindow.inspectionData().board().measuredObjs().print();
   }
   catch(const SDK::CustomException& ex)
   {
       //打印异常信息
       std::ostringstream message;
       message << "File:"<<__FILE__<<"\n"
               << "Line:"<<__LINE__<<"\n"
               << "Func:"<<__FUNCTION__<<"\n"
               << " " << "\n"\
               << "Detail:"<<ex.what()<<"\n";
       std::cout << message.str();
   }
}


