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

    QString name("tt");	// имя таблицы, здрасте Кэп
	SQLiteMgr *db = new SQLiteMgr("", "", "", "");	
									/*path  - если пуст база открывается в домашней папке*/
	QSqlQuery q;

//	db->

	db->createTable(name, data); // тут таблицу создаем
	
    for (auto i = 0; i < 4; i++)	// добавляю данные
	{
		auto it = i * 2;
		auto it1 = i * 50;
        QStringList f({ "fUne", "fDue", "fTree", "fQuatro" });
        QStringList v({QString::number(i), QString::number(it), QString::number(it1), QString::number(i)+" text" });
        q = db->insert(name,f, v );
	}
    QStringList x({"*"});
    q = db->select(name,x); // пытаюсь запросить данные
									   
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
		
		nFUne =		 q.value(0).toInt();
		strFDue =	 q.value(1).toString();
		strFTree =	 q.value(2).toString();
		strFQuatro = q.value(3).toString();

        qDebug() << nFUne << "| " << strFDue << "|"
            << strFTree << "|" << strFQuatro << "|  next\n"; // непосредственно вывод данных
	}
  
    return  /*0;*/ a.exec(); // на этом Кэп с вами прощается
}								
