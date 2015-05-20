#include <QStandardPaths>
#include "connectionmgr.h"

ConnectionMgr::ConnectionMgr(const QString& dbDriver = "",
                             const QString& dbHost = "",
								   QString	dbPath = "",
                             const QString& dbUser = "",
                             const QString& dbPass = "")
{
    if(dbPath.isEmpty()) 
		dbPath += QStandardPaths::writableLocation(QStandardPaths::DataLocation) + QDir::separator();

    if( !QSqlDatabase::isDriverAvailable(dbDriver) ){
        qCritical() << "Cannot avalible "<< dbDriver <<" driver";
        QMessageBox::critical(0 , QObject::tr("Critical"),
                              QObject::tr("Cannot avalible database driver") );
    }

    db = QSqlDatabase::addDatabase(dbDriver);

    if( !QDir().mkpath( dbPath ) ){
        qCritical() << "Cannot createed work directory"
                    << "\nPath: " << dbPath;
        QMessageBox::critical(0 , QObject::tr("Critical"),
                              QObject::tr("it was not succeeded to create a directory for a database.") );
    }else{
        db.setDatabaseName( dbPath + "QTester.db" );
        db.setUserName( dbUser );
        db.setHostName( dbHost );
        db.setPassword( dbPass );
    }

	qDebug() << dbPath;
}

QSqlError ConnectionMgr::lastError()
{
    return db.lastError();
}

bool ConnectionMgr::open()
{
    return db.open();
}

void ConnectionMgr::close()
{
    db.close();
}

bool ConnectionMgr::transaction()
{
    return db.transaction();
}

bool ConnectionMgr::commit()
{
    return db.commit();
}

bool ConnectionMgr::rollback()
{
    return db.rollback();
}

bool ConnectionMgr::isOpen()
{
    return db.isOpen();
}
