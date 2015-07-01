#ifndef APITESTWINDOW_H
#define APITESTWINDOW_H

#include <QMainWindow>

#include "networkquerymanager.h"
#include "jsonparser.h"
#include "tcpclient.h"

#include <QList>
#include <QCompleter>
#include <QStringListModel>

#include <QSettings>
#include <QPoint>

namespace Ui {
    class ApiTestWindow;
}

namespace Settings {
    const QString REQUESTS = "requests";
}

class ApiTestWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::ApiTestWindow *ui;

    QList<QWidget*>  _tabsContent;
    QStringList      _requests;
    QStringListModel _requestsModel;

    QCompleter _requestCompleter;

    TcpClient *_client;

public:
    explicit ApiTestWindow(QWidget *parent = 0);
    ~ApiTestWindow();

private slots:
    void connectedSuccess();
    void connectionError( const QString &errorMessage );
    void addTab();

private slots:
    void on_PButton_Send_clicked();
    void on_PButton_Connect_clicked();
    void on_TabWidget_tabBarDoubleClicked(int index);
    void on_TabWidget_tabCloseRequested(int index);
    void on_PButton_NewTab_clicked();
    void on_LineEdit_Request_returnPressed();
    void on_actionRemove_From_Completion_triggered();
    void on_LineEdit_Request_customContextMenuRequested(const QPoint &pos);
};

#endif // APITESTWINDOW_H
