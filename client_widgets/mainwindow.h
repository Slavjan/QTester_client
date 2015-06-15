#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "jsonparser.h"
#include "networkquerymanager.h"

namespace Ui {
  class MainWindow;
}
namespace PageIndex{
  enum PageIndex{Start = 0, Login = 1};
}

class AurizationWindow : public QDialog
{
  Q_OBJECT

private:
  Ui::MainWindow *ui;

  static QString getUserLogin();//пусть остается
public:

  explicit AurizationWindow(QWidget *parent = 0);
  ~AurizationWindow();

private slots:// чё тут будет не могу додуматься
  void authorisation(const QString &token, const QString &fullName);

  void on_PButton_Start_BeginTest_clicked();
  void setProfs(IdTitleMap profList);
};

#endif // MAINWINDOW_H
