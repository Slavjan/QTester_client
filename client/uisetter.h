#ifndef UISETTER_H
#define UISETTER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "jsonparser.h"

class UiSetter : public QObject
{
  Q_OBJECT
  QQmlContext *_root;
public:
  explicit UiSetter(QQmlContext *root, QObject *parent = 0);

signals:
  void pullProfList();
  void pullLessonsList( const QString &profId );
  void pullThemesList( const QString &lessonId );
  void pullQuestions( const QString &themeId, qint64 questionsCount, qint64 answersCount );

public slots:
  void setFullName( QString fullName );
  void setLogin( QString login );

  void setProfList( const QJsonObject &profs );
  void setLessonsList( const QJsonObject &lessons);
  void setThemesList( const QJsonObject &themes);
  void setQuestions( const QJsonObject &questions);
};

#endif // UISETTER_H
