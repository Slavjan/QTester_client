#include "theme.h"


Theme::Theme(const QString &title)
{
    _title = title;
}

QString Theme::getId() const
{
	return _id;
}			  
QString Theme::getTitle() const
{
    return _title;
}
int	Theme::getDifficulty() const
{
    return _difficulty;
}
QString Theme::getLessonId() const
{
    return _lessonId;
}
QVector<Question> Theme::getQuestions() const
{
    return _questions;
}

void Theme::setId(const QString &id)
{
	_id = id;
}	
void Theme::setTitle(const QString &title)
{
    _title = title;
}		 
void Theme::setDifficulty(const int &difficulty)
{
    _difficulty = difficulty;
}		 
void Theme::setLessonId( const QString &lessonId )
{
    _lessonId = lessonId;
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

bool Theme::selectFromDatabase(const SQLMgr &sqlManager, const qint64 questionsCount, const int answersCount)
{
    const QString tableName_questions("Questions");
    const QStringList selectedFields({"question_id", "text", "question_type",
                                      "recomended_time", "caseSens", "stripSpace" });

	SqlWhere _where("theme_id = '" + _id + "'");

    if( _where.isValid() )
	{
        QSqlQuery query = sqlManager.select(tableName_questions, selectedFields, _where, SqlOrderBy::RANDOM(), questionsCount);


        while ( query.next() )
        {
            /// \todo TODO: type code here
            Question issue  = selectQuestion(query);	   
            QVector<Answer> replys = selectAnswers(sqlManager, answersCount, issue.getId() );

			issue.setAnswers(replys);
            pushQuestion(issue);
        }

        return true;
    }
    return false;
}
	
QVector<Answer> Theme::selectAnswers(const SQLMgr &sqlManager, const int answersCount, const QString &questionId) const
{
    using namespace Table::Answer::Field;        // зачем? ес
    QVector<Answer> replys;
    QStringList answerFields({ TEXT, VALID });
    QString tableName_answers = Table::Answer::TABLE_NAME;
    SqlWhere ansWhere(QUESTION_ID + " = '" + questionId + "'");
    QSqlQuery answerQuery = sqlManager.select(tableName_answers,
                                              answerFields,
                                              ansWhere,
                                              SqlOrderBy::RANDOM(),
                                              answersCount);

    while( answerQuery.next() )
    {
        QString text = answerQuery.value(answerQuery.record().indexOf(TEXT)).toString();
        bool valid = answerQuery.value(answerQuery.record().indexOf(VALID)).toBool();

        replys.push_back(Answer(text, valid));
    }

    return replys;
}

Question Theme::selectQuestion(const QSqlQuery &query) const
{ // reject into new method.  Question makeQuestion(const QSqlQueru &query)
    using namespace Table::Question::Field;
    Question issue;

    QString id = query.value(query.record().indexOf(QUESTION_ID)).toString(),
        text = query.value(query.record().indexOf(TEXT)).toString(),
        type = query.value(query.record().indexOf(QUESTION_TYPE)).toString();
    bool caseSens = query.value(query.record().indexOf(CASE_SENS)).toBool(),
        stripSpace = query.value(query.record().indexOf(STRIP_SPACE)).toBool();

    QTime time = query.value(query.record().indexOf(RECOMENDED_TIME)).toTime();

    issue.setId(id);
    issue.setText(text);
    issue.setType(type);
    issue.setTime(time);
    issue.setCaseSensitivity(caseSens);
    issue.setStripSpaces(stripSpace);
    return issue;
}


