#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jsonparser.h"
#include "networkquerymanager.h"

namespace Ui {
  class MainWindow;
}
namespace PageIndex{
  enum PageIndex{Start = 0, Login = 1};
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
  Ui::MainWindow *ui;
  NetworkQueryManager *_netMan;
  JsonParser _parser;

  static QString getUserLogin();
public:

  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void authorisation(const QString &token, const QString &fullName);

  void on_PButton_Start_BeginTest_clicked();
  void setProfs(IdTitleMap profList);
};

#endif // MAINWINDOW_H
