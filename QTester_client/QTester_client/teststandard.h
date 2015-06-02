#pragma once
#ifndef TESTSTANDARD_H
#define TESTSTANDARD_H

#include <QString>
#include <QVector>
#include <QLocale>
#include "profession.h"  

class TestStandard
{
private:          //TODO: ƒŒœ»—¿“‹  À¿——
    QString _id;
    QString _name;
    QString _title;
    QString _profession;
    int _questionsCount;
    int _range5;
    int _range4;
    int _range3;

    void selectStandardFromBase(const SQLMgr &sqlManager);

public:
    TestStandard();
    TestStandard( const SQLMgr &sqlManager, const QString &name );

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

namespace Table
{
    namespace TestStandard
    {
        const QString TABLE_NAME = "TestStandards";

        namespace Fields
        {
            const QString STANDARD_ID = "standard_id";
            const QString NAME = "name";
            const QString TITLE = "title";
            const QString QUESTIONS_COUNT = "questions_count";
            const QString RANGE5 = "rande5";
            const QString RANGE4 = "rande4";
            const QString RANGE3 = "rande3";
        }                 
    }                     
}                         
#endif