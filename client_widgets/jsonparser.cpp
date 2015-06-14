#include "jsonparser.h"

namespace reqLists
{
    const QString auth = "/auth";
    const QString get = "/get";
    const QString profList = "profList";
    const QString lessonsList = "lessonsList";
    const QString themesList = "themesList";
    const QString questions = "questions";
}

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

void JsonParser::takeProfessionsList(QJsonObject response)
{    
  IdTitleMap result;
  QJsonArray profArray = response[reqLists::profList].toArray();

  foreach (QJsonValue val, profArray) {
      QJsonObject obj = val.toObject();
      result[ obj["id"].toString() ] = obj["title"].toString();
  }

  emit takeProfs(result);
}

void JsonParser::takeLessonsList(QJsonObject response)
{
 // emit takeLessons(response);
}

void JsonParser::takeThemesLists(QJsonObject response)
{
//  emit takeThemes(response);
}

void JsonParser::takeQuestionsList(QJsonObject questions)
{
    QJsonObject q = questions;
 //   emit takeQuestions(questions);
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
    default:
      break;
    }
}
