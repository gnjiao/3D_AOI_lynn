#include <iostream>

#include "./SDK/customexception.hpp"
#include"./Job/measuredobj.hpp"
#include"./Job/measuredobjlist.hpp"
#include"./SDK/rectangle.hpp"
#include"./Job/board.hpp"
#include"./Job/inspectiondata.hpp"
#include"./App/appsetting.hpp"
#include"./App/capturesetting.hpp"
#include"./App/app.h"

using namespace std;

int main()
{
   App::MainWindow lynn;
   lynn.loadAppSetting("./init/aaaa");
   lynn.loadJobFolder();
   lynn.inspectionData().board().measuredObjs().print();
}


