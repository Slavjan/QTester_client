#include "uisetter.h"

UiSetter::UiSetter(QQmlApplicationEngine *engine, QObject *parent) : QObject(parent)
{
  _engine = engine;
}

void UiSetter::setFullName(QString fullName)
{
  _engine->rootContext()->setContextProperty("fullName", fullName);
}

void UiSetter::setLogin(QString login)
{
   _engine->rootContext()->setContextProperty("username", login);
}

 //slots

void UiSetter::setProfList(const QJsonObject &profs)
{
  _engine->contextForObject(Configure)->setContextObject("profList", profs);
}
void UiSetter::setLessonsList( const QString &profId )//making
{

}

void UiSetter::setThemesList( const QString &lessonId );                                            //TODO implemented
void UiSetter::setQuestions( const QString &themeId, qint64 questionsCount, qint64 answersCount );  //TODO implemented
