#include "jsonparser.h"

JsonParser::JsonParser(QObject *parent)
  : QObject(parent)
{

}

void JsonParser::authorisation(const QJsonObject &response)
{
  QString token = response["token"].toString(),
          fullName = response["fullUserName"].toString();

  emit authSignalPars(token, fullName);
  emit authSignalPars(fullName);
}

void JsonParser::takeProfessionsList(const QJsonObject &response)
{    
  emit takeProfs(respons);
}

void JsonParser::takeLessonsList(const QJsonObject &response)
{
  emit takeLessons(respons);
}

void JsonParser::takeThemesLists(const QJsonObject &response)
{
  emit takeThemes(response);
}

void JsonParser::parsQuestions(const QJsonObject &questions)
{
    QJsonObject q = questions;
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
      takeQuestions(response);
      break;
    default:
      break;
    }
}
//
//void respArraySlot( QJsonArray response )
//{
//    
//}
//
//
