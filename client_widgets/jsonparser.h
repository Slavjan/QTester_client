#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QObject>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QMap>
#include <QVector>

namespace Codes{
    enum requests{auth = 200, ProfList, LessonsList, ThemesList, QuestionsList, QuestionsCount,
                  ProfsTree, LessonsTree, ThemesTree, QuestionsTree, AnswersTree,
                  ProfTable, LessonTable, ThemeTable, QuestionTable, AnswerTable,
                  ProfsTable, LessonsTable, ThemesTable, QuestionsTable, AnswersTable};
}
struct strAnswers
{
  qint64 id;
  QString text;
  bool valid;

  QWidget *wgt = nullptr;
};
struct strQuestions
{
  qint64 id;
  QString text;
  QString type;
  QVector<strAnswers> answers;
};

typedef QMap<QString, QString> IdTitleMap;

namespace userGroups
{
    enum UserGroups { Admin = 0, Prepod, Student};
}


class JsonParser : public QObject
{
  Q_OBJECT
private:
  static JsonParser *_instance;

  explicit JsonParser(QObject *parent = 0);
public:
  static JsonParser *instance(QObject *parent = 0);

  void authorisation(const QJsonObject &response);
  void takeProfessionsList(QJsonObject response);
  void takeLessonsList(QJsonObject response);
  void takeThemesLists(QJsonObject response);
  void takeQuestionsList(QJsonObject response );
  void takeQuestionsCount(QJsonObject response);


  QVector<strQuestions> takeQuestions(QJsonObject response);
private:
  IdTitleMap takeProfs(QJsonObject response);
  IdTitleMap takeLessons(QJsonObject response);
  IdTitleMap takeThemes(QJsonObject response);

signals:
  void authSignalPars( QString token, QString fullName, int userGroup );
  void authSignalPars(QString token, QString fullName);
  void authSignalPars(QString fullName);

  void takeProfsList    (IdTitleMap profsList);
  void takeLessons  (IdTitleMap Lessons);
  void takeThemes   (IdTitleMap Themes );
  void takeQuestions(QVector<strQuestions> &Questions);
  void takeSignalQuestionsCount(qint64);

public slots:
  void responseSlot(QString);
  //void respArraySlot(QJsonArray);

};


#endif // JSONPARSER_H
