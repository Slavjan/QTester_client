QT       += core gui widgets sql xml network

TARGET = QTester_Client
TEMPLATE = app

CONFIG += console
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

VERSION = 0.0.0.0
#Last digit:
# 0 - Pre-Alpha
# 1 - Alpha
# 2 - Beta
# 3 - Release Candidate
# 4 - Release

RC_ICONS = images/QTester_Icon.ico
QMAKE_TARGET_COMPANY = Slavjan
QMAKE_TARGET_PRODUCT = QTester
QMAKE_TARGET_DESCRIPTION = Tester
QMAKE_TARGET_COPYRIGHT = Slavjan

HEADERS += \
    QTester_client/Tester.h \
    QTester_client/TestGenerator.h \
    QTester_client/SQLiteMgr.h \
    QTester_client/ConnectionMgr.h \
    QTester_client/SQLMgr.h

SOURCES += \
    QTester_client/main.cpp \
    QTester_client/Tester.cpp \
    QTester_client/TestGenerator.cpp \
    QTester_client/SQLiteMgr.cpp \
    QTester_client/ConnectionMgr.cpp \
    QTester_client/SQLMgr.cpp

#FORMS += \


#OTHER_FILES += \
#    ToDo.md \
#    ChangeLog.md

#RESOURCES += \
#    resource.qrc

#TRANSLATIONS += \


#DISTFILES += \
#    db

DISTFILES += \
    QTester_client/QTester_client.vcxproj.filters \
    QTester_client/QTester_client.vcxproj
