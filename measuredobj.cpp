#include "measuredobj.h"


Job::MeasuredObj::MeasuredObj()
{
    this->pNextMeasuredObj = nullptr;
    this->pPreMeasuredObj = nullptr;
}

Job::MeasuredObj::MeasuredObj(Job::MeasuredObj *preMeasureObj,
                              Job::MeasuredObj *nextMeasureObj)
{
    this->pNextMeasuredObj = nextMeasureObj;
    this->pPreMeasuredObj = preMeasureObj;
}

Job::MeasuredObj::~MeasuredObj()
{
    this->pNextMeasuredObj = nullptr;
    this->pPreMeasuredObj = nullptr;
}
