#include <iostream>

#include "customexception.h"
#include"measuredobj.hpp"
#include"measuredobjlist.hpp"
#include"rectangle.h"
#include"board.h"
#include"inspectiondata.h"
#include"appsetting.h"

using namespace std;

int main()
{
    QString path = "./aaaaaa.init";
    App::AppSetting lynn;
    lynn.load(path);
    return 0;
}

