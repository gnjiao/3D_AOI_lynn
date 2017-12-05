#include "capturesetting.hpp"


App::CaptureSetting::CaptureSetting()
{

}


App::CaptureSetting::~CaptureSetting()
{

}


void App::CaptureSetting::load(const QString &path)
{
    try
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.假如路径不存在的话, 抛出异常
        if(!QFile::exists(path))
        {
            THROW_EXCEPTION("没有标定文件");
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.文件路径存在, 没有问题
        else
        {
            QSettings configFile(path, QSettings::IniFormat);

            //2.1读取图像的宽度,若数据异常则抛出异常
            int width =  configFile.value("ImgWidth").toInt();
            if( (width > 3072) && (width < 4096) )
            {
                this->m_imgWidth = width;
            }
            else
            {
                THROW_EXCEPTION("读取ImgWidth失败!");
            }

            //2.2读取图像的高度，若数据异常则抛出异常
            int height =  configFile.value("ImgHeight").toInt();
            if( (height > 3072) && (height < 4096) )
            {
                this->m_imgHeight = height;
            }
            else
            {
                THROW_EXCEPTION("读取ImgHeight失败!");
            }

            //2.3读取图像位数，若数据异常则抛出异常
            int imgBits =  configFile.value("ImgBits").toInt();
            if( imgBits == 8 )
            {
                this->m_imgBits = ImgBits::BIT_8;
            }
            else if ( imgBits == 16 )
            {
                this->m_imgBits = ImgBits::BIT_16;
            }
            else
            {
                THROW_EXCEPTION("读取ImgHeight失败!");
            }
        }   //end of if(!QFile::exists(path)) 的else语句
    }
    catch(const SDK::CustomException& ex)
    {
        //加上这一层的异常信息，异常上抛
        THROW_EXCEPTION(ex.what());
    }
}
