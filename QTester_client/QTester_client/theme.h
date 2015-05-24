#pragma once
#ifndef THEM_H
#define THEM_H

#include <QString>
#include <QVector>
#include "question.h"
#include "sqlwhere.h"
#include "sqlmgr.h"

class Theme {
private:
	QString _id;
	QString _title;
	int 	_difficulty = 0;
	QVector <Question> _questions;

public:
	Theme() { };
	Theme(const QString &title);

	QString getId()	const;
	QString getTitle() const;
	int getDifficulty() const;
	QVector <Question> getQuestions() const;

	void setId(const QString &id);
	void setTitle(const QString &title);
	void setDifficulty(const int &difficulty);
	void pushQuestion(const Question &question);
	void pushQuestion(const QString &text,
					  const QString &type);
	void pushQuestion(const QString &text,
					  const QString &type,
					  const QVector <Answer> &answers);

	bool selectFromDatabase( const SQLMgr &sqlManager,
							 const qint64 questionsCount,
							 const int answersCount );

	Question selectQuestion(const QSqlQuery &query) const;

	QVector<Answer> selectAnswers(const SQLMgr  &sqlManager,
						          const int      answersCount,
						          const QString &questionId) const;	
};

namespace Table
{
	namespace Theme
	{
		const QString TABLE_NAME = "Thems";

		namespace Fields
		{
			const QString THEM_ID = "them_id";
			const QString NAME = "name";
			const QString TITLE = "title";
			const QString LESSON_ID = "lesson_id";
		}
	}
} 
#endif

