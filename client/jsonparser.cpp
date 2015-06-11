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

void JsonParser::getProfessionsList(const QJsonObject &response)
{
  QString pTitle = respons["title"].toString(),
          lTitle = Lessons["title"];
  QJsonArray jALessons = response["lessons"].toString(),
             jAThemes, jAQuestions, jAAnswers;

  //QJsonObject jOThemes = jALessons[""]
  emit getProfs(jALessons);
}

void JsonParser::getLessonsList(const QJsonObject &response)
{

}

void JsonParser::getQuestions(const QJsonObject &response)
{

}

void JsonParser::responseSlot(QString string)
{
  QJsonDocument doc = QJsonDocument::fromJson(string.toUtf8());
  QJsonObject obj = doc.object();
  int code = obj["code"].toInt();
  QJsonObject response = obj["response"].toObject();

  switch (code) {
    case 200:
      authorisation(response);
      break;
    case 201:
      getProfessionsList(response);
      break;
    case 202:
      getLessonsList(response);
      break;
    case 203:
      getQuestions(response);
      break;
    default:
      break;
    }
}

