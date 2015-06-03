#pragma once

#include <QString>
#include <QDebug>

class Answer
{
	QString _value;
	bool    _valid = false;
public:
	Answer(){};
	Answer(const QString &value, const bool valid);

	QString getValue()const;
	bool isValid()const;

	void setValue(const QString &value);
	void setValid(const bool valid);

    void print()const;
};

namespace Table
{
	namespace Answers
	{
		const QString TABLE_NAME = "Answers";

		namespace Field
		{
			const QString ANSWER_ID = "answer_id";
			const QString TEXT = "text";
			const QString QUESTION_ID = "question_id";
			const QString VALID = "valid";
		}
	}  
}