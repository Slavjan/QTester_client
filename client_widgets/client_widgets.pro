#-------------------------------------------------
#
# Project created by QtCreator 2015-06-14T01:10:53
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client_widgets
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
    jsonreader.cpp \
    tcpclient.cpp \
    networkquerymanager.cpp \
    jsonparser.cpp \
    rootform.cpp \
    rootwindow.cpp \
    autorisationdialog.cpp \
    button.cpp \
    radio.cpp \
    check.cpp \
    edit.cpp \
    tilelayout.cpp\
    apitestwindow.cpp

HEADERS  += jsonreader.h \
    tcpclient.h \
    networkquerymanager.h \
    jsonparser.h \
    rootform.h \
    rootwindow.h \
    autorisationdialog.h \
    button.h \
    radio.h \
    check.h \
    edit.h \
    tilelayout.h\
    apitestwindow.h

FORMS    += rootform.ui \
    rootwindow.ui \
    autorisationdialog.ui\
    apitestwindow.ui

RESOURCES += \
    resource.qrc\
