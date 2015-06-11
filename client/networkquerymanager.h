#pragma once
#include <QObject>
#include <QUrlQuery>
#include "tcpclient.h"

class NetworkQueryManager :
    public QObject
{
    Q_OBJECT
private:
    TcpClient *_client;
public slots:
    void connectionOpen();
    void authorisation(const QString &login, const QString &password);
    void statusMessage(const QString &msg);
signals:
    void dataRecieved( QString );

public:
    NetworkQueryManager(const QString &host, const int port);
    ~NetworkQueryManager();

    TcpClient* getClient();
};

