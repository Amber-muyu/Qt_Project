QT       += core gui sql charts serialport
QT       += xml qml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/add/admindeviceinfoadd.cpp \
    src/add/adminruleadd.cpp \
    src/chart/realtimechart.cpp \
    src/controller/admindataanalysiscontroller.cpp \
    src/controller/alarmadmincontroller.cpp \
    src/controller/alarmusercontroller.cpp \
    src/controller/dataadmincontroller.cpp \
    src/controller/datausercontroller.cpp \
    src/controller/deviceadmincontroller.cpp \
    src/add/adminuserinfoadd.cpp \
    src/base/baseframe.cpp \
    src/controller/admincontroller.cpp \
    src/controller/deviceusercontroller.cpp \
    src/controller/usercontroller.cpp \
    src/controller/userdataanalysiscontroller.cpp \
    src/database/alarmrecordmanager.cpp \
    src/database/alarmrulemanager.cpp \
    src/database/databasemanager.cpp \
    src/database/datamanager.cpp \
    src/database/devicemanager.cpp \
    src/database/usermanager.cpp \
    src/modify/admindeviceinfomodify.cpp \
    src/modify/adminrulemodify.cpp \
    src/modify/adminuserinfomodify.cpp \
    src/modify/passwordmodify.cpp \
    src/modify/usermodify.cpp \
    src/serial/serialport.cpp \
    src/ui/homewindow.cpp \
    src/ui/loginwindow.cpp \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/registerwindow.cpp \
    src/ui/resetpasswdwindow.cpp \
    src/ui/statusbar.cpp \
    src/ui/titlebar.cpp

HEADERS += \
    src/add/admindeviceinfoadd.h \
    src/add/adminruleadd.h \
    src/chart/realtimechart.h \
    src/controller/admindataanalysiscontroller.h \
    src/controller/alarmadmincontroller.h \
    src/controller/alarmusercontroller.h \
    src/controller/dataadmincontroller.h \
    src/controller/datausercontroller.h \
    src/controller/deviceadmincontroller.h \
    src/add/adminuserinfoadd.h \
    src/base/baseframe.h \
    src/controller/admincontroller.h \
    src/controller/deviceusercontroller.h \
    src/controller/usercontroller.h \
    src/controller/userdataanalysiscontroller.h \
    src/database/alarmrecordmanager.h \
    src/database/alarmrulemanager.h \
    src/database/databasemanager.h \
    src/database/datamanager.h \
    src/database/devicemanager.h \
    src/database/usermanager.h \
    src/modify/admindeviceinfomodify.h \
    src/modify/adminrulemodify.h \
    src/modify/adminuserinfomodify.h \
    src/modify/passwordmodify.h \
    src/modify/usermodify.h \
    src/serial/serialport.h \
    src/ui/homewindow.h \
    src/ui/loginwindow.h \
    src/ui/mainwindow.h \
    src/ui/registerwindow.h \
    src/ui/resetpasswdwindow.h \
    src/ui/statusbar.h \
    src/ui/titlebar.h \
    src/utils/utils.h \

FORMS += \
    src/add/admindeviceinfoadd.ui \
    src/add/adminruleadd.ui \
    src/chart/realtimechart.ui \
    src/controller/admindataanalysiscontroller.ui \
    src/controller/alarmadmincontroller.ui \
    src/controller/alarmusercontroller.ui \
    src/controller/dataadmincontroller.ui \
    src/controller/datausercontroller.ui \
    src/controller/deviceadmincontroller.ui \
    src/add/adminuserinfoadd.ui \
    src/controller/admincontroller.ui \
    src/controller/deviceusercontroller.ui \
    src/controller/usercontroller.ui \
    src/controller/userdataanalysiscontroller.ui \
    src/modify/admindeviceinfomodify.ui \
    src/modify/adminrulemodify.ui \
    src/modify/adminuserinfomodify.ui \
    src/modify/passwordmodify.ui \
    src/modify/usermodify.ui \
    src/serial/serialport.ui \
    src/ui/homewindow.ui \
    src/ui/loginwindow.ui \
    src/ui/mainwindow.ui \
    src/ui/registerwindow.ui \
    src/ui/resetpasswdwindow.ui \
    src/ui/statusbar.ui \
    src/ui/titlebar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

QXLSX_ROOT = $$PWD/src/libs/QXlsx
include($$PWD/src/libs/QXlsx/QXlsx.pri)
INCLUDEPATH += $$PWD/src/libs/QXlsx
