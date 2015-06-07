#include "tcpclient.h"

#include <QTime>
#include <QString>
/*! \~russian
 * \brief Метод предназначен для соединения внутренних сигналов и слотов класса.
 */
void TcpClient::connectSignalsAndSlots()
{
    connect(&_socket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(&_socket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(&_socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this,       SLOT(slotError(QAbstractSocket::SocketError))
            );
}
/*! \~russian
 * \brief Конструктор инициализирует объект и открывает соединение
 * \param host - адрес удаленного сервера
 * \param port - порт на удаленном сервере
 * \param parent - родитель для инициализации QObject
 */
TcpClient::TcpClient(const QString &host, int port, QObject *parent)
    :QObject(parent)
{
    connectSignalsAndSlots();
    connectToServer(host, port);
}

/*! \~russian
 * \brief Конструктор инициализирует объект, но для установки соединения необходимо
 *        воспользоваться методом TcpClient::connectToServer
 * \param parent - родитель для инициализации QObject
 */
TcpClient::TcpClient(QObject *parent)
    :QObject(parent)
{
    connectSignalsAndSlots();
}

/*! \~russian
 * \brief Метод предназначен для открытия соединения с удаленным сервером.
 * \param host - адрес удаленного сервера
 * \param port - порт на удаленном сервере
 */
void TcpClient::connectToServer(const QString &host, const int port)
{
    if( ! _socket.isOpen() ){
        _socket.connectToHost(host, port);
    }else{
#ifdef DEBUG_OUTPUT
        qWarning() << "Connection is already open.";
#endif
    }
}

/*! \~russian
 * \brief Внутренний слот класса.
 * Предназначен для чтения принимаемых с сервера данных
 * \note не понимаю цикла. Сигнал с данными, по идее, будет высылаться
 * на каждую порцию принятых данных, возможно ошибочная реализация.
 *
 * \code
 * QObject::connect(     tcpObj, SIGNAL( dataRecieved(QString&)      ),
 *                   anotherObj, SLOT  ( slotDataRecieved(QString&)) );
 * \endcode
 */
void TcpClient::slotReadyRead()
{
    QDataStream in(&_socket);
    in.setVersion(QDataStream::Qt_4_2);
    for (;;) {
        if (!_nextBlockSize) {
            if (_socket.bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> _nextBlockSize;
        }

        if (_socket.bytesAvailable() < _nextBlockSize) {
            break;
        }
        QString str;
        in >> str;

        _nextBlockSize = 0;

        emit dataRecieved( str );
    }
}

/*! \~russian
 * \brief Внутренний слот класса.
 * Принимает ошибку соединения и высылает сигнал об ошибке, со строкой
 * содержащей описание ошибки.
 * \param error - код ошибки сокета
 *
 * \code
 * QObject::connect(     tcpObj, SIGNAL( errorDataRecieved(QString&)      ),
 *                   anotherObj, SLOT  ( slotErrorDataRecieved(QString&)) );
 * \endcode
 */
void TcpClient::slotError(QAbstractSocket::SocketError error)
{
    QString errorMessage;

    if(      error == QAbstractSocket::HostNotFoundError )
        errorMessage = "The host was not found.";
    else if( error == QAbstractSocket::RemoteHostClosedError )
        errorMessage = "The remote host is closed.";
    else if( error == QAbstractSocket::ConnectionRefusedError )
        errorMessage = "The connection was refused.";
    else
        _socket.errorString();

#ifdef DEBUG_OUTPUT
    qCritical() << errorMessage;
#endif
    emit errorDataRecieved( errorMessage );
}

/*! \~russian
 * \brief Слот для отправки данных на сервер. Соединение должно быть открыто.
 * \param data - данные для отправки
 */
void TcpClient::sendToServer(const QString &data)
{
    if( _socket.isOpen() ){
        QByteArray  arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_2);
        out << quint16(0) << data;

        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));

        _socket.write( arrBlock );
    }else{
#ifdef DEBUG_OUTPUT
        qCritical() << "Connection is not open.";
#endif
    }
}

/*! \~russian
 * \brief Внутренний слот класса. Высылает сигнал об супешности соединения.
 *
 * \code
 * QObject::connect(     tcpObj, SIGNAL( connectedSuccess()      ),
 *                   anotherObj, SLOT  ( slotConnectedSuccess()) );
 * \endcode
 */
void TcpClient::slotConnected()
{
    emit connectedSuccess();
}
