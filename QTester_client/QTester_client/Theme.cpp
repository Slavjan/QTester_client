#include "Theme.h"


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