#pragma once

#include <QString>
#include <QDebug>

class Answer
{
    QString _id;    
	QString _value;
	bool    _valid = false;
public:
	Answer(){};
	Answer(const QString &value, const bool valid);
    Answer( const QString &text, const bool valid, const QString &type );

    QString getId()const;
    QString getValue()const;
	bool isValid()const;

    void setId(const QString &id);
	void setValue(const QString &value);
	void setValid(const bool valid);

    void print()const;
};

namespace Tables
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