#include "customexception.h"


SDK::CustomException::CustomException(std::string &message)
{
    this->m_originalMsg = message;
}
