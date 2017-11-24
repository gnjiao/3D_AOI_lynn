#include "appsetting.h"



void App::AppSetting::load(const QString &path)
{
    QString defaultTheme = "Black";
    QString defaultLang = "CN";
    QString defaultLaneMode = "Simulator";
    QString defaultMachineType = "SPI";
    QString defaultCompanyName = "SCIJET";
    QString defaultJobFolderPath = "./Inspection/";

    QSettings configFile(path, QSettings::IniFormat);

    if(!QFile::exists(path))        //若没有配置文件
    {
        //若路径不存在, 那么重新创建一个配置文件, 参数使用默认值
        std::cout << "没有配置文件, 写入默认值"<< std::endl;
        configFile.setValue("Theme", defaultTheme);
        configFile.setValue("Lang", defaultLang);
        configFile.setValue("LaneMode",defaultLaneMode);
        configFile.setValue("MachineType",defaultMachineType);
        configFile.setValue("CompanyName",defaultCompanyName);
        configFile.setValue("JobFolderPath",defaultJobFolderPath);

        this->m_lang = Lang::CN;
        this->m_laneMode = LaneMode::Simulator;
        this->m_machineType = MachineType::SPI;
        this->m_companyName = defaultCompanyName.toStdString();
        this->m_jobFolderPath = defaultJobFolderPath.toStdString();

        //读取生成的配置文件
        std::cout << "重新读取"<< std::endl;
        this->load(path);
        return;
    }
    else                            //若有配置文件
    {
        //1.读取Theme, 如果不正确的话就写入默认值
        QString theme =  configFile.value("Theme").toString();
        if( theme == "Black" ) {
            this->m_theme = Theme::Black;
        }
        else if (theme == "White") {
            this->m_theme = Theme::White;
        }
        else {
            std::cout << "读取Theme失败,设置为默认值Black"<< std::endl;
            configFile.setValue("Theme", defaultTheme);
            this->m_theme = Theme::Black;
        }

        //2.读取Lang,如果不正确的话就写入默认值
        QString lang =  configFile.value("Lang").toString();
        if(lang == "CN") {
            this->m_lang = Lang::CN;
        }
        else if (lang == "EN") {
            this->m_lang = Lang::EN;
        }
        else
        {
            std::cout << "读取Lang失败,默认设置为CN"<< std::endl;
            configFile.setValue("Lang", defaultLang);
            this->m_lang = Lang::CN;
        }

        //3.读取LaneMode，如果不正确就写如默认值
        QString laneMode =  configFile.value("LaneMode").toString();
        if(laneMode == "Simulator") {
            this->m_laneMode = LaneMode::Simulator;
        }
        else if (laneMode == "DualLane") {
            this->m_laneMode = LaneMode::DualLane;
        }
        else if (laneMode == "SingleLane") {
            this->m_laneMode = LaneMode::SingleLane;
        }
        else {
            std::cout << "读取LaneMode失败,默认设置为Simulator"<< std::endl;
            configFile.setValue("LaneMode", defaultLang);
            this->m_laneMode = LaneMode::Simulator;
        }

        //4.读取MachineType,如果不正确就写入默认值
        QString machineType = configFile.value("MachineType").toString();
        if (machineType == "SPI") {
            this->m_machineType = MachineType::SPI;
        }
        else if (machineType == "AOI3D") {
            this->m_machineType = MachineType::AOI3D;
        }
        else {
            std::cout << "读取MachinType失败,默认设置为SPI"<< std::endl;
            configFile.setValue("MachineType", defaultMachineType);
            this->m_machineType = MachineType::SPI;
        }

        //5.读取CompanyName,若不存在设置为默认值
        QString companyName = configFile.value("Company").toString();
        if (companyName == "\0" ) {
            this->m_companyName = defaultCompanyName.toStdString();
        }
        else {
            this->m_companyName = companyName.toStdString();
        }

        //6.读取JobFolderPath
        QString jobFolderPath = configFile.value("JobFolderPath").toString();
        std::fstream fFile;
        fFile.open(jobFolderPath.toStdString(),std::ios::in);
        if(!fFile)
        {
            std::cout << "存放程式路径不存在，使用默认路径";
            this->m_jobFolderPath = defaultJobFolderPath.toStdString();
        }
         else
        {
            this->m_companyName = jobFolderPath.toStdString();
        }

    }
}
