#include "mngrconnection.h"
#include <QStandardPaths>

MngrConnection::MngrConnection(const QString &dbDriver = "QSQLITE",
                               const QString &dbHost   = "",
                               const QString &dbUser   = "",
                               const QString &dbPass   = "")
{
    const QString dbPath( QStandardPaths::writableLocation(QStandardPaths::DataLocation) + QDir::separator() + "QTester" + QDir::separator() );

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
                              QObject::tr("It was not succeeded to create a directory for a database.") );
    }else{
        db.setDatabaseName( dbPath + "QTester.db" );
        db.setUserName( dbUser );
        db.setHostName( dbHost );
        db.setPassword( dbPass );
    }
}

QSqlError MngrConnection::lastError()
{
    return db.lastError();
}

bool MngrConnection::open()
{
    return db.open();
}

void MngrConnection::close()
{
    db.close();
}

bool MngrConnection::transaction()
{
    return db.transaction();
}

bool MngrConnection::commit()
{
    return db.commit();
}

bool MngrConnection::rollback()
{
    return db.rollback();
}

bool MngrConnection::isOpen()
{
    return db.isOpen();
}
