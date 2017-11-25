/**
 *  @brief  自定义异常，传入错误信息，返回格式化的全套异常信息
 *  @author lynn
 *  @version 1.00 2017-11-21 lynn
 *                note:create it
 */

#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <exception>
#include <string>
#include <sstream>
#include <iostream>

#define THROW_EXCEPTION(exMsg)\
{\
    std::ostringstream message;\
    message << "File:"<<__FILE__<<"\n"\
            << "Line:"<<__LINE__<<"\n"\
            << "Func:"<<__FUNCTION__<<"\n"\
            << "Detail:"<<exMsg<<"\n";\
    std::string msg = message.str();\
    throw SDK::CustomException(msg);\
}


namespace SDK
{
    /**
     *  @brief 自定义异常类
     *
     *  @author lynn
     *  @version 1.00 2017-11-25 lynn
     *                note:create it
     */
    class CustomException : public std::exception
    {
    public:
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.constructor & destructor
        CustomException(std::string & message);

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.访存函数
        virtual const char * what() const _GLIBCXX_USE_NOEXCEPT override
        {
            return m_originalMsg.data();
        }

    private :
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.成员变量
        std::string m_originalMsg;          //异常信息
    };

}//End of namespace SDK

#endif // CUSTOMEXCEPTION_H
