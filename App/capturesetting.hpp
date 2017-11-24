#ifndef CAPTURESETTING_H
#define CAPTURESETTING_H

#include <QSettings>
#include <QFile>

#include "./SDK/customexception.hpp"

namespace App
{

    class CaptureSetting
    {
    public:
        void load(const QString& path);
    private:
        int m_imgWidth;
        int m_imgHeight;
        int m_imgBits;
    };

}//End of namespace App

#endif // CAPTURESETTING_H
