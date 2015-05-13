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

    QString tableName("tt");	// ��� �������, ������� ���
	SQLiteMgr *db = new SQLiteMgr("", "", "", "");	
									/*path  - ���� ���� ���� ����������� � �������� �����*/
	QSqlQuery q;

//	db->

    db->createTable(tableName, data); // ��� ������� �������
	
    for (auto i = 0; i < 4; i++)	// �������� ������
	{
        DataMap data;
        data["fUne"]    = QString::number(i);
        data["fDue"]    = QString::number(i*2);
        data["fTree"]   = QString::number(i*50);
        data["fQuatro"] = QString::number(i) + " text";

        q = db->insert(tableName, data );
	}
//    QStringList x({"*"});
    q = db->select(tableName,{"*"}); // ������� ��������� ������
									   
    QSqlRecord  rec = q.record(); // ������� ��� ������ � �������
	int			nFUne = 0;	 // ��������������� ����������
	QString		strFDue;
	QString		strFTree;
	QString		strFQuatro;

	

//	if (q.isActive())
//		qDebug() << "ACTIVE " << rec << "\n";  // ��������� ��� ������ ������

    qDebug() << "fUne" << "| " << "fDue" << "|"
        << "fTree" << "|" << "fQuatro" << "| \n"; // ��������� �������


	q.first();		// �� ������ ������ � ������ ������
	while (q.next()) {	  // ������� ���� ������ �� ����������
		
        nFUne =		 q.value( 0 ).toInt();
        strFDue =	 q.value( 1 ).toString();
        strFTree =	 q.value( 2 ).toString();
        strFQuatro = q.value( 3 ).toString();

        qDebug() << nFUne << "| " << strFDue << "|"
            << strFTree << "|" << strFQuatro << "|  next\n"; // ��������������� ����� ������
	}
  
    return  /*0;*/ a.exec(); // �� ���� ��� � ���� ���������
}								
