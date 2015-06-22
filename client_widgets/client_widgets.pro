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
<<<<<<< HEAD
    tilelayout.cpp\
=======
    tilelayout.cpp
>>>>>>> 7d752a6e2ca132eb4560e44871073a1621247025

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
<<<<<<< HEAD
    tilelayout.h\
=======
    tilelayout.h
>>>>>>> 7d752a6e2ca132eb4560e44871073a1621247025

FORMS    += rootform.ui \
    rootwindow.ui \
    autorisationdialog.ui\

RESOURCES += \
    resource.qrc\
