#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

#include <QObject>

#define DEBUG_OUTPUT /// < Включает вывод qDebug() qCritical() сообщений
#ifdef DEBUG_OUTPUT
    #include <QDebug>
#endif

/*!
 * \brief Класс для обмена данными с клиентами по протоколу TCP
 */
class TcpServer : public QObject
{
    Q_OBJECT
private:
    QTcpServer _server;
    quint16    _nextBlockSize;

    void connectSignals();
public:
    TcpServer(int port, QObject *parent = 0);
    TcpServer(QObject *parent = 0);

private slots:
    virtual void slotNewConnection();
            void slotReadClient();

public slots:
            void sendToClient(QTcpSocket *client, const QString &str);

public slots:
    bool listen(const int port);

signals:
    void newConnection(QTcpSocket*);
    void dataRecieved(QString);
    void dataRecieved(QString, QTcpSocket*);
};

#endif // TCPSERVER_H
