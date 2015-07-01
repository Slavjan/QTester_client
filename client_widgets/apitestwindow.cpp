#include "apitestwindow.h"
#include "ui_apitestwindow.h"

ApiTestWindow::ApiTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ApiTestWindow)
{
    ui->setupUi(this);

//    _jParser = JsonParser::instance( this );
//    _netMan = new NetworkQueryManager( "127.0.0.1", 3434 );
    _client = new TcpClient("localhost", 3434, this);

    connect( _client, SIGNAL( dataRecieved( QString ) ),
             ui->PlainTextEdit_Reply, SLOT( setPlainText(QString) ) );
    //pull requests
//    // profList
//    connect( _jParser, SIGNAL( takeProfsList( IdTitleMap ) ),
//             this, SLOT( setProfs( IdTitleMap ) ) );

//    connect( _jParser, SIGNAL( authSignalPars( QString, QString, int ) ),
//             this, SLOT( authAdmin( QString, QString, int ) ) );
}

ApiTestWindow::~ApiTestWindow()
{
    delete ui;
}

void ApiTestWindow::on_PButton_Send_clicked()
{
    QString request = ui->LineEdit_Request->text();

    _client->sendToServer( request );
}
