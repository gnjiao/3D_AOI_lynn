#include "capturesetting.h"



void App::CaptureSetting::load(const QString &path)
{
    try
    {
        if(!QFile::exists(path))
        {
            //假如路径不存在的话, 直接中止启动，退出软件
            THROW_EXCEPTION("没有标定文件，直接退出!");
        }
        else
        {
            //文件路径存在, 没有问题
            QSettings configFile(path, QSettings::IniFormat);

            //读取图像的宽度
            int width =  configFile.value("ImgWidth").toInt();
            if( (width < 3072) && (width > 4096) )
            {
                THROW_EXCEPTION("读取ImgWidth失败!");
            }
            else
            {
                this->m_imgWidth = width;
            }

            //读取图像的高度
            int height =  configFile.value("ImgHeight").toInt();
            if( (height < 3072) && (height > 4096) )
            {
                THROW_EXCEPTION("读取ImgHeight失败!");
            }
            else
            {
                this->m_imgHeight = height;
            }
        }
    }
    catch(const SDK::CustomException& ex)
    {
        std::cout << ex.what()<< std::endl;
        std::cout << "检测功能不可用， 请重新标定！"<< std::endl;
    }
}
