#include <QtCore/QCoreApplication>

#include "SQLiteMgr.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString,QString> data;		
    data["fUne"]  = "INTEGER";
    data["fDue"]  = "INTEGER";
    data["fTree"] = "INTEGER";
    data["fQuatro"] = "VARCHAR(20)";

    QString tableName("tt");	// имя таблицы, здрасте Кэп
	SQLiteMgr *db = new SQLiteMgr("", "", "", "");	
									/*path  - если пуст база открывается в домашней папке*/
	QSqlQuery q;

//	db->

    db->createTable(tableName, data); // тут таблицу создаем
	
    for (auto i = 0; i < 4; i++)	// добавляю данные
	{
        DataMap data;
        data["fUne"]    = QString::number(i);
        data["fDue"]    = QString::number(i*2);
        data["fTree"]   = QString::number(i*50);
        data["fQuatro"] = QString::number(i) + " text";

        q = db->insert(tableName, data );
	}
//    QStringList x({"*"});
    q = db->select(tableName,{"*"}); // пытаюсь запросить данные
									   
    QSqlRecord  rec = q.record(); // объекты для работы с данными
	int			nFUne = 0;	 // соответствующие переменные
	QString		strFDue;
	QString		strFTree;
	QString		strFQuatro;

	

//	if (q.isActive())
//		qDebug() << "ACTIVE " << rec << "\n";  // убеждаюсь что запрос прошел

    qDebug() << "fUne" << "| " << "fDue" << "|"
        << "fTree" << "|" << "fQuatro" << "| \n"; // заголовок таблицы


	q.first();		// на всякий случай к первой записи
	while (q.next()) {	  // выводим пока записи не закончатся
		
        nFUne =		 q.value( 0 ).toInt();
        strFDue =	 q.value( 1 ).toString();
        strFTree =	 q.value( 2 ).toString();
        strFQuatro = q.value( 3 ).toString();

        qDebug() << nFUne << "| " << strFDue << "|"
            << strFTree << "|" << strFQuatro << "|  next\n"; // непосредственно вывод данных
	}
  
    return  /*0;*/ a.exec(); // на этом Кэп с вами прощается
}								
