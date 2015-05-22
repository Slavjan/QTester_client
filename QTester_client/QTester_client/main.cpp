#include <QtCore/QCoreApplication>
#include <iostream>

#include "sqlitemgr.h"
#include "testgenerator.h"

#ifdef QT_DEBUG
    #define _DEBUG
#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	//a.setApplicationName("QTester_Client");

//    QMap<QString,QString> data;
//    data["fUne"]  = "INTEGER";
//    data["fDue"]  = "INTEGER";
//    data["fTree"] = "INTEGER";
//    data["fQuatro"] = "VARCHAR(20)";

    QString tableName("tt");	// имя таблицы, здрасте Кэп
    SQLMgr *db = new SQLiteMgr("", "", "", "");
									/*path  - если пуст база открывается в домашней папке*/
	QSqlQuery q;
    TestGenerator::collectTestVariant(*db, 1, 1);

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
