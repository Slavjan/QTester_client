#include "networkmanager.h"


void NetworkManager::connectSlots()
{
    connect( _server, SIGNAL( dataRecieved(QString, QTcpSocket*) ),
             this, SLOT( inputQuery( QString, QTcpSocket* ) )
             );
    connect( _server, SIGNAL( newConnection( QTcpSocket* ) ), 
             this, SLOT( newClient( QTcpSocket* ) ) );
}

NetworkManager::NetworkManager( SQLMgr &sqlMgr)
    : QObject(0)
{
    _sqlMgr = &sqlMgr;  
    
    _server = new TcpServer( 3434 ); 
    connectSlots();
}

void NetworkManager::newClient( QTcpSocket* )
{
    qDebug() << "[NetworkManager::newClient]";
}

NetworkManager::~NetworkManager()
{
    delete _server;
}

void NetworkManager::inputQuery(QString request, QTcpSocket* client )
{
    qDebug() << "NetworkManager::inputQuery :";
    qDebug() << "Request: " << request;
    
    QString outputData = RequestsManager::request( *_sqlMgr, request );
    qDebug() << outputData;
    _server->sendToClient( client, outputData );
}