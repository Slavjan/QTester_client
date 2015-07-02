#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QTime>
#include <QVector>

#include "answer.h"

class Question
{
	QString _id;
	QString _text;
	QString _type;
	QTime	_time;
	bool    _caseSensitivity = false;
	bool    _stripSpaces = true;
	bool    _markAsError = false;
	bool    _markAsDontKnow = false;
	QVector<Answer> _answers;

	void stripSpaces();

public:
	Question(){};
	Question(const QString &text, const QString &type, const QVector<Answer> &answers);
	Question(const QString &text, const QString &type);

	void pushAnswer(const Answer &answer);
	void pushAnswer(const QString &text, const bool valid);

	QString getId() const;
	QString getText() const;
	QString getType() const;
	QTime	getTime() const;
	QVector<Answer> getAnswers() const;
	bool    isCaseSensitivity() const;
	bool    isStripSpaces() const;
	bool    isMarkAsError() const;
	bool    isMarkAsDontKnow() const;

	void    setId(const QString &id);
	void    setText(const QString &text);
	void    setType(const QString &type);
	void    setTime(const QTime &time);
	void 	setAnswers(const QVector<Answer> &answers);
	void    setCaseSensitivity(const bool caseSensitivity);
	void    setStripSpaces(const bool stripSpace);
	void    setMarkAsError(const bool markAsError);
	void    setMarkAsDontKnow(const bool markAsDontKnow);

    void print()const;
};

namespace Tables
{
	namespace Question
	{
		const QString TABLE_NAME = "Questions";

		namespace Field
		{
			const QString QUESTION_ID = "question_id";
			const QString RECOMENDED_TIME = "recomended_time";
			const QString TEXT = "text";
			const QString QUESTION_TYPE = "QUESTION_TYPE";
			const QString THEME_ID = "theme_id";
			const QString CASE_SENS = "caseSens";
			const QString STRIP_SPACE = "stripSpace";
		}
	}	 
}
#endif

