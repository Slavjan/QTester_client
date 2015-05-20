#ifndef TESTER_H
#define TESTER_H

#include <QString>
#include "connectionmgr.h"
#include "sqlmgr.h"
#include "testgenerator.h"

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