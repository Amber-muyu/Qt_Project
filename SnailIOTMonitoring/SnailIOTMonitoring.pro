QT       += core gui sql

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
    src/base/baseframe.cpp \
    src/database/datamanage.cpp \
    src/database/usermanage.cpp \
    src/ui/homewindow.cpp \
    src/ui/loginwindow.cpp \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/registerwindow.cpp \
    src/ui/resetpasswdwindow.cpp \
    src/ui/statusbar.cpp \
    src/ui/titlebar.cpp

HEADERS += \
    src/base/baseframe.h \
    src/database/datamanage.h \
    src/database/usermanage.h \
    src/ui/homewindow.h \
    src/ui/loginwindow.h \
    src/ui/mainwindow.h \
    src/ui/registerwindow.h \
    src/ui/resetpasswdwindow.h \
    src/ui/statusbar.h \
    src/ui/titlebar.h \
    src/utils/utils.h \

FORMS += \
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
