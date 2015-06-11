#ifndef UISETTER_H
#define UISETTER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class UiSetter : public QObject
{
  Q_OBJECT
  QQmlApplicationEngine *_engine;
public:
  explicit UiSetter(QQmlApplicationEngine *engine, QObject *parent = 0);

signals:
  void pullProfList();
  void pullLessonsList( const QString &profId );
  void pullThemesList( const QString &lessonId );
  void pullQuestions( const QString &themeId, qint64 questionsCount, qint64 answersCount );

public slots:
  void setFullName( QString fullName );
  void setLogin( QString login );

  void setProfList( const QJsonObject &profs );
  void setLessonsList( const QJsonObject &profs);
  void setThemesList( const QJsonObject &profs);
  void setQuestions( const QJsonObject &profs);
};

#endif // UISETTER_H
