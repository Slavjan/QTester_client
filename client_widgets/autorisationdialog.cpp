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
  connect( _jParser, SIGNAL(authSignalPars(QString,QString, int)),
           this, SLOT(authorisation(QString,QString, int)) );
}

AutorisationDialog::~AutorisationDialog()
{
  delete ui;
}

void AutorisationDialog::authorisation( const QString &token, const QString &fullName, int userGroup )
{
  qDebug() << "Auth";
  ui->ComboBox_Auth_User->clear();

  switch( userGroup )
  {
  case userGroups::Admin:
      ui->PButton_Auth_Admin->setText(tr("Administration"));
      ui->PButton_Auth_Admin->setVisible(true);
      break;
  case userGroups::Prepod:
      ui->PButton_Auth_Admin->setText(tr("Questions redaction"));
      ui->PButton_Auth_Admin->setVisible(true);
      break;
  case userGroups::Student:
      ui->PButton_Auth_Admin->setVisible(false);
      break;
  default:
      ui->PButton_Auth_Admin->setVisible(false);
      break;
  }

  setGroupId(userGroup);
  ui->ComboBox_Auth_User->addItem(fullName, token);
  ui->ComboBox_Auth_User->addItem( tr("Change user..."), -1 );
  ui->stackedWidget->setCurrentIndex( PageIndex::AuthForm::Auth );
}


int AutorisationDialog::groupId() const
{
    return _groupId;
}

void AutorisationDialog::setGroupId(int groupId)
{
    _groupId = groupId;
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


void AutorisationDialog::on_PButton_Auth_Login_clicked()
{
    QString login = ui->LEdit_Login_Login->text(),
            password = ui->LEdit_Login_Password->text();

    _netMan->authorisation(login, password);

    connect( _jParser, SIGNAL( authSignalPars( QString, QString, int ) ),
             this, SLOT( authorisation( QString, QString, int ) ) );
}

void AutorisationDialog::on_PButton_Auth_Admin_clicked()
{
  //  emit authAdmin( groupId() );
   close();

}
