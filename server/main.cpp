#include <QCoreApplication>

//#include "sqlitemgr.h"
#include "profession.h"
#include "testgenerator.h"
#include "jsonformat.h"
#include "networkmanager.h"

#include <QCryptographicHash>
             
int main( int argc, char *argv[] )
{
    QCoreApplication a( argc, argv );

    SQLMgr *db = new SQLiteMgr( "", "", "", "" );
    setlocale( LC_ALL, "Russian" );

    qDebug() << "//Server/ лчслдвыадвылоадлвыоавылоа  бла-бла-бла! ";

   /* DataMap map;
    map["password"] = "111";
    map["firstName"] = "Бла";
    map["secondName"] = "bla";
    map["login"] = "Khaidayev";
    db->insert("Users", map );*/

    NetworkManager netMan( *db );

//    QByteArray hashPass = QCryptographicHash::hash( QByteArray("123"), QCryptographicHash::Md5 );

//    qDebug() << "[SQLMgr::auth]password>" << hashPass ;
    /*IdTitleMap lessons = Lesson::getLessonsList( *db ),
               themes = Theme::getThemeList( *db );*/
                                                                
    //idThemeIdsMap lessons_themes_ids;

  /*  lessons_themes_ids[lessons.key( "Сетевые технологии" )] = QStringList( { themes.key( "Топология и конфигурация сетей" ), themes.key( "JavaScript" ) } );
    lessons_themes_ids[lessons.key( "ОС и ПО ВК" )] = QStringList( { themes.key( "UNIX-системы" ), themes.key( "Norton Comander" ) } );
*/
 /*   ParamsForCollection params;
    params.professionId = "1";
    params.lessIds = lessons_themes_ids.keys().first();
    params.themsIds = lessons_themes_ids.values().first();
    params.questionsCount = 5;
    params.answersCount = 5;

    auto prof = TestGenerator::collectTestVariant( *db, params );
    QJsonDocument doc;
    doc.setObject( JsonFormat::professionToJsonObj( prof ) );
    qDebug() << doc.toJson( QJsonDocument::Indented );
*/
//    delete _server;

    return  a.exec();
}


/////////////////////////
/*
 TODO:
* SocketConnectionManager
* UserControl
* AccessManager
* iApiManager
* Api_1_0

*/
