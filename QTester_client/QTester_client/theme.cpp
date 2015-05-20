#include "theme.h"


Theme::Theme(const QString &title)
{
	_title = title;
}

QString Theme::getTitle() const
{
	return _title;
}
int	Theme::getDifficulty() const
{
	return _difficulty;
}
QVector<Question> Theme::getQuestions() const
{
	return _questions;
}

void Theme::setTitle(const QString &title)
{
	_title = title;
}

void Theme::setDifficulty(const int &difficulty)
{
	_difficulty = difficulty;
}

void Theme::pushQuestion(const Question &question)
{
	_questions.push_back(question);
}

void Theme::pushQuestion(const QString &text, const QString &type)
{
	pushQuestion(Question(text, type));
}

void Theme::pushQuestion(const QString &text, const QString &type, const QVector<Answer> &answers)
{
    pushQuestion(Question(text, type, answers));
}

bool Theme::selectFromDatabase(const SQLMgr &sqlManager, const SqlWhere &where, const qint64 count)
{
    const QString tableName_questions("Questions");
    const QStringList selectedFields({"question_id", "text", "question_type", "" });

    if( where.isValid() ){
        QSqlQuery query = sqlManager.select(tableName_questions, selectedFields, where, count);

        while( query.next() ){
            /// \todo TODO type code here
			Question issue()
			//issue.setId();
			//pushQuestion();
        }

        return true;
    }
    return false;
}


