#include "Answer.h"


Answer::Answer(const QString &value, const bool valid)
{
	if (!value.isEmpty())
	{
		_value = value;
		_valid = valid;
	}
}

QString Answer::getValue() const
{
	return _value;
}

bool Answer::isValid() const
{
	return _valid;
}

void Answer::setValue(const QString &value)
{
	_value = value;
}

void Answer::setValid(const bool valid)
{
	_valid = valid;
}