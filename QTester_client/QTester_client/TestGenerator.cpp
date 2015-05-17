#include "TestGenerator.h"


TestGenerator::TestGenerator(const int &sqlServType, 
							 const QString &dbHost,
							 const QString &dbPath,
							 const QString &dbUser,
							 const QString &dbPass)
{
	switch(sqlServType)
	{
	case MSSQL:
	case MYSQL:
	case SQLITE:
		Qbase = new SQLiteMgr(dbHost, dbPath, dbUser, dbPass);
		break;
	default: break;
	}	  
}


TestGenerator::~TestGenerator()
{
	delete[] Qbase;
}

bool TestGenerator::generateTest(const int questionCount)
{
	QString tNameQst("Questions"),	// ЫЮЯ РСР АСДЕР УНКХБЮП: пюгахбюи мю лерндш ))
			s_qID("qID"),
			
			tNameAns("Anwers"),			
			s_ansID("ansID"),
			fValue("Value"),
			fCorrectly("Correctly"),
			
			_where("qID = '%1' AND Correctly = 'false'"),
			_where1("qID = %1 AND Correctly = 'true'");

	QStringList qfields({s_qID, fValue});
	QStringList	afields({s_ansID, fValue, fCorrectly});

	QSqlQuery qry0, qry1;
	QSqlRecord rec0, rec1;
	qint64 tSize = Qbase->size(tNameQst),
		   n_qID,
		   n_ansID;

	if (tSize >= questionCount)	 // пюгахбюи мю лерндш
	{
		for (auto i = 0; i < questionCount; i++)
		{									   // пюгахбюи мю лерндш
			n_qID = qrand() * tSize;
			qry0 = Qbase->select(tNameQst, 
								 qfields, 
								 _where.arg(QString::number(n_qID)));
			rec0 = qry0.record();
			QString qValue = qry0.value(rec0.indexOf(fValue)).toString();
			Answer n;
			qry1 = Qbase->select(tNameAns,
								 afields,
								 _where.arg(QString::number(n_qID)));
			rec1 = qry1.record();
			for (auto j = 0; j < 5; j++)
			{	//пюгдекъи мю лерндш 
				QString aValue(rec1.indexOf(fValue)), 
						aCorrectly(fCorrectly);
				n[aValue] = aCorrectly.toInt();
				qry1.next();
			}


			test[qValue] = n;
		}
		return true;
	}
	return false;
}

Question TestGenerator::getTest()
{
	return test;
}