#ifndef MEASUREDOBJ_H
#define MEASUREDOBJ_H

#include<string>

#include "rectangle.h"

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
        *  @brief   只初始化两个成员变量指针为空指针
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
        MeasuredObj(Job::MeasuredObj* preMeasureObj,
                    Job::MeasuredObj* nextMeasureObj);

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.访存函数
        ~MeasuredObj();

    private:
        std::string name;
        SDK::Rectangle body;
        Job::MeasuredObj* pPreMeasuredObj;
        Job::MeasuredObj* pNextMeasuredObj;
    };

}

#endif // MEASUREDOBJ_H
