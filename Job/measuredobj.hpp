#ifndef MEASUREDOBJ_H
#define MEASUREDOBJ_H

#include <string>
#include <iostream>
#include <random>

#include "./SDK/rectangle.hpp"
#include "./SDK/datahelper.hpp"

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
        //1.set & get function

        /*
        *  @brief   获取元件名称
        *  @param   N/A
        *  @return  元件名陈
        */
        std::string name() { return this->m_name; }

        /*
        *  @brief   设置元件名陈
        *  @param   要设置的元件名称
        *  @return  N/A
        */
        void setName(std::string name) { this->m_name = name; }

        /*
        *  @brief   获取元件的基本信息
        *  @param   N/A
        *  @return  元件的基本信息
        */
        SDK::Rectangle& body() { return this->m_body; }

        /*
        *  @brief   获取上一个元件的指针
        *  @param   N/A
        *  @return  上一个元件的指针
        */
        Job::MeasuredObj* pPreMeasureObj() {return this->m_pPreMeasuredObj;}

        /*
        *  @brief   设置上一个元件的指针
        *  @param   要设置的上一个元件的指针
        *  @return  N/A
        */
        void setPPreMeasureObj(Job::MeasuredObj *pPreMeasuredObj)
        {
            this->m_pPreMeasuredObj = pPreMeasuredObj;
        }

        /*
        *  @brief   获取下一个元件的指针
        *  @param   N/A
        *  @return  下一个元件的指针
        */
        Job::MeasuredObj* pNextMeasuredObj(){return this->m_pNextMeasuredObj;}

        /*
        *  @brief   设置下一个元件的指针
        *  @param   要设置的下一个元件的指针
        *  @return  N/A
        */
        void setPNextMeasuredObj(Job::MeasuredObj *pNextMeasuredObj)
        {
            this->m_pNextMeasuredObj = pNextMeasuredObj;
        }

    private:

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.member variant
        std::string m_name;
        SDK::Rectangle m_body;
        Job::MeasuredObj* m_pPreMeasuredObj{nullptr};
        Job::MeasuredObj* m_pNextMeasuredObj{nullptr};
    };

}//End of namespace Job

#endif // MEASUREDOBJ_H
