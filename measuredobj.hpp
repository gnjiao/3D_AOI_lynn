#ifndef MEASUREDOBJ_H
#define MEASUREDOBJ_H

#include <string>

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
        MeasuredObj(Job::MeasuredObj* preMeasureObj,
                    Job::MeasuredObj* nextMeasureObj);

        ~MeasuredObj();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.访存函数
        std::string& setName() { return this->m_name; }
        SDK::Rectangle& setBody() { return this->m_body; }
        Job::MeasuredObj*& setPreMeasureObj() {return this->m_pPreMeasuredObj;}
        Job::MeasuredObj*& setNextMeasuredObj(){return this->m_pNextMeasuredObj;}

    private:
        std::string m_name;
        SDK::Rectangle m_body;
        Job::MeasuredObj* m_pPreMeasuredObj;
        Job::MeasuredObj* m_pNextMeasuredObj;
    };

}

#endif // MEASUREDOBJ_H
