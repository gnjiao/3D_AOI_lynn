#include "mainwindow.hpp"

App::MainWindow::MainWindow()
{

}


App::MainWindow::~MainWindow()
{
    //获取链表首个元素指针
    Job::MeasuredObj *pHead = this->m_inspectionData.board().measuredObjs().pHeadMeasuredObj();

    //循环释放整个链表中的元素空间
    while ( nullptr != pHead) {
        this->m_inspectionData.board().measuredObjs().pullHead();
        delete pHead;
        pHead = this->m_inspectionData.board().measuredObjs().pHeadMeasuredObj();
    }
}


void App::MainWindow::loadAppSetting(QString path)
{
    this->m_appSetting.load(path);
}


void App::MainWindow::loadCaptureSetting(QString path)
{
    try
    {
        this->m_captureSetting.load(path);
    }
    catch(const SDK::CustomException& ex)
    {
        //加上这一层的异常信息，将异常上抛
        THROW_EXCEPTION(ex.what());
    }
}


void App::MainWindow::loadJobFolder()
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1.判断程式路径是否存在，不存在则创建
    QDir dir(QString::fromStdString(this->m_appSetting.jobFolderPath()));
    if(!dir.exists())                   //判断程式路径是否存在
    {
        //判断程式目录是否创建成功
        if( !dir.mkpath(QString::fromStdString(this->m_appSetting.jobFolderPath())) )
        {
            THROW_EXCEPTION("程式路径不存在");
        }
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2.遍历程式目录，找出缀不为.xml的文件
    QStringList filters;
    filters << "*[^xml]";
    dir.setNameFilters(filters);        //设置寻找文件的过滤条件
    dir.setFilter(QDir::Files);
    QFileInfoList fileList = dir.entryInfoList();
    QFileInfo fileInfo;

    for (int i = 0; i < fileList.size(); ++i) {
        fileInfo = fileList.at(i);
        std::cout<< i << ":\t" << fileInfo.fileName().toStdString() <<std::endl;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //3.若无程式文件，创建默认程式并导出xml文件
    std::string xmlSuffix = ".xml";
    if(fileList.empty())//若没有程式，生成默认程式
    {
        std::string defaultJobName = "XiaoMi";
        this->createDefaultJob(this->m_appSetting.jobFolderPath() + defaultJobName);
        this->writeToXml( this->m_appSetting.jobFolderPath() +\
                          defaultJobName + xmlSuffix );
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //4.若有程式文件，加载用户选择的文件并导出xml文件
    else                                //若存在程式,用户选择加载的程式
    {
        std::cout << "请选择程式（输入序号即可）" << std::endl;

        int selectJobIdx = -1;          //用户选择的程式索引，初始化为-1，表示未选择

        while (true)
        {
            std::cin >> selectJobIdx;   //接收用户选择的程式索引

            if(std::cin && selectJobIdx < fileList.size() && selectJobIdx >= 0)
            {
                fileInfo = fileList.at(selectJobIdx);

                //加载用户选择的程式文件：
                loadInspectionData( this->m_appSetting.jobFolderPath() + \
                                    fileInfo.fileName().toStdString());

                //将程式数据导出为xml文件
                this->writeToXml( this->m_appSetting.jobFolderPath() +\
                                  fileInfo.fileName().toStdString() +\
                                  xmlSuffix );
                break;
            }
            else
            {
                std::cout << "请输入正确的程式索引号" << std::endl;

                //清空cin缓冲区：
                std::cin.clear();
                std::cin.ignore();
            }
        }   //end of while(true)
    }
}


void App::MainWindow::loadInspectionData(std::string path)
{
    SSDK::DB::SqliteDB sqlite(path);
    try
    {
        auto isOpened = sqlite.isOpened();
        if(isOpened)
        {
            //>>>----------------------------------------------------------------------------------------------------------
            //1.读取Job表
            //读取版本号
            std::string selectedString = "select version from Job";
            sqlite.prepare(selectedString);
            this->m_inspectionData.setVersion(sqlite.executeScalar<std::string>(selectedString));
            if(this->m_inspectionData.version() !="V1")
            {
                THROW_EXCEPTION("检测程式版本过高");
            }

            //读取最后修改时间
            selectedString = "select lastEditTime from Job";
            sqlite.prepare(selectedString);
            this->m_inspectionData.setLastEditingTime(sqlite.executeScalar<std::string>(selectedString));

            //>>>----------------------------------------------------------------------------------------------------------
            //2.读取Board表
            selectedString = "select * from Board";
            sqlite.prepare(selectedString);
            sqlite.begin();

            while(true)
            {
                sqlite.step();
                if (sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }

                this->m_inspectionData.board().setName(boost::get<std::string>(sqlite.columnValue(0)));
                this->m_inspectionData.board().setSizeX(boost::get<double>(sqlite.columnValue(1)));
                this->m_inspectionData.board().setSizeY(boost::get<double>(sqlite.columnValue(2)));
                this->m_inspectionData.board().setOriginalX(boost::get<double>(sqlite.columnValue(3)));
                this->m_inspectionData.board().setOriginalY(boost::get<double>(sqlite.columnValue(4)));
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //3.读取MeasuredObjs表
            selectedString = "select * from MeasuredObjs";
            sqlite.prepare(selectedString);
            sqlite.begin();

            Job::MeasuredObj *pQueryingObj;

            while(true)
            {
                sqlite.step();
                if (sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                pQueryingObj = new Job::MeasuredObj;
                pQueryingObj->setName(boost::get<std::string>(sqlite.columnValue(0)));
                pQueryingObj->body().setWidth(boost::get<double>(sqlite.columnValue(1)));
                pQueryingObj->body().setHeight(boost::get<double>(sqlite.columnValue(2)));
                pQueryingObj->body().setXPos(boost::get<double>(sqlite.columnValue(3)));
                pQueryingObj->body().setYPos(boost::get<double>(sqlite.columnValue(4)));
                this->m_inspectionData.board().measuredObjs().pushHead(pQueryingObj);
            }

            sqlite.reset();
            sqlite.close();
        } //end of if(isopen)
    } //end of try
    catch(const SDK::CustomException& ex)
    {
        std::cout << ex.what() << std::endl;
        if(sqlite.isOpened())
        {
            sqlite.reset();
            sqlite.close();
        }
    }
}


void App::MainWindow::createDefaultJob(std::string path)
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1.生成默认程式（数据为随机生成）

    //随机生成的数据的上下限
    double maxHeight = 150.00;
    double minHeight = 0.01;
    double maxWidth = 150.0;
    double minWidth = 0.01;
    double maxX = 100.00;
    double minX = 0.00;
    double maxY = 100.00;
    double minY = 0.00;

    srand(time(0));
    std::string defaultBoardName = "Mi";
    this->inspectionData().board().setName(defaultBoardName);
    this->inspectionData().board().setSizeX(RANDOM_NUM(minWidth,maxWidth));
    this->inspectionData().board().setSizeY(RANDOM_NUM(minHeight,maxHeight));
    this->inspectionData().board().setOriginalX(RANDOM_NUM(minX,maxX));
    this->inspectionData().board().setOriginalY(RANDOM_NUM(minY,maxY));

    time_t currentTime;
    time (&currentTime);
    this->inspectionData().setLastEditingTime(asctime(localtime (&currentTime)));

    this->inspectionData().setVersion("V1");
    char objName[10];
    char namePrefixArr[][5]={"chip","ic"};
    int chipCnt = 20;
    int icCnt = 30;
    Job::MeasuredObj* pPushingMeasuredObj;
    for ( int i = 1; i <= chipCnt + icCnt; ++i)
    {
        //生成元件名：
        if ( i <= icCnt ){
            std::sprintf(objName,"%s%02d",namePrefixArr[1],i);
        }
        else {
            std::sprintf(objName,"%s%02d",namePrefixArr[0],i - 30);
        }

        //生成要push到元件（元件数据为随机生成）
        pPushingMeasuredObj = new Job::MeasuredObj;
        pPushingMeasuredObj->body().setXPos(RANDOM_NUM(minX,maxX));
        pPushingMeasuredObj->body().setYPos(RANDOM_NUM(minY,maxY));
        pPushingMeasuredObj->body().setHeight(RANDOM_NUM(minHeight,maxHeight));
        pPushingMeasuredObj->body().setWidth(RANDOM_NUM(minWidth,maxWidth));

        pPushingMeasuredObj->setName(objName);  //给元件赋元件名

        //将刚生成的元件加入列表
        this->m_inspectionData.board().measuredObjs().pushHead(pPushingMeasuredObj);
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2.创建job表
    SSDK::DB::SqliteDB v2Sqlite;
    v2Sqlite.open(path);

    std::string sqlcreate = "create table Job ( version varchar(5), lastEditTime varchar(30) )";
    v2Sqlite.execute(sqlcreate);

    std::string sqlInsert = "insert into Job(version,lastEditTime) values(?,?)";
    v2Sqlite.execute(sqlInsert,this->m_inspectionData.version(), this->m_inspectionData.lastEditingTime());


    //>>>----------------------------------------------------------------------------------------------------------
    //3.创建board表
    //新建表
    sqlcreate = "create table Board (name varchar(20),sizeX REAL,sizeY REAL,originalX REAL,originalY REAL)";
    v2Sqlite.execute(sqlcreate);

    //插入数据
    sqlInsert = "insert into Board(name,sizeX,sizeY,originalX,originalY) values(?,?,?,?,?)";

    v2Sqlite.execute(sqlInsert, this->m_inspectionData.board().name(),\
                     this->m_inspectionData.board().sizeX(), \
                     this->m_inspectionData.board().sizeY(),\
                     this->m_inspectionData.board().originalX(),\
                     this->m_inspectionData.board().originalY());


    //>>>----------------------------------------------------------------------------------------------------------
    //4.创建MeasuredObjs表
    //新建表
    sqlcreate = "create table MeasuredObjs (name varchar(20),width REAL,height REAL,xPos REAL,yPos REAL)";
    v2Sqlite.execute(sqlcreate);

    //插入数据
    sqlInsert = "insert into MeasuredObjs(name,width,height,xPos,yPos) values(?,?,?,?,?)";
    Job::MeasuredObj* pListHead = this->m_inspectionData.board().measuredObjs().pHeadMeasuredObj();

    while (nullptr != pListHead)
    {
        v2Sqlite.execute(sqlInsert,pListHead->name(),\
                         pListHead->body().width(),\
                         pListHead->body().height(),\
                         pListHead->body().xPos(),\
                         pListHead->body().yPos());
        pListHead = pListHead->pNextMeasuredObj();
    }

    v2Sqlite.close();
}


void App::MainWindow::writeToXml(std::string path)
{
    this->m_inspectionData.writeToXml(path);
}
