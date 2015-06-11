#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QObject>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

namespace Codes{
    enum requests{auth = 200, Prof, Lessons, Themes, Questions };
}

class JsonParser : public QObject
{
  Q_OBJECT
public:
  explicit JsonParser(QObject *parent = 0);

  void authorisation(const QJsonObject &response);
  void takeProfessionsList(const QJsonObject &response);
  void takeLessonsList(const QJsonObject &response);
  void takeThemesLists(const QJsonObject &response);
  void takeQuestions(const QJsonObject &questions);
signals:
  void authSignalPars(QString token, QString fullName);
  void authSignalPars(QString fullName);

  void takeProfs(QJsonObject &profsList);
  void takeLessons(QJsonObject &Lessons);
  void takeThemes (QJsonObject &Themes );
  void takeQuestions(QJsonObject &Questions);
public slots:
  void responseSlot(QString);
  //void respArraySlot(QJsonArray);
};


namespace reqLists
{
    const QString profList = "profLsit";
    const QString lessonsList = "lessonsLsit";
    const QString themesList = "themesLsit";
    const QString questions = "questions";
}
#endif // JSONPARSER_H
