#ifndef TESTER_H
#define TESTER_H

#include <QString>
#include "ConnectionMgr.h"
#include "SQLMgr.h"
#include "TestGenerator.h"

#include <QMap>
#include <QString>
#include <QStringList>
#include <QSqlQuery>

#ifdef _DEBUG
#include <QDebug>
#endif

class Tester
{
private:
	
public:
	Tester();
	~Tester();

	bool generateTest(const int questiuonCount); // TODO: them, subject, in place the questionCount - a Test Standard in mean ENT, NOK
	void RunTest();
};
#endif