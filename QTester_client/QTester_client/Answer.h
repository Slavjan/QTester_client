#pragma once

#include <QString>

class Answer
{
	QString _value;
	bool    _valid = false;
public:
	Answer(const QString &value, const bool valid);

	QString getValue()const;
	bool isValid()const;

	void setValue(const QString &value);
	void setValid(const bool valid);
};

