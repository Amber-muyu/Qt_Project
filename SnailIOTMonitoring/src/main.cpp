#include "ui/mainwindow.h"

#include <QApplication>
#include "database/datamanager.h"
#include "database/usermanager.h"
#include "database/devicemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DataManager& dbManager = DataManager::instance();
    dbManager.open();  // 使用默认数据库路径
    dbManager.init();

    UserManager::instance();
    DeviceManager::instance();

    MainWindow w;
    w.show();
    return a.exec();
}
