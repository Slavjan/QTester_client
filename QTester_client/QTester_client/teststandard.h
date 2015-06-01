#pragma once
#ifndef TESTSTANDARD_H
#define TESTSTANDARD_H

#include <QString>
#include <QVector>
#include <QLocale>
#include "lesson.h"




class TestStandard
{
private:
    QString _id;
    QString _name;
    QString _title;
    int _questionsCount;
    int _range5;
    int _range4;
    int _range3;

public:
    TestStandard();

    QString getId()const;
    QString getName()const;
    QString getTitle()const;
    int getQuestionsCount()const;
    int getRang5()const;
    int getRang4()const;
    int getRang3()const;

    void setId( const QString &id );
    void setName( const QString &name );
    void setTitle( const QString &title );
    void setQuestionsCount( const int questions );
    void setRang5( const int range );
    void setRang4( const int range );
    void setRang3( const int range );
};
#endif