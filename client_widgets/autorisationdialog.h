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

  QString getUserLogin();
public:
  explicit AutorisationDialog(NetworkQueryManager *netMan, JsonParser *jParser, QWidget *parent = 0);
  ~AutorisationDialog();

private slots:
  void authorisation(const QString &token, const QString &fullName);

  void on_PButton_Auth_Begin_clicked();
};

#endif // AUTORISATIONDIALOG_H
