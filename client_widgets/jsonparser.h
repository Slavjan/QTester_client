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
                  TopRowProf, TopRowLesson, TopRowTheme, TopRowQuestion, TopRowAnswer,
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

  void takeProfsTree(QJsonObject response);
  void takeLessonsTree  (QJsonObject response);
  void takeThemesTree   (QJsonObject response);
  void takeQuestionsTree(QJsonObject response);
  void takeAnswersTree  (QJsonObject response);
  void takeProfsTable     (QJsonObject response);
  void takeLessonsTable   (QJsonObject response);
  void takeThemesTable    (QJsonObject response);
  void takeQuestionsTable (QJsonObject response);
  void takeAnswersTable   (QJsonObject response);
  void takeProfTable      (QJsonObject response);
  void takeLessonTable    (QJsonObject response);
  void takeThemeTable     (QJsonObject response);
  void takeQuestionTable  (QJsonObject response);
  void takeAnswerTable    (QJsonObject response);

  QVector<strQuestions> takeQuestions(QJsonObject response);
private:
  IdTitleMap takeProfs(QJsonObject response);
  IdTitleMap takeLessons(QJsonObject response);
  IdTitleMap takeThemes(QJsonObject response);

signals:
  void authSignalPars(QString token, QString fullName);
  void authSignalPars(QString fullName);

  void takeProfsList    (IdTitleMap profsList);
  void takeLessons  (IdTitleMap Lessons);
  void takeThemes   (IdTitleMap Themes );
  void takeQuestions(QVector<strQuestions> &Questions);
  void takeSignalQuestionsCount(qint64);

  void takeSignalProfsTree    (IdTitleMap tree);
  void takeSignalLessonsTree  (IdTitleMap tree);
  void takeSignalThemesTree   (IdTitleMap tree);
  void takeSignalQuestionsTree(IdTitleMap tree);
  void takeSignalAnswersTree  (IdTitleMap tree);
  void takeSignalProfsTable();
  void takeSignalLessonsTable();
  void takeSignalThemesTable();
  void takeSignalQuestionsTable();
  void takeSignalAnswersTable();
  void takeSignalProfTable();
  void takeSignalLessonTable();
  void takeSignalThemeTable();
  void takeSignalQuestionTable();
  void takeSignalAnswerTable();
  void takeTree();
public slots:
  void responseSlot(QString);
  //void respArraySlot(QJsonArray);

};


#endif // JSONPARSER_H
