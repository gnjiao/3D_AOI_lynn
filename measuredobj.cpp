#include "measuredobj.hpp"


Job::MeasuredObj::MeasuredObj()
{
    this->m_pNextMeasuredObj = nullptr;
    this->m_pPreMeasuredObj = nullptr;
}

Job::MeasuredObj::MeasuredObj(Job::MeasuredObj *pPreMeasureObj,
                              Job::MeasuredObj *pNextMeasureObj)
{
    this->m_pNextMeasuredObj = pNextMeasureObj;
    this->m_pPreMeasuredObj = pPreMeasureObj;
}

Job::MeasuredObj::~MeasuredObj()
{
    this->m_pNextMeasuredObj = nullptr;
    this->m_pPreMeasuredObj = nullptr;
}

void Job::MeasuredObj::randomMeasuredObj()
{
    //随机生成rectangle的数据的上下限
    double maxHeight = 150.00;
    double minHeight = 0.01;
    double maxWidth = 150.0;
    double minWidth = 0.01;
    double maxX = 100.00;
    double minX = 0.00;
    double maxY = 100.00;
    double minY = 0.00;

    //生成一个数据随机的rectangle
    SDK::Rectangle randomRectangle;
    randomRectangle.setHeight(RANDOM_NUM(minHeight,maxHeight));
    randomRectangle.setWidth(RANDOM_NUM(minWidth,maxWidth));
    randomRectangle.setXPos(RANDOM_NUM(minX,maxX));
    randomRectangle.setYPos(RANDOM_NUM(minY,maxY));

    srand(time(0));
    this->setBody(randomRectangle);     //将随机生成的rectangle赋给当前对象
}
