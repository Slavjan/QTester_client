#include "jsonparser.h"
#include <qdebug.h>

namespace reqLists
{
    const QString auth = "/auth";
    const QString get = "/get";
    // lists
    const QString profList = "profList";
    const QString lessonsList = "lessonsList";
    const QString themesList = "themesList";
    const QString questions = "questions";
    const QString answers = "answers";
    // trees
    const QString profTree = "profTree";
    const QString lessonsTree = "lessonsTree"; // getlessonsTree?profId = %id
    const QString themesTree = "themesTree";
    const QString questionsTree = "questionsTree";
    const QString answersTree = "answersTree";
    // tabels
    const QString profTable      = "profTable";
    const QString lessonsTable   = "lessonsTable";
    const QString themesTable    = "themesTable";
    const QString questionsTable = "questionsTable";
    const QString answersTable   = "answersTable";
}

JsonParser* JsonParser::_instance = nullptr;

JsonParser::JsonParser(QObject *parent)
  : QObject(parent)
{

}

JsonParser* JsonParser::instance(QObject *parent)
{
  if( !_instance )
  {
      _instance = new JsonParser( parent );
  }

  return _instance;
}

void JsonParser::authorisation(const QJsonObject &response)
{
  QString token = response["token"].toString(),
          fullName = response["fullUserName"].toString();

  emit authSignalPars(token, fullName);
  emit authSignalPars(fullName);
}

IdTitleMap JsonParser::takeProfs(QJsonObject response)
{
    IdTitleMap result;
    QJsonArray profArray = response[reqLists::profList].toArray();

    foreach (QJsonValue val, profArray) {
        QJsonObject obj = val.toObject();
        qDebug() << obj["id"].toString() << " " << obj["title"].toString();
        result[QString::number( obj["id"].toInt() )] = obj["title"].toString();
    }

    return result;
}

void JsonParser::takeProfessionsList(QJsonObject response)
{    
  IdTitleMap result = takeProfs(response);
  qDebug() << result;
  emit takeProfsList(result);
}

void JsonParser::takeProfsTree(QJsonObject response)
{
    IdTitleMap result = takeProfs(response);
    qDebug() << result;
    emit takeSignalProfsTree(result);
}



void takeTable(QJsonObject response)
{
   // todo какая-то структура для передачи таблицы в модель
}

IdTitleMap JsonParser::takeLessons(QJsonObject response)
{
    IdTitleMap result;
    QJsonArray lessonsArray = response[reqLists::lessonsList].toArray();

    foreach (QJsonValue val, lessonsArray) {
        QJsonObject obj = val.toObject();
        qDebug() << obj["id"].toString() << " " << obj["title"].toString();
        result[QString::number( obj["id"].toInt() )] = obj["title"].toString();
    }

    return result;
}

void JsonParser::takeLessonsList(QJsonObject response)
{
  IdTitleMap result = takeLessons(response);
  emit takeLessons(result);
}

void JsonParser::takeLessonsTree(QJsonObject response)
{
  IdTitleMap result = takeLessons(response);
  emit takeSignalLessonsTree(result);
}

IdTitleMap JsonParser::takeThemes(QJsonObject response)
{
    IdTitleMap result;
    QJsonArray themeArray = response[reqLists::themesList].toArray();
    qDebug() << response;
    foreach( QJsonValue val, themeArray )
    {
        QJsonObject obj = val.toObject();
        qDebug() << obj["id"].toString() << " " << obj["title"].toString();
        result[QString::number( obj["id"].toInt() )] = obj["title"].toString();
    }

    return result;
}

void JsonParser::takeThemesLists(QJsonObject response)
{
  IdTitleMap result = takeThemes(response);
  emit takeThemes(result);
}

void JsonParser::takeThemesTree(QJsonObject response)
{
    IdTitleMap result = takeThemes(response);
    emit takeSignalThemesTree(result);
}

QVector<strQuestions> JsonParser::takeQuestions(QJsonObject response)
{
    QVector<strQuestions> result;

    strAnswers strAns;
    QJsonArray questionsArray = response[reqLists::questions].toArray(),
            answersArray;
    foreach( QJsonValue questionVal, questionsArray )
    {
        strQuestions strQs;
        QJsonObject questionObj = questionVal.toObject();
        answersArray = questionObj[reqLists::answers].toArray();
        strQs.text = questionObj["text"].toString(),
                strQs.type = questionObj["type"].toString();
        strQs.id =  questionObj["id"].toInt();

        foreach (QJsonValue ansVal, answersArray)
        {
            QJsonObject  ansObj = ansVal.toObject();
            strAns.id = ansObj["id"].toInt();
            strAns.text = ansObj["text"].toString();
            strAns.valid = ansObj["valid"].toBool();
            strQs.answers.push_back(strAns);
        }
        result.push_back( strQs );
    }

    return result;
}

void JsonParser::takeQuestionsList(QJsonObject response)
{
    QVector<strQuestions> result = takeQuestions(response);
    emit takeQuestions(result);
}

void JsonParser::takeQuestionsTree(QJsonObject response)
{
//    QVector<strQuestions> result = takeQuestions(response);
//    emit takeSignalQuestionsTree(result);
}

void JsonParser::takeQuestionsCount(QJsonObject response)
{
  qint64 count = response["questionsCount"].toInt();
  emit takeSignalQuestionsCount(count);
}

void JsonParser::responseSlot(QString string)
{
  QJsonDocument doc = QJsonDocument::fromJson(string.toUtf8());
  QJsonObject obj = doc.object();
  int code = obj["code"].toInt();
  QJsonObject response = obj["response"].toObject();

  switch (code)
  {
  case Codes::auth:
    authorisation(response);
    break;
  case Codes::ProfList:
    takeProfessionsList(response);
    break;
  case Codes::LessonsList:
    takeLessonsList(response);
    break;
  case Codes::ThemesList:
    takeThemesLists( response );
    break;
  case Codes::QuestionsList:
    takeQuestionsList(response);
    break;
  case Codes::QuestionsCount:
    takeQuestionsCount(response);
  default:
    break;
  }
}
