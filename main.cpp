#include <iostream>

#include "customexception.h"
#include"measuredobj.hpp"
#include"measuredobjlist.hpp"
#include"rectangle.h"
#include"board.h"
#include"inspectiondata.h"
#include"appsetting.h"
#include"capturesetting.h"

using namespace std;

int main()
{
//    QString path = "./aaaaaa.init";
//    App::AppSetting lynn;
//    lynn.load(path);

//    Job::Board lala;
//    lala.randomMeasuredObjs();
//    (lala.getMeasuredObjs()).print();
//    lala.writeToXml("aaabbb.xml");


    App::CaptureSetting lynn;
    lynn.load("./aa");
    return 0;
}


