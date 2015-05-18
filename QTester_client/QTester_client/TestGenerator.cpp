#include "TestGenerator.h"


TestGenerator::TestGenerator()
{
}


TestGenerator::~TestGenerator()
{
}

Question TestGenerator::generateTest(const SQLMgr &base, const int questionCount)
{
    QString tName("tt"),
            where("0=0 ORDER BY RANDOM()");

    QStringList qFields("fUne"),
				qValue,
				
				aFields,
				aValies;

	QSqlQuery qry;
	QSqlRecord rec;
//	bool next = true;
//				//request for questions
//    qry = base.select(tName, qFields, where, 2);
//	rec = qry.record();
//	while (next)
//	{
//        qValue.push_back(qry.value(rec.indexOf(qFields.first())).toString());	//recording to var
//		next = qry.next();
//	}

    qry = base.select(tName, qFields, where, 4);
    while( qry.next() ){
        qDebug() << qry.record();
    }


	Question test; //\todo TODO: the gag
	return test;
}
