#include "TestGenerator.h"


TestGenerator::TestGenerator()
{
}


TestGenerator::~TestGenerator()
{
}

Question TestGenerator::generateTest(const SQLMgr &base, const int questionCount)
{
	QString tName("Questions"),
			where("ORDER BY RANDOM()");

	QStringList qFields("fields"), 
				qValue,
				
				aFields,
				aValies;

	QSqlQuery qry;
	QSqlRecord rec;
	bool next = true;
				//request for questions
	qry = base.select(tName, qFields, where, 2);
	rec = qry.record();
	while (next)
	{
		qValue.push_back(qry.value(rec.indexOf(qFields.at(0))).toString());	//recording to var 
		next = qry.next();
	}


	Question test; //\todo TODO: the gag
	return test;
}
