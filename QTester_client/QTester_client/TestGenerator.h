#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

#include "SQLiteMgr.h"

#include <QTime>
#include <QMap>
#include <QString>
#include <QStringList>

#ifdef _DEBUG
#include <QDebug>
#endif

typedef QMap<QString, bool> Answer;
typedef QMap<QString, Answer> Question;

class TestGenerator
{
private:
public:
	TestGenerator();
	~TestGenerator();

	static Question generateTest(const SQLMgr &base, const int questionCount);
	 
};
#endif