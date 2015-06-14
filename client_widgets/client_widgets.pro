#-------------------------------------------------
#
# Project created by QtCreator 2015-06-14T01:10:53
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client_widgets
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jsonreader.cpp \
    tcpclient.cpp \
    networkquerymanager.cpp \
    jsonparser.cpp \
    rootform.cpp

HEADERS  += mainwindow.h \
    jsonreader.h \
    tcpclient.h \
    networkquerymanager.h \
    jsonparser.h \
    rootform.h

FORMS    += mainwindow.ui \
    rootform.ui

RESOURCES += \
    resource.qrc
