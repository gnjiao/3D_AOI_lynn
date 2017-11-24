#include <iostream>

#include "./SDK/customexception.hpp"
#include"./Job/measuredobj.hpp"
#include"./Job/measuredobjlist.hpp"
#include"./SDK/rectangle.hpp"
#include"./Job/board.hpp"
#include"./Job/inspectiondata.hpp"
#include"./App/appsetting.hpp"
#include"./App/capturesetting.hpp"

using namespace std;

int main()
{
    QString path = "./aaaaaa.init";
    App::AppSetting lynn;
    lynn.load(path);

    Job::InspectionData lala;
    lala.getBoard().randomMeasuredObjs();
    lala.getBoard().getMeasuredObjs().print();
    lala.writeToXml("aaabbb.xml");


//    App::CaptureSetting lynn;
//    lynn.load("./aa");
    return 0;
}

