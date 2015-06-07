#include "tcpserver.h"

/*! \~russian
 * \brief Метод предназначен для соединения внутренних сигналов и слотов класса.
 */
void TcpServer::connectSignals()
{
    connect(&_server, SIGNAL(newConnection()),
             this,    SLOT(slotNewConnection())
            );
}

/*! \~russian
 * \brief Конструктор инициализирует объект и ставит сервер на прослушивание порта.
 * \param port - порт для прослушивания
 * \param parent - родитель для инициализации QObject
 */
TcpServer::TcpServer(int port, QObject *parent)
    : QObject(parent), _nextBlockSize(0)
{
    listen(port);
    connectSignals();
}

/*! \~russian
 * \brief Конструктор инициализирует объект. Для прослушивания порта необходимо воспользоваться методом TcpServer::listen
 * \param parent - родитель для инициализации QObject
 */
TcpServer::TcpServer(QObject *parent)
    :QObject(parent)
{
    connectSignals();
}

/*! \~russian
 * \brief Слот для отправки данных клиенту.
 * \param client - указатель на объект QTcpSocket клиента
 * \param str - данные для отправки
 */
void TcpServer::sendToClient(QTcpSocket *client, const QString &str)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    client->write(arrBlock);
}

/*! \~russian
 * \brief Внутренний слот класса.
 * Предназначен для принятия сигнала о новом соединении.
 * Высылает сигнал с сокетом присоединившегося клиента.
 * Соединяет методы клиента и сервера.
 *
 * \code
 * QObject::connect( serverObject,  SIGNAL(newConnection(QTcpSocket*)),
 *                   anotherObject,   SLOT(slotNewConnection(QTcpSocket*)) );
 * \endcode
 */
void TcpServer::slotNewConnection()
{
    QTcpSocket* client = _server.nextPendingConnection();
    connect(client, SIGNAL(disconnected()),
            client, SLOT(deleteLater())
           );
    connect(client, SIGNAL(readyRead()),
            this,   SLOT(slotReadClient())
           );

    emit newConnection(client);
}

/*! \~russian
 * \brief Внутренний слот класса.
 * Предназначен для чтения пришедших от клиента данных.
 * Высылает сигналы с данными и сокетом клиента.
 *
 * \code
 * QObject::connect( serverObject,  SIGNAL(dataRecieved(QString&,QTcpSocket*)),
 *                   anotherObject,   SLOT(slotDataRecieved(QString&,QTcpSocket*)) );
 * \endcode
 */
void TcpServer::slotReadClient()
{
    QTcpSocket* client = (QTcpSocket*)sender();
    QDataStream in(client);

    in.setVersion(QDataStream::Qt_4_2);
    for (;;) {
        if (!_nextBlockSize) {
            if (client->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> _nextBlockSize;
        }

        if (client->bytesAvailable() < _nextBlockSize) {
            break;
        }
        QString str;
        in >> str;

        _nextBlockSize = 0;

        emit dataRecieved( str );
        emit dataRecieved( str, client );
    }
}

/*! \~russian
 * \brief Метод для установки сервера на прослушку порта
 * \param port - порт для прослушивания
 * \return успех операции
 */
bool TcpServer::listen(const int port)
{
    if( ! _server.listen( QHostAddress::Any, port ) ){
#ifdef DEBUG_OUTPUT
        qCritical() << "Unable to start listen on port `" << port << "`: "
                    << _server.errorString();
#endif
        _server.close();
        return false;
    }
    return true;
}
