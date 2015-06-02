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
    QVector<QString> LessIds;
    QVector<QString> ThemsIds;
    int questionsCount;
    int answersCount;
};


class TestGenerator
{
private:
public:
	TestGenerator();

    static Questions collectTestVariant( const SQLMgr &base,
                                         const Professtion &prof,
                                         const ParamsForCollection &params );
	 
};
#endif