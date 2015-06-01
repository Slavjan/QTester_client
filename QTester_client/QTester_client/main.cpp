#include <QtCore/QCoreApplication>
#include <iostream>

#include "sqlitemgr.h"
#include "profession.h"

#ifdef QT_DEBUG
#define _DEBUG
#endif

int main( int argc, char *argv[] )
{
    QCoreApplication a( argc, argv );
    //a.setApplicationName("QTester_Client");

    //    QMap<QString,QString> data;
    //    data["fUne"]  = "INTEGER";
    //    data["fDue"]  = "INTEGER";
    //    data["fTree"] = "INTEGER";
    //    data["fQuatro"] = "VARCHAR(20)";

    //  QString tableName("tt");	// имя таблицы, здрасте Кэп
    SQLMgr *db = new SQLiteMgr( "", "", "", "" );
    /*path  - если пуст база открывается в домашней папке*/
    QSqlQuery q;
    // TestGenerator::collectTestVariant(*db, 1, 1);
    setlocale( LC_ALL, "Russian" );

    QMap<QString, QVector<QString>> lessons_themes_ids;

    lessons_themes_ids["1"] = QVector<QString>( { "1", "2" } );
    lessons_themes_ids["2"] = QVector<QString>( { "3", "5" } );
    

    Professtion prof( "web" );
    prof.setId( "1" );
    prof.selectLessonsFromDatabase( *db, lessons_themes_ids, 5, 5 );

    for( auto i = 0; i < prof.getLessons().count(); i++ )
    {
        qDebug() << "\n\\lesson \\name > " << prof.getLessons().at( i ).getName() << "\\title >" << prof.getLessons().at( i ).getTitle();
        
        for( auto j = 0; j < prof.getLessons().at( i ).getThemes().count(); j++ )
        {
            qDebug() << "\n\\theme \\name > " << prof.getLessons().at( i ).getThemes().at( j ).getName() << "\\title >" << prof.getLessons().at( i ).getThemes().at( j ).getTitle();
             
            for( auto k = 0; k < prof.getLessons().at( i ).getThemes().at(j).getQuestions().count(); k++ )
            {
                qDebug() << "\n\\question " << k << " > " << prof.getLessons().at( i ).getThemes().at( j ).getQuestions().at(k).getText();

                for( auto l = 0; l < prof.getLessons().at( i ).getThemes().at( j ).getQuestions().at(k).getAnswers().size(); l++ )
                {
                    qDebug() << "\\answer " << l << " > " << prof.getLessons().at( i ).getThemes().at( j ).getQuestions().at( k ).getAnswers().at(l).getValue();
                }
            }
        }
    }

        //    db->createTable(tableName, data); // тут таблицу создаем

        //    for (auto i = 0; i < 4; i++)	// добавляю данные
        //    {
        //        DataMap data;
        //        data["fUne"]    = QString::number(i);
        //        data["fDue"]    = QString::number(i*2);
        //        data["fTree"]   = QString::number(i*50);
        //        data["fQuatro"] = QString::number(i) + " text";

        //        q = db->insert(tableName, data );
        //    }

        //    q = db->select(tableName, {"*"}); // пытаюсь запросить данные


        //    QSqlRecord  rec = q.record(); // объекты для работы с данными
        //	int			nFUne = 0;	 // соответствующие переменные
        //	QString		strFDue;
        //	QString		strFTree;
        //	QString		strFQuatro;
        // костыль
        //	int count = 0;
        //	while (q.next()){
        //		count++;		// когда записей 8 всё норм но если 10000, то уже БООльшИИе тормоза пойдут
        //	}

        //    db->size("tt");
        //	qDebug() << "count(*) >" << count; // заголовок таблицы


        //	q.first();		// на всякий случай к первой записи
        //while (q.next()) {	  // выводим пока записи не закончатся
        //	
        //       nFUne =		 q.value( 0 ).toInt();
        //       strFDue =	 q.value( 1 ).toString();
        //       strFTree =	 q.value( 2 ).toString();
        //       strFQuatro = q.value( 3 ).toString();

        //       qDebug() << nFUne << "| " << strFDue << "|"
        //           << strFTree << "|" << strFQuatro << "|  next"; // непосредственно вывод данных
        //}

        return  a.exec();
}
