cmake_minimum_required(VERSION 3.2)
project(QTester_client)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core)
find_package(Qt5Sql)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    QTester_client/answer.cpp
    QTester_client/answer.h
    QTester_client/connectionmgr.cpp
    QTester_client/connectionmgr.h
    QTester_client/lesson.cpp
    QTester_client/lesson.h
    QTester_client/main.cpp
    QTester_client/question.cpp
    QTester_client/question.h
    QTester_client/sqlitemgr.cpp
    QTester_client/sqlitemgr.h
    QTester_client/sqlmgr.cpp
    QTester_client/sqlmgr.h
    QTester_client/sqlorderby.cpp
    QTester_client/sqlorderby.h
    QTester_client/sqlwhere.cpp
    QTester_client/sqlwhere.h
    QTester_client/tester.cpp
    QTester_client/tester.h
    QTester_client/testgenerator.cpp
    QTester_client/testgenerator.h
    QTester_client/theme.cpp
    QTester_client/theme.h)

#/add_executable(QTester_client ${SOURCE_FILES})

add_executable(QtFramework WIN32 SOURCE_FILES)
target_link_libraries(QtFramework WIN32 Qt5::Core Qt5::Sql)