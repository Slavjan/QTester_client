#ifndef APITESTWINDOW_H
#define APITESTWINDOW_H

#include <QMainWindow>

#include "networkquerymanager.h"
#include "jsonparser.h"
#include "tcpclient.h"

namespace Ui {
    class ApiTestWindow;
}

class ApiTestWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::ApiTestWindow *ui;

//    NetworkQueryManager *_netMan;
//    JsonParser *_jParser;
    TcpClient *_client;

public:
    explicit ApiTestWindow(QWidget *parent = 0);
    ~ApiTestWindow();
private slots:
    void on_PButton_Send_clicked();
};

#endif // APITESTWINDOW_H
