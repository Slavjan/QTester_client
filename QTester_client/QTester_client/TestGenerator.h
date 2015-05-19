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

typedef QMap<QString, bool> Answers;
typedef QMap<QString, Answers> Questions;

class TestGenerator
{
private:
public:
	TestGenerator();
	~TestGenerator();

	static Questions collectTestVariant(const SQLMgr &base, int themId/*TODO: make structure*/, const int questionCount);
	 
};
#endif