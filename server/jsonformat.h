#pragma once

#include <QString>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include "profession.h"

class JsonFormat
{
private:
    
     

public:
    static QJsonObject professionToJsonObj( const Profession &prof );
    static QJsonObject lessonToJsonObj( const Lesson &lesson );
    static QJsonObject themeToJsonObj( const Theme &theme );
    static QJsonObject questionToJsonObj( const Question &question );
    static QJsonObject answerToJsonObj( const Answer &answer );

     
};