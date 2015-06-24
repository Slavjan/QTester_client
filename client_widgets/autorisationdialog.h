#ifndef AUTORISATIONDIALOG_H
#define AUTORISATIONDIALOG_H

#include <QDialog>
#include "jsonparser.h"
#include "networkquerymanager.h"

namespace Ui {
  class AutorisationDialog;
}

namespace PageIndex
{
    namespace AuthForm
    {   
        enum PageIndex
        {
            Auth = 0, Login = 1
        };
    }
}

class AutorisationDialog : public QDialog
{
  Q_OBJECT
private:
  Ui::AutorisationDialog *ui;

  JsonParser *_jParser;
  NetworkQueryManager *_netMan;

  int _groupId;

  QString getUserLogin();
public:
  explicit AutorisationDialog(NetworkQueryManager *netMan, JsonParser *jParser, QWidget *parent = 0);
  ~AutorisationDialog();

  int groupId() const;
  void setGroupId(int groupId);

private slots:
  void authorisation(const QString &token, const QString &fullName, int userGroup);

  void on_PButton_Auth_Begin_clicked();
  void on_AutorisationDialog_rejected();
  void on_PButton_Auth_Login_clicked();
  void on_PButton_Auth_Admin_clicked();

//signals:
    //void authAdmin( int );
};

#endif // AUTORISATIONDIALOG_H
