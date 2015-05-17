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
		//		  S	Q L	I T	E
#define SQLITE	0x53514c495445
#define MYSQL	0x4d5953514c
#define MSSQL	0x4d5353514c

typedef QMap<QString, bool> Answer;
typedef QMap<QString, Answer> Question;

class TestGenerator
{
private:
	SQLMgr *Qbase;
	Question test;
public:
	TestGenerator(const int &sqlServType,
				  const QString &dbHost,
				  const QString &dbPath,
				  const QString &dbUser,
				  const QString &dbPass);
	~TestGenerator();

	bool generateTest(const int questionCount);
	Question getTest();
};
#endif