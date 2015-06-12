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
  void takeProfessionsList(QJsonObject response);
  void takeLessonsList(QJsonObject response);
  void takeThemesLists(QJsonObject response);
  void takeQuestionsList( QJsonObject questions );
signals:
  void authSignalPars(QString token, QString fullName);
  void authSignalPars(QString fullName);

  void takeProfs(QJsonObject     profsList);
  void takeLessons(QJsonObject   Lessons);
  void takeThemes (QJsonObject   Themes );
  void takeQuestions(QJsonObject Questions);
public slots:
  void responseSlot(QString);
  //void respArraySlot(QJsonArray);
};
#endif // JSONPARSER_H
