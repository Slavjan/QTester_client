#ifndef UISETTER_H
#define UISETTER_H

#include <QObject>
#include <QQmlContext>

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
  void setProfList();
  void setLessonsList( const QString &profId );
  void setThemesList( const QString &lessonId );
  void setQuestions( const QString &themeId, qint64 questionsCount, qint64 answersCount );
};

#endif // UISETTER_H
