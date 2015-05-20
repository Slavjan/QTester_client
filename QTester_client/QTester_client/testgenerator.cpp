#include "testgenerator.h" 

TestGenerator::TestGenerator()
{
}


TestGenerator::~TestGenerator()
{
}

Questions TestGenerator::collectTestVariant(const SQLMgr &base, int themeId/*TODO: make structure*/, const int questionCount)
{
	QString tName("Questions");
	SqlWhere questionWhere("theme_id=" + QString::number(themeId));
	

	QStringList questionFields({ "text", "question_id" }),
		        questionValue,
		        
		        ansFields({ "text", "valid" }),
		        ansValues;

	QVector<int> questionIds, ansValid;

	QSqlQuery qry;
	QSqlRecord rec;
	
	//request for questions
	qry = base.select(tName, questionFields, questionWhere, SqlOrderBy::RANDOM(), questionCount);
		//base.select(tName, qstFields, qwhere.arg(themeId), questionCount);
	rec = qry.record();

	
	qry.first();
	questionValue.push_back(qry.value(rec.indexOf(questionFields.first())).toString());	//recording to var
	questionIds.push_back(qry.value(rec.indexOf(questionFields.at(1))).toInt());
	while (qry.next())
	{
		questionValue.push_back(qry.value(rec.indexOf(questionFields.first())).toString());	//recording to var
		questionIds.push_back(qry.value(rec.indexOf(questionFields.at(1))).toInt());  	
	}
	//request for answers
	tName = "Answers";		 							  
	for (auto i = 0; i < questionIds.size(); i++)				  
	{
		SqlWhere answerWhere("question_id=" + QString::number(questionIds.at(i)));
		qry = base.select(tName, ansFields, answerWhere, SqlOrderBy::RANDOM(), questionCount);
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
	for (auto i = 0; i < questionIds.size(); i++)
	{	
		Answers ans;
		for (auto j = 0; j < ansValues.size(); j++)
		{
			ans[ansValues.at(j)] = ansValid.at(j);
		}
		test[questionValue.at(i)] = ans;
	} 	
	
	qDebug() << "[TestGenerator::collectTestVariant]";
	for (auto i = 0; i < questionIds.size(); i++)
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