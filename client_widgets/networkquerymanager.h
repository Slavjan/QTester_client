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
    
    void sendPullRequestProfList();
    void sendPullRequestLessonsList( const QString &profId );
    void sendPullRequestThemesList( const QString &lessonId );
    void sendPullRequestQuestions( const QString &themeId, qint64 questionsCount, qint64 answersCount );
signals:
    void dataRecieved( QString );

public:
    NetworkQueryManager(const QString &host, const int port);
    ~NetworkQueryManager();

    TcpClient* getClient();
};
                
namespace reqLists
{
    const QString auth = "/auth";
    const QString get = "/get";      
    const QString profList = "profList";
    const QString lessonsList = "lessonsList";
    const QString themesList = "themesList";
    const QString questions = "questions";
}
