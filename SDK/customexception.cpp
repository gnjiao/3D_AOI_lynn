#include "customexception.hpp"


SDK::CustomException::CustomException(std::string &message)
{
    this->m_originalMsg = message;
}

SDK::CustomException::~CustomException()
{

}
