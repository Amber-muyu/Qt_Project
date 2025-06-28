#ifndef COMMONHELP_H
#define COMMONHELP_H

#include <QApplication>
#include <QDebug>
#include <QFile>

class CommonHelper {
public:
    static void loadStyleSheet(const QString &filePath) {
        QFile file(filePath);
        if(!file.open(QIODevice::ReadOnly)) {
            qDebug() << "loadStyleSheet failed!";
            return;
        }
        QTextStream in(&file);
        in.setCodec("UTF-8");
        qApp->setStyleSheet(in.readAll());
        file.close();
    }
};

#endif // COMMONHELP_H
