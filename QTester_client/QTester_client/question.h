#pragma once

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
	bool    isCaseSensitivity() const;
	bool    isStripSpaces() const;
	bool    isMarkAsError() const;
	bool    isMarkAsDontKnow() const;

	void    setId(const QString &id);
	void    setText(const QString &text);
	void    setType(const QString &type);
	void    setTime(const QTime &time);
	void    setCaseSensitivity(const bool caseSensitivity);
	void    setStripSpaces(const bool stripSpace);
	void    setMarkAsError(const bool markAsError);
	void    setMarkAsDontKnow(const bool markAsDontKnow);
};

