#ifndef MEASUREDOBJLIST_H
#define MEASUREDOBJLIST_H

#include "measuredobj.hpp"

namespace Job
{
    class MeasuredObjList
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor
        MeasuredObjList();
        MeasuredObjList(MeasuredObj headMeasuredObj);
        ~MeasuredObjList();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.访存函数
        int getSize() { return this->m_size; }
        MeasuredObj * getHeadMeasuredObj() { return this->m_pHeadMeasuredObj; }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.成员函数
        void pushHead(MeasuredObj newMeasuredObj);
        void pushTail(MeasuredObj newMeasuredObj);
        void pullHead();
        void pullTail();
        void print();
    private:

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4.成员变量
        int m_size;                             //链表元素个数
        MeasuredObj * m_pHeadMeasuredObj;       //链表首元素地址
    };

}//End of namespace Job


#endif // MEASUREDOBJLIST_H
