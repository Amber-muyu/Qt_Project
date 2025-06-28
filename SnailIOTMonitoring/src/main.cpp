#include "ui/mainwindow.h"

#include <QApplication>
#include "database/databasemanager.h"
#include "database/usermanager.h"
#include "database/devicemanager.h"
#include "database/datamanager.h"
#include "database/alarmrecordmanager.h"
#include "database/alarmrulemanager.h"
#include "database/systemlogsmanager.h"
#include "utils/commonhelp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager& dbManager = DatabaseManager::instance();
    dbManager.open();  // 使用默认数据库路径
    dbManager.init();

    UserManager::instance();
    DeviceManager::instance();
    DataManager::instance();
    AlarmRecordManager::instance();
    AlarmRuleManager::instance();
    SystemLogsManager::instance();

    CommonHelper::loadStyleSheet(":/resources/btn.css");

    MainWindow w;
    w.show();
    return a.exec();
}
