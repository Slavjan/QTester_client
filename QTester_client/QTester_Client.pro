QT       += core gui widgets sql xml network

TARGET = QTester_Client
TEMPLATE = app

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
    QTester_client/SQLiteMgr.h \
    QTester_client/SQLMgr.h \
    QTester_client/stdHeaders.h \
    QTester_client/Tester.h \
    QTester_client/TestGenerator.h \
    QTester_client/db/mngrconnection.h \
    QTester_client/db/mngrquerys.h

SOURCES += \
    QTester_client/main.cpp \
    QTester_client/SQLiteMgr.cpp \
    QTester_client/SQLMgr.cpp \
    QTester_client/stdHeaders.cpp \
    QTester_client/Tester.cpp \
    QTester_client/TestGenerator.cpp \
    QTester_client/db/mngrconnection.cpp \
    QTester_client/db/mngrquerys.cpp

#FORMS += \


#OTHER_FILES += \
#    ToDo.md \
#    ChangeLog.md

#RESOURCES += \
#    resource.qrc

#TRANSLATIONS += \


#DISTFILES += \
#    db
