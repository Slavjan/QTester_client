#include <QtCore/QCoreApplication>

#include "SQLiteMgr.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

    QMap<QString,QString> data;
    data["fUne"]  = "vUne";
    data["fDue"]  = "vDue";
    data["fTree"] = "vTree";
    data["fQuetro"] = "vQuatro";

    QString name("test");
	
	SQLiteMgr *sql = new SQLiteMgr();
	
	

	sql->Hi("I`m SQLMgr");


	//QStringList par;
	//par << "par1" << "par2";
//	SQLiteMgr::sescionConfigurate(QStringList({ "dsfsdfs", "sdfsfsd" }), QStringList({ "val1", "val2" }), 5);

	/*;
	MYSQLMgr  b;*/


	return a.exec();
}								
