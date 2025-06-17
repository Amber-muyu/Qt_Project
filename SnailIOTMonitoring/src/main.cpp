#include "ui/mainwindow.h"

#include <QApplication>
#include "database/datamanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DataManager& dbManager = DataManager::instance();
    dbManager.open();  // 使用默认数据库路径
    dbManager.init();

    return a.exec();
}
