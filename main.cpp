#include <iostream>

#include "customexception.h"
#include "rectangle.h"
#include "measuredobj.hpp"
#include "measuredobjlist.hpp"
#include "board.h"

using namespace std;

int main()
{
    Job::Board lynn;
    lynn.randomMeasuredObjs();
    (lynn.getMeasuredObjs()).print();

//    Job::MeasuredObj s1;
//    Job::MeasuredObj s2;
//    Job::MeasuredObj s3;
//    Job::MeasuredObjList lynn;
//    lynn.pushHead(s2);
//    lynn.pushTail(s1);
//    lynn.print();

    return 0;
}

