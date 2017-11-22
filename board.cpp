#include "board.h"

namespace Job
{
    Board::Board()
    {
        this->m_sizeX = 0;
        this->m_sizeY = 0;
        this->m_originalX = 0;
        this->m_originalY = 0;
        this->m_name = "\0";
    }

    void Job::Board::randomMeasuredObjs()
    {
        char name[10];
        char namePrefixArr[][5]={"chip","ic"};

        for ( int i = 1; i <= 50; ++i)
        {
            //1.生成元件名：
            if ( i <= 30 ){
                std::sprintf(name,"%s%02d",namePrefixArr[1],i);
            }
            else {
                std::sprintf(name,"%s%02d",namePrefixArr[0],i - 30);
            }

            //2.生成要push到元件（元件数据为随机生成）
            Job::MeasuredObj pushingMeasuredObj;
            pushingMeasuredObj.randomRectangle();           //随机生成元件的数据
            pushingMeasuredObj.setName(name);               //给元件赋元件名

            //3.将刚生成的元件加入列表
            this->m_measuredObjs.pushHead(pushingMeasuredObj);
        }
    }

}//End of namespace Job
