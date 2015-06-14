#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "rootform.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->stackedWidget->setCurrentIndex( PageIndex::Login );

  // Определить логин
  QString UserLogin = getUserLogin();
  _netMan = new NetworkQueryManager("127.0.0.1", 3434);

  _netMan->authorisation(UserLogin, "111");

  connect( _netMan->getClient(), SIGNAL(dataRecieved(QString)),
           &_parser, SLOT(responseSlot(QString)) );

  connect( &_parser, SIGNAL(authSignalPars(QString,QString)),
           this, SLOT(authorisation(QString,QString)) );


  // Отправка запроса на логин
  // Прием ответа о логине
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::authorisation(const QString &token, const QString &fullName)
{
  qDebug() << "Auth";
  ui->ComboBox_Start_User->clear();
  ui->ComboBox_Start_User->addItem(fullName, token);
  ui->ComboBox_Start_User->addItem( tr("Change user..."), -1 );
  ui->stackedWidget->setCurrentIndex( PageIndex::Start );
}

QString MainWindow::getUserLogin()
{
    //* Variant #1 : simple
    return QDir().home().dirName();
    // */
    /* Variant #2
    QString name;
    name = qgetenv(“USER”); // get the user name in Linux
    if( name.isEmpty() ){
    name = qgetenv(“USERNAME”); // get the name in Windows
    }
    // */
    //* Variant #3
    // google it: http://qt-project.org/forums/viewthread/11951
    // */
}

void MainWindow::on_PButton_Start_BeginTest_clicked()
{
  _netMan->sendPullRequestProfList();
  connect(&_parser, SIGNAL(takeProfs(IdTitleMap)),
          this, SLOT(setProfs(IdTitleMap)));
}

void MainWindow::setProfs(IdTitleMap profList)
{
//  this->hide();
  qDebug() << "setProfs";
  RootForm *form = new RootForm(this);
  form->setProfList( profList );
  form->exec();
}
