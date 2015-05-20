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
    QTester_client/theme.h \
    QTester_client/sqlwhere.h \
    QTester_client/answer.h \
    QTester_client/connectionmgr.h \
    QTester_client/lesson.h \
    QTester_client/question.h \
    QTester_client/tester.h \
    QTester_client/testgenerator.h \
    QTester_client/sqlitemgr.h \
    QTester_client/sqlmgr.h

SOURCES += \
    QTester_client/theme.cpp \
    QTester_client/sqlwhere.cpp \
    QTester_client/main.cpp \
    QTester_client/answer.cpp \
    QTester_client/connectionmgr.cpp \
    QTester_client/lesson.cpp \
    QTester_client/question.cpp \
    QTester_client/tester.cpp \
    QTester_client/testgenerator.cpp \
    QTester_client/sqlitemgr.cpp \
    QTester_client/sqlmgr.cpp
