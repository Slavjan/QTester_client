#include "apitestwindow.h"
#include "ui_apitestwindow.h"

#include <QDesktopWidget>
#include <QMenu>
#include <QMessageBox>
#include <QScreen>
#include <QSpinBox>

namespace DefaultValues {
    const QString HOST = "localhost";
    const int     PORT = 3434;
}

ApiTestWindow::ApiTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ApiTestWindow)
{
    ui->setupUi(this);
    QSettings cfg;

    _requests = cfg.value( Settings::REQUESTS ).toStringList();
    ui->LineEdit_Request->setCompleter( & _requestCompleter );


    _requestsModel.setStringList( _requests );
    _requestCompleter.setModel( & _requestsModel );

    _client = new TcpClient( DefaultValues::HOST, DefaultValues::PORT, this );

    connect( _client, SIGNAL( dataRecieved( QString ) ),
             ui->PlainTextEdit_Reply, SLOT( setPlainText(QString) ) );
    connect( _client, SIGNAL( connectedSuccess() ),
             this,    SLOT( connectedSuccess() ) );
    connect( _client, SIGNAL( errorDataRecieved(QString) ),
             this,    SLOT( connectionError(QString) ) );
}

ApiTestWindow::~ApiTestWindow()
{
    delete ui;
}

void ApiTestWindow::connectedSuccess()
{
    ui->PButton_Send->setEnabled( true );
}

void ApiTestWindow::connectionError(const QString &errorMessage)
{
    ui->PButton_Send->setDisabled( true );
    QMessageBox::critical(this, tr("Critical"), errorMessage);
}

void ApiTestWindow::addTab()
{
    QWidget *content = new QWidget;
    QHBoxLayout *hostPortLay = new QHBoxLayout;
    QGridLayout *center = new QGridLayout;

    auto connectFrame = new QFrame;
    connectFrame->setMaximumSize( 240, 80 );
    content->setLayout( center );

    auto host = new QLineEdit( DefaultValues::HOST );
    host->setPlaceholderText( tr("Host") );
    auto port = new QSpinBox;
    port->setMaximum( 9999 );
    port->setMinimum( 0 );
    port->setValue( DefaultValues::PORT );
    hostPortLay->addWidget( host );
    hostPortLay->addWidget( port );

    auto btnConnect = new QPushButton( tr("&Connect") );
    auto hostport_btnLay = new QVBoxLayout;
    hostport_btnLay->addLayout( hostPortLay );
    hostport_btnLay->addWidget( btnConnect );
    connectFrame->setLayout( hostport_btnLay );

    center->addWidget( connectFrame,  0, 0 );

    _tabsContent.push_back( content );
    ui->TabWidget->addTab( content, host->text() );
}

void ApiTestWindow::on_PButton_Send_clicked()
{
    QString request = ui->LineEdit_Request->text();

    if( ! _requests.contains( request ) ){
        _requests.append( request );
        _requestsModel.setStringList( _requests );

        QSettings cfg;
        cfg.setValue( Settings::REQUESTS, _requests );
    }

    _client->sendToServer( request );
}

void ApiTestWindow::on_PButton_Connect_clicked()
{
    _client->connectToServer( DefaultValues::HOST , DefaultValues::PORT );
}

void ApiTestWindow::on_TabWidget_tabBarDoubleClicked(int index)
{
    qDebug() << "Clicked by index: " << index;
}

void ApiTestWindow::on_TabWidget_tabCloseRequested(int index)
{
    ui->TabWidget->removeTab( index );
    _tabsContent.removeAt( index );
}

void ApiTestWindow::on_PButton_NewTab_clicked()
{
    addTab();
}

void ApiTestWindow::on_LineEdit_Request_returnPressed()
{
    on_PButton_Send_clicked();
}

void ApiTestWindow::on_actionRemove_From_Completion_triggered()
{
    qDebug() << "Remove completion";
    QString request = ui->LineEdit_Request->text();

    if( _requests.contains( request ) ){
        _requests.removeOne( request );
        _requestsModel.setStringList( _requests );
        QSettings cfg;
        cfg.setValue( Settings::REQUESTS, _requests );

        qDebug() << "Request removed from completeon: \n    " << request;
    }
}

void ApiTestWindow::on_LineEdit_Request_customContextMenuRequested(const QPoint &pos)
{
    emit ui->actionRemove_From_Completion->triggered();
}
