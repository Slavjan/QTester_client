#pragma once
#include "qobject.h"
#include "tcpserver.h"
#include "sqlmgr.h"
#include "users/usercontrol.h"
#include "requestsmanager.h"

class NetworkManager :
    public QObject
{
    Q_OBJECT
private:
    TcpServer *_server;
    SQLMgr *_sqlMgr;

    void connectSlots();
public slots:
    void newClient( QTcpSocket* );
    void inputQuery( QString, QTcpSocket* );
public:
    NetworkManager(SQLMgr &sqlMgr, const int port );
    ~NetworkManager();
};

