#include "measuredobjlist.hpp"

using namespace Job;


MeasuredObjList::MeasuredObjList()
{
    this->m_size = 0;
    this->m_pHeadMeasuredObj = nullptr;
}


MeasuredObjList::MeasuredObjList(MeasuredObj headMeasuredObj)
{
    this->m_size = 1;
    this->m_pHeadMeasuredObj = new ( MeasuredObj );     //开辟内存

    if( nullptr != this->m_pHeadMeasuredObj )           //若内存开辟成功
    {
        //将数据存到新开辟的内存空间中
        *this->m_pHeadMeasuredObj = headMeasuredObj;

        //将指向上一个和下一个元件的指针都置为nullptr,表示不存在
        (*this->m_pHeadMeasuredObj).setPPreMeasureObj(nullptr);
        (*this->m_pHeadMeasuredObj).setPNextMeasuredObj(nullptr);

    }
}


MeasuredObjList::~MeasuredObjList()
{
//    MeasuredObj *pDeletingMeasuredObj = this->m_pHeadMeasuredObj;

    while(0 != this->m_size)                            //释放所有元素开辟的空间
    {
        this->pullHead();                               //释放链表首元素
    }
}


void MeasuredObjList::pushHead(MeasuredObj newMeasuredObj)      //TBC:优化measuredObj的构造函数减少代码行数
{
    this->m_size++;                                     //元素个数加一
    MeasuredObj *pOldHead = this->m_pHeadMeasuredObj;   //记录原来的第一个元件地址

    //将新的元素加入到链表
    this->m_pHeadMeasuredObj = new ( MeasuredObj );     //开辟存放新元素的内存空间
    if( nullptr != this->m_pHeadMeasuredObj )           //若内存开辟成功
    {
        *this->m_pHeadMeasuredObj = newMeasuredObj;
    }

    //将原来的首个元素的前一个元素指针指向新元素
    (*pOldHead).setPPreMeasureObj(this->m_pHeadMeasuredObj);

    //将新元素的后一个元素指针指向原来的首个元素
    (*this->m_pHeadMeasuredObj).setPNextMeasuredObj(pOldHead);

    //将新元素的前一个元素指针置为空,表示不存在
    (*this->m_pHeadMeasuredObj).setPPreMeasureObj(nullptr);
}

void MeasuredObjList::pushTail(MeasuredObj newMeasuredObj)
{
    this->m_size++;                                     //元素个数加一
    //获取原链表最后一个元素的指针
    MeasuredObj *pOldTail = this->m_pHeadMeasuredObj;
    while ( nullptr != (*pOldTail).getPNextMeasuredObj() )
    {
        pOldTail = (*pOldTail).getPNextMeasuredObj();
    }

    //将新的元素加入到链表
    MeasuredObj *pTailMeasuredObj = new ( MeasuredObj );//开辟存放新元素的内存空间
    if( nullptr != this->m_pHeadMeasuredObj )            //若内存开辟成功
    {
        *pTailMeasuredObj = newMeasuredObj;
    }

    //将原来的尾元素的后一个元素指针指向新元素
    (*pOldTail).setPNextMeasuredObj( pTailMeasuredObj );

    //将新元素的前一个元素指针指向原来的尾元素
    (*pTailMeasuredObj).setPPreMeasureObj(pOldTail);

    //将新元素的后一个元素指针置为空,表示不存在
    (*pTailMeasuredObj).setPNextMeasuredObj(nullptr);

}

void MeasuredObjList::pullHead()
{
    if (0 == this->m_size)                               //判断链表中是否存在元素
    {
        std::cout << "链表无元素" << std::endl;
        return;
    }

    this->m_size--;                                     //元素个数减一
    //记录新的首个元素指针
    MeasuredObj *pNewHead = (*this->m_pHeadMeasuredObj).getPNextMeasuredObj();

    delete this->m_pHeadMeasuredObj;                     //释放原首个元素的内存空间
    this->m_pHeadMeasuredObj = pNewHead;                 //更新链表的首个元素指针
    //将链表的新首个元素的前一个元素置为空，表示不存在
    if( nullptr != this->m_pHeadMeasuredObj )
        (*this->m_pHeadMeasuredObj).setPPreMeasureObj(nullptr);
}


void MeasuredObjList::pullTail()
{
    if (0 == this->m_size)                               //判断链表中是否存在元素
    {
        std::cout << "链表无元素" << std::endl;
        return;
    }

    this->m_size--;                                     //元素个数减一

    //获取原链表最后一个元素的指针
    MeasuredObj *pOldTail = this->m_pHeadMeasuredObj;
    while ( nullptr != (*pOldTail).getPNextMeasuredObj() )
    {
        pOldTail = (*pOldTail).getPNextMeasuredObj();
    }

    //记录新的链表尾元素的地址
    MeasuredObj *pNewTail = (*pOldTail).getPPreMeasureObj();
    delete pOldTail;                                    //释放原尾元素的内存空间
    pOldTail = nullptr;

    //将链表的新尾元素的后一个元素置为空，表示不存在
    if(nullptr != pNewTail)
        (*pNewTail).setPNextMeasuredObj(nullptr);
}

void MeasuredObjList::print()
{
    MeasuredObj *pPrintingMeasuredObj = this->m_pHeadMeasuredObj;

    for( int i = 0;i < this->m_size ; ++i )             //打印链表中的所有元素
    {
        std::cout << (*pPrintingMeasuredObj).getName() << ":" << std::endl
              << "\tx坐标\t:"
              << ((*pPrintingMeasuredObj).getBody()).getXPos() << std::endl
              << "\ty坐标\t:"
              << ((*pPrintingMeasuredObj).getBody()).getYPos() << std::endl
              << "\t宽度\t:"
              << ((*pPrintingMeasuredObj).getBody()).getWidth() << std::endl
              << "\t高度\t:"
              << ((*pPrintingMeasuredObj).getBody()).getHeight() << std::endl;

        //将待打印元素指针指向链表中的下一个元素
        pPrintingMeasuredObj = (*pPrintingMeasuredObj).getPNextMeasuredObj();
    }
}
