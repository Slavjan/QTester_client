#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

#include <QTime>
#include <QMap>
#include <QString>
#include <QStringList> 
#include "profession.h"

#ifdef _DEBUG
#include <QDebug>
#endif

typedef QMap<QString, bool> Answers;
typedef QMap<QString, Answers> Questions;

struct ParamsForCollection
{
    QString professionId;
    QString lessIds;
    QStringList themsIds;            // less.getThemes().at(i)  less.getLess
    int questionsCount;
    int answersCount;
};                         

class TestGenerator
{
private:
public:
    static Profession collectTestVariant( const SQLMgr &db,
                                          const ParamsForCollection &params );
};
#endif