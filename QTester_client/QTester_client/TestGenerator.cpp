#include "TestGenerator.h"


TestGenerator::TestGenerator()
{
}


TestGenerator::~TestGenerator()
{
}

Questions TestGenerator::collectTestVariant(const SQLMgr &base, int themeId/*TODO: make structure*/, const int questionCount)
{
	QString tName("Questions"),
	qwhere("theme_id=%1 ORDER BY RANDOM()"),
	awhere("question_id=%1 ORDER BY RANDOM()");

	QStringList qstFields({ "text", "question_id" }),
		        qstValue,
		        
		        ansFields({ "text", "valid" }),
		        ansValues;

	QVector<int> qIDs, ansValid;

	QSqlQuery qry;
	QSqlRecord rec;
	
	//request for questions
	qry = base.select(tName, qstFields, qwhere.arg(themeId), questionCount);
	rec = qry.record();

	
	qry.first();
	qstValue.push_back(qry.value(rec.indexOf(qstFields.first())).toString());	//recording to var
	qIDs.push_back(qry.value(rec.indexOf(qstFields.at(1))).toInt());
	while (qry.next())
	{
		qstValue.push_back(qry.value(rec.indexOf(qstFields.first())).toString());	//recording to var
		qIDs.push_back(qry.value(rec.indexOf(qstFields.at(1))).toInt()); 
	
	}
	//request for answers
	tName = "Answers";		 							  
	for (auto i = 0; i < qIDs.size(); i++)				  
	{
		qry = base.select(tName, ansFields, awhere.arg(qIDs.at(i)));
		rec = qry.record();

		qry.first();
		ansValues.push_back(qry.value(rec.indexOf(ansFields.first())).toString());
		ansValid.push_back(qry.value(rec.indexOf("valid")).toInt());
		while (qry.next())
		{
			ansValues.push_back(qry.value(rec.indexOf(ansFields.first())).toString());
			ansValid.push_back(qry.value(rec.indexOf("valid")).toInt());
		}			   
	}

	Questions test;
	for (auto i = 0; i < qIDs.size(); i++)
	{	
		Answers ans;
		for (auto j = 0; j < ansValues.size(); j++)
		{
			ans[ansValues.at(j)] = ansValid.at(j);
		}
		test[qstValue.at(i)] = ans;	  	
	} 	
	
	qDebug() << "[TestGenerator::collectTestVariant]";
	for (auto i = 0; i < qIDs.size(); i++)
	{											   		
		qDebug()  << "question " << test.keys().at(i);
		qDebug() << "answer " << test.values();									   
	}
		
	return test;
}


/*	TODO List
	* сделать выборку вопросов, тем самым сгенерировать вариант теста
	** выбераем вопросы пишем в StringList
	** выбераем ответы пишем в другой StringList
	** записываем в QMap 
			  ^
	Tester эти^ методы пользует, получает собственно вариант теста и выдает вопросы по требованию	
*/