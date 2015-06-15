#include "jsonparser.h"
#include <qdebug.h>

namespace reqLists
{
    const QString auth = "/auth";
    const QString get = "/get";
    const QString profList = "profList";
    const QString lessonsList = "lessonsList";
    const QString themesList = "themesList";
    const QString questions = "questions";
    const QString answers = "answers";
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

void JsonParser::takeProfessionsList(QJsonObject response)
{    
  IdTitleMap result;
  QJsonArray profArray = response[reqLists::profList].toArray();

  foreach (QJsonValue val, profArray) {
      QJsonObject obj = val.toObject();
      qDebug() << obj["id"].toString() << " " << obj["title"].toString();
      result[QString::number( obj["id"].toInt() )] = obj["title"].toString();
  }
  qDebug() << result;
  emit takeProfs(result);
}

void JsonParser::takeLessonsList(QJsonObject response)
{
  IdTitleMap result;
  QJsonArray lessonsArray = response[reqLists::lessonsList].toArray();

  foreach (QJsonValue val, lessonsArray) {
      QJsonObject obj = val.toObject();        
      qDebug() << obj["id"].toString() << " " << obj["title"].toString();
      result[QString::number( obj["id"].toInt() )] = obj["title"].toString();
  }
  emit takeLessons(result);
}

void JsonParser::takeThemesLists(QJsonObject response)
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

  emit takeThemes(result);
}

void JsonParser::takeQuestionsList(QJsonObject response)
{
  QVector<strQuestions> result;
  strQuestions strQs;
  strAnswers strAns;
  QJsonArray questionsArray = response[reqLists::questions].toArray(),
             answersArray;
  foreach( QJsonValue questionVal, questionsArray )
  {
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
  //  QJsonObject q = questions;
  emit takeQuestions(result);
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

  switch (code) {
    case Codes::auth:
      authorisation(response);
      break;
    case Codes::Prof:
      takeProfessionsList(response);
      break;
    case Codes::Lessons:
      takeLessonsList(response);
      break;
    case Codes::Themes:
      takeThemesLists( response );
      break;
    case Codes::Questions:
      takeQuestionsList(response);
      break;
    case Codes::QuestionsCount:
      takeQuestionsCount(response);
    default:
      break;
    }
}
