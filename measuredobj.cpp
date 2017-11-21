#include "measuredobj.hpp"


Job::MeasuredObj::MeasuredObj()
{
    this->m_pNextMeasuredObj = nullptr;
    this->m_pPreMeasuredObj = nullptr;
}

Job::MeasuredObj::MeasuredObj(Job::MeasuredObj *preMeasureObj,
                              Job::MeasuredObj *nextMeasureObj)
{
    this->m_pNextMeasuredObj = nextMeasureObj;
    this->m_pPreMeasuredObj = preMeasureObj;
}

Job::MeasuredObj::~MeasuredObj()
{
    this->m_pNextMeasuredObj = nullptr;
    this->m_pPreMeasuredObj = nullptr;
}
