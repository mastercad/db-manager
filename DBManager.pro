#-------------------------------------------------
#
# Project created by QtCreator 2020-01-09T19:07:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBManager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS    += -lGL
LIBS    += -L/usr/local/lib -L/usr/lib -lmysqlcppconn

INCLUDEPATH += -I/usr/include -I/usr/local/include
               -I/usr/local/include/cppconn

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    newconnectionwindow.cpp \
    textedit.cpp \
    mysqlconnection.cpp \
    sqliteconnection.cpp \
    connectionfactory.cpp \
    connectionwithlogindialog.cpp \
    connectionwithfiledialog.cpp \
    newconnectionwizard.cpp \
    connectionwizardintropage.cpp \
    connectionwizardmysqlpage.cpp \
    connectionwizardsqlitepage.cpp \
    connectionwizardfinalpage.cpp

HEADERS += \
    mainwindow.h \
    newconnectionwindow.h \
    textedit.h \
    mysqlconnection.h \
    sqliteconnection.h \
    connectionfactory.h \
    connectionwithlogindialog.h \
    connectionwithfiledialog.h \
    newconnectionwizard.h \
    connectionwizardintropage.h \
    connectionwizardmysqlpage.h \
    connectionwizardsqlitepage.h \
    connectionwizardfinalpage.h

FORMS += \
    mainwindow.ui \
    newconnectionwindow.ui \
    connectionwithlogindialog.ui \
    connectionwithfiledialog.ui

DISTFILES += \
    README.md \
    TODO.md

RESOURCES += \
    resources.qrc
