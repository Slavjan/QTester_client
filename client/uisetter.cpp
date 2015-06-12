#include "uisetter.h"
#include <qdebug.h>

namespace reqLists
{
    const QString auth = "/auth";
    const QString get = "/get";
    const QString profList = "profList";
    const QString lessonsList = "lessonsList";
    const QString themesList = "themesList";
    const QString questions = "questions";
}
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
 // _engine->contextForObject(Configure)->setContextObject( profs);
  QObject *obj = _engine->rootObjects()[0];
  _engine->contextForObject(obj)->setContextProperty(reqLists::profList, profs);
  qDebug() << obj->objectName();
  //->setContextObject( lessons );
}
void UiSetter::setLessonsList( const QJsonObject &lessons )
{
    QObject *obj = _engine->rootObjects()[1];
    _engine->contextForObject( obj )->setContextProperty( reqLists::profList, lessons );
    qDebug() << obj->objectName();
    //  _engine->rootObjects()["Configure"]->setProperty(reqLists::profList, profs);
}

void UiSetter::setThemesList( const QJsonObject &themes )
{
    QObject *obj = _engine->rootObjects()[2];
    _engine->contextForObject( obj )->setContextProperty( reqLists::profList, themes );
    qDebug() << obj->objectName();
  //_engine->contextForObject(Configure)->setContextObject( lessons );
  /*_engine->rootObjects()["Configure"]
      ->setProperty(reqLists::profList, profs);*/
}

void UiSetter::setQuestions( const QJsonObject &questions)//making
{
    QObject *obj = _engine->rootObjects()[3];
    _engine->contextForObject( obj )->setContextProperty( reqLists::profList, questions );
    qDebug() << obj->objectName();
 // _engine->contextForObject(Configure)->setContextObject( questions );
}
