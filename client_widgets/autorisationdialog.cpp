#include "autorisationdialog.h"
#include "ui_autorisationdialog.h"
#include <QDir>

AutorisationDialog::AutorisationDialog(NetworkQueryManager *netMan, JsonParser *jParser, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AutorisationDialog)
{
  ui->setupUi(this);
  ui->stackedWidget->setCurrentIndex( PageIndex::AuthForm::Login );
  _netMan = netMan;
  _jParser = jParser;

  _netMan->authorisation(getUserLogin(), "111");

  //autorisation
  connect( _jParser, SIGNAL(authSignalPars(QString,QString)),
           this, SLOT(authorisation(QString,QString)) );
}

AutorisationDialog::~AutorisationDialog()
{
  delete ui;
}

void AutorisationDialog::authorisation(const QString &token, const QString &fullName)
{
  qDebug() << "Auth";
  ui->ComboBox_Auth_User->clear();
  ui->ComboBox_Auth_User->addItem(fullName, token);
  ui->ComboBox_Auth_User->addItem( tr("Change user..."), -1 );
  ui->stackedWidget->setCurrentIndex( PageIndex::AuthForm::Auth );
}

QString AutorisationDialog::getUserLogin()
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

void AutorisationDialog::on_PButton_Auth_Begin_clicked()
{
    close();
}

void AutorisationDialog::on_AutorisationDialog_rejected()
{
    
}
