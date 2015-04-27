#include <QtCore/QCoreApplication>

#include "mngrquerys.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

    QMap<QString,QString> data;
    data["fUne"]  = "vUne";
    data["fDue"]  = "vDue";
    data["fTree"] = "vTree";
    data["fQuetro"] = "vQuatro";

    QString name("test");
    MngrQuerys::createTable(name, data);

	return a.exec();
}								
