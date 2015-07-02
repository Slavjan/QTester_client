#pragma once
#include "qobject.h"
#include "tcpserver.h"
#include "db/sqlmgr.h"
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
signals:
    void newClientConnected(QTcpSocket *client);
public slots:
    void newClient(QTcpSocket* client);
    void inputQuery( QString, QTcpSocket* );
public:
    NetworkManager(SQLMgr &sqlMgr, const int port );
    ~NetworkManager();
};

