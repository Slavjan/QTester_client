#include "Question.h"


Question::Question(const QString &text, const QString &type, const QVector<Answer> &answers)
{
	_text = text;
	_type = type;
	_answers = answers;
}

Question::Question(const QString &text, const QString &type)
{
	_text = text;
	_type = type;
}

void Question::pushAnswer(const Answer &answer)
{
	_answers.push_back(answer);
}
void Question::pushAnswer(const QString &text, const bool valid)
{
	pushAnswer(Answer(text, valid));
}

QString Question::getText() const
{
	return _text;
}
QString Question::getType() const
{
	return _type;
}
QTime Question::getTime()const
{
	return _time;
}
bool Question::isCaseSensitivity() const
{
	return _caseSensitivity;
}
bool Question::isStripSpaces() const
{
	return _stripSpaces;
}
bool Question::isMarkAsError() const	  
{
	return _markAsError;
}

bool Question::isMarkAsDontKnow() const  
{
	return _markAsDontKnow;
}

void Question::setText(const QString &text)
{
	_text = text;
}

void Question::setType(const QString &type)
{
	_type = type;
}

void Question::setTime(const QTime &time)
{
	_time = time;
}

void Question::setCaseSensitivity(const bool caseSensitivity)
{
	_caseSensitivity = caseSensitivity;
}

void Question::setStripSpaces(const bool stripSpace)
{
	_stripSpaces = stripSpace;
}

void Question::setMarkAsError(const bool markAsError)
{
	_markAsError = markAsError;
}

void Question::setMarkAsDontKnow(const bool markAsDontKnow)
{
	_markAsDontKnow = markAsDontKnow;
}

void Question::stripSpaces()
{
	_text = _text.trimmed();	   
}					 