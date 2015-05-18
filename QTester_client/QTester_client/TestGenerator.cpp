#include "TestGenerator.h"


TestGenerator::TestGenerator(const SQLMgr *base)
{
	*_base = *base;
}


TestGenerator::~TestGenerator()
{
	delete[] _base;
}

bool TestGenerator::generateTest(const int questionCount)
{
	QString tName("Questions"),
			where("ORDER BY RANDOM()");

	QStringList qfields("fields"), 
				value;

	QSqlQuery qry;
	QSqlRecord rec;
	bool next = true;
	
	qry = _base->select(tName, qfields, where);
	rec = qry.record();
	while (next)
	{
		value.push_back(qry.value(rec.indexOf(qfields.at(0))).toString());
		next = qry.next();
	}
	
	return false;
}

Question TestGenerator::getTest()
{
	return test;
}