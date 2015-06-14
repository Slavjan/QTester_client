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
UiSetter::UiSetter(QQmlContext *root, QObject *parent) : QObject(parent)
{
  _root = root;
}

void UiSetter::setFullName(QString fullName)
{
  _root->setContextProperty("fullName", fullName);
}

void UiSetter::setLogin(QString login)
{
   _root->setContextProperty("username", login);
}

 //slots

void UiSetter::setProfList(const QJsonObject &profs)
{
  qDebug() << "client/[UiSetter::setProfList] profs> " << profs;
    QJsonArray response = profs["profList"].toArray();
  //qDebug() << "client/[UiSetter::setProfList] list> " << list;
//  QJsonArray arr;
//  for (int i = 0; i < respons.size(); ++i) {
//      arr.append(respons.at(i).toObject()["title"]);
//    }

  _root->setContextProperty("profList", response);//skype go
  //->setContextObject( lessons );
}
void UiSetter::setLessonsList( const QJsonObject &lessons )
{
  _root->setContextProperty( "lessonsList", lessons );

    //  _engine->rootObjects()["Configure"]->setProperty(reqLists::profList, profs);
}

void UiSetter::setThemesList( const QJsonObject &themes )
{
  _root->setContextProperty( "themesList", themes );

  //_engine->contextForObject(Configure)->setContextObject( lessons );
  /*_engine->rootObjects()["Configure"]
      ->setProperty(reqLists::profList, profs);*/
}

void UiSetter::setQuestions( const QJsonObject &questions)//making
{
  _root->setContextProperty( "questions", questions );

 // _engine->contextForObject(Configure)->setContextObject( questions );
}
