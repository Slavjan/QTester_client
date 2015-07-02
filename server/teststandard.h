#pragma once
#ifndef TESTSTANDARD_H
#define TESTSTANDARD_H

#include <QString>
#include <QVector>
#include <QLocale>
#include "profession.h"  

typedef QMap<QString, QVector<QString>> S_VS;// TODO: назвать по нормальному

class TestStandard
{
private:          //TODO: ДОПИСАТЬ КЛАСС
    QString _id;
    QString _name;
    QString _title;
    QString _professionId;
    S_VS _lessons_themes_ids;                
    int _questionsCount;

    void selectStandardFromBase(const SQLMgr &sqlManager);

public:
    TestStandard();
    TestStandard( const QString &id, const QString &name );

    QString getId()const;
    QString getName()const;
    QString getTitle()const;
    int getQuestionsCount()const;
    S_VS getLessons_Themes_ids()const;
    QStringList StandardNames;

    void setId( const QString &id );
    void setName( const QString &name );
    void setTitle( const QString &title );
    void setQuestionsCount( const int questions );
    void pushLessons_Themes_ids( const S_VS &lessons_themes_ids );
    void pushName( const QString &name );
};

namespace Tables
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
            const QString RANGES = "randes";
        }                 
    }                     
}                         
#endif