# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = server
#DESTDIR = ../Win32/Debug
QT += core sql network declarative widgets gui multimediawidgets
CONFIG += debug console
#DEFINES += WIN64 QT_DLL QT_NETWORK_LIB QT_SQL_LIB QT_WIDGETS_LIB QT_DECLARATIVE_LIB QT_MULTIMEDIAWIDGETS_LIB
#INCLUDEPATH += . \
#    ./GeneratedFiles/Debug
#DEPENDPATH += .
#MOC_DIR += ./GeneratedFiles/debug
#OBJECTS_DIR += debug
#UI_DIR += ./GeneratedFiles
#RCC_DIR += ./GeneratedFiles
#include(server.pri)


HEADERS += ./networkmanager.h \
    ./answer.h \
    ./connectionmgr.h \
    ./jsonformat.h \
    ./lesson.h \
    ./profession.h \
    ./question.h \
    ./requestsmanager.h \
    ./sqlitemgr.h \
    ./sqlmgr.h \
    ./sqlorderby.h \
    ./sqlwhere.h \
    ./tester.h \
    ./testgenerator.h \
    ./teststandard.h \
    ./theme.h \
    ./user.h \
    ./usercontrol.h \
    ./tcpserver.h
SOURCES += ./main.cpp \
    ./networkmanager.cpp \
    ./answer.cpp \
    ./connectionmgr.cpp \
    ./jsonformat.cpp \
    ./lesson.cpp \
    ./profession.cpp \
    ./question.cpp \
    ./sqlitemgr.cpp \
    ./sqlmgr.cpp \
    ./sqlorderby.cpp \
    ./sqlwhere.cpp \
    ./tcpserver.cpp \
    ./tester.cpp \
    ./testgenerator.cpp \
    ./teststandard.cpp \
    ./theme.cpp \
    ./user.cpp \
    ./usercontrol.cpp \
    ./requestsmanager.cpp
