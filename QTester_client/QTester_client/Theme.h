#pragma once

#include <QString>
#include <QVector>
#include "Question.h"

class Theme
{
private:
	QString _title;
	int		_difficulty = 0;
	QVector<Question> _questions;  

public:
	Theme(){};
	Theme(const QString &title);

	QString getTitle() const;
	int		getDifficulty() const;
	QVector<Question> getQuestions() const;

	void setTitle(const QString &title);
	void setDifficulty(const int &difficulty);
	void pushQuestion(const Question &question);
	void pushQuestion(const QString &text, const QString &type);
	void pushQuestion(const QString &text, const QString &type, const QVector<Answer> &answers);
	
	//QVector<Question> Ќбрать_себе_проблем();
};

