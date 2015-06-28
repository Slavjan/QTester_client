TEMPLATE = app
TARGET = server

QT += core sql network
CONFIG += c++11 console

HEADERS += \
    networkmanager.h \
    answer.h \
    connectionmgr.h \
    jsonformat.h \
    lesson.h \
    profession.h \
    question.h \
    requestsmanager.h \
    sqlitemgr.h \
    sqlmgr.h \
    sqlorderby.h \
    sqlwhere.h \
    tester.h \
    testgenerator.h \
    teststandard.h \
    theme.h \
    user.h \
    usercontrol.h \
    tcpserver.h \
    ../common/ParametrParser/parametrparser.h

SOURCES += \
    main.cpp \
    networkmanager.cpp \
    requestsmanager.cpp \
    answer.cpp \
    connectionmgr.cpp \
    jsonformat.cpp \
    lesson.cpp \
    profession.cpp \
    question.cpp \
    sqlitemgr.cpp \
    sqlmgr.cpp \
    sqlorderby.cpp \
    sqlwhere.cpp \
    tcpserver.cpp \
    tester.cpp \
    testgenerator.cpp \
    teststandard.cpp \
    theme.cpp \
    user.cpp \
    usercontrol.cpp \
    ../common/ParametrParser/parametrparser.cpp
