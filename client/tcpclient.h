#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

#define DEBUG_OUTPUT /// < Включает вывод qDebug() qCritical() сообщений
#ifdef DEBUG_OUTPUT
    #include <QDebug>
#endif

/*! \~russian
 * \brief Класс для работы с Tcp соединением.
 * Предназначен для получения и отправки данных с/на сервер.
 */
class TcpClient : public QObject
{
    Q_OBJECT
private:
    QTcpSocket _socket;
    quint16    _nextBlockSize = 0; /// < \~russian Размер следующего ожидаемого блока данных.

    void connectSignalsAndSlots();

public:
    TcpClient(const QString& host, int port, QObject* parent = 0);
    TcpClient(QObject* parent = 0);
    void connectToServer(const QString &host, const int port);

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError error);
    void slotConnected();

public slots:
    void sendToServer(const QString &data);

signals:
    void dataRecieved(QString);
    void errorDataRecieved(QString);
    void connectedSuccess();
};

#endif // TCPCLIENT_H
