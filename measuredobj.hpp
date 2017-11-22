#ifndef MEASUREDOBJ_H
#define MEASUREDOBJ_H

#include <string>
#include <iostream>
#include <random>

#include "rectangle.h"

/*
*  @brief   生成一个精度为0.01的随机数
*  @param   lowerLimit为随机数的下限
*           upperLimit为随机数的上限
*  @return  指定范围内的有效精度为0.01的随机数
*/
#define RANDOM_NUM(lowerLimit,upperLimit)\
((rand()%(int)((upperLimit - lowerLimit)*100)+lowerLimit)/100)

namespace Job {

    /**
     *  @brief  该类表示一个检测过的元件。(具有双向链表中元素的特性，可以通过成员指针变量记
     *          录上一个元件和下一个元件,若指向nullptr则表示为没有上一个/下一个元件。)
     *  @author lynn
     *  @version 1.00 2017-11-20 lynn
     *                note:create it
     */
    class MeasuredObj
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor
        /*
        *  @brief   只是初始化两个成员变量指针为空指针
        *  @param   N/A
        *  @return  N/A
        */
        MeasuredObj();

        /*
        *  @brief   指定前一个和后一个元件
        *  @param   preMeasureObj是指向前一个元件的指针
        *           nextMeasureObj是指向后一个元件的指针
        *  @return  N/A
        */
        MeasuredObj(Job::MeasuredObj* pPreMeasureObj,
                    Job::MeasuredObj* pNextMeasureObj);

        ~MeasuredObj();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.访存函数
        std::string getName() { return this->m_name; }
        void setName(std::string name) { this->m_name = name; }

        SDK::Rectangle getBody() { return this->m_body; }
        void setBody(SDK::Rectangle body) { this->m_body = body; }

        Job::MeasuredObj* getPPreMeasureObj() {return this->m_pPreMeasuredObj;}
        void setPPreMeasureObj(Job::MeasuredObj *pPreMeasuredObj)
        {
            this->m_pPreMeasuredObj = pPreMeasuredObj;
        }

        Job::MeasuredObj* getPNextMeasuredObj(){return this->m_pNextMeasuredObj;}
        void setPNextMeasuredObj(Job::MeasuredObj *pNextMeasuredObj)
        {
            this->m_pNextMeasuredObj = pNextMeasuredObj;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.成员函数
        void randomMeasuredObj();
    private:

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4.成员变量
        std::string m_name;
        SDK::Rectangle m_body;
        Job::MeasuredObj* m_pPreMeasuredObj;
        Job::MeasuredObj* m_pNextMeasuredObj;
    };

}//End of namespace Job

#endif // MEASUREDOBJ_H
