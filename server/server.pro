TEMPLATE = app
TARGET = server

QT += core sql network
CONFIG += c++14 console

HEADERS += \
    jsonformat.h \
    requestsmanager.h \
    ../common/ParametrParser/parametrparser.h \
    api/api.h \
    api/apifactory.h \
    api/api_1_0.h \
    users/user.h \
    users/usercontrol.h \
    users/accesscontrol.h \
    db/sqlitemgr.h \
    db/sqlmgr.h \
    db/sqlorderby.h \
    db/sqlwhere.h \
    db/connectionmgr.h \
    tester/theme.h \
    tester/question.h \
    tester/lesson.h \
    tester/profession.h \
    tester/answer.h \
    network/networkmanager.h \
    network/tcpserver.h

SOURCES += \
    main.cpp \
    requestsmanager.cpp \
    jsonformat.cpp \
    ../common/ParametrParser/parametrparser.cpp \
    api/api.cpp \
    api/apifactory.cpp \
    api/api_1_0.cpp \
    users/user.cpp \
    users/usercontrol.cpp \
    users/accesscontrol.cpp \
    db/sqlitemgr.cpp \
    db/sqlmgr.cpp \
    db/sqlwhere.cpp \
    db/sqlorderby.cpp \
    db/connectionmgr.cpp \
    tester/lesson.cpp \
    tester/profession.cpp \
    tester/question.cpp \
    tester/answer.cpp \
    tester/theme.cpp \
    network/networkmanager.cpp \
    network/tcpserver.cpp
