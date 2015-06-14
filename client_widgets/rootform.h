#ifndef ROOTFORM_H
#define ROOTFORM_H

#include <QWidget>
#include <QDialog>
typedef QMap<QString, QString> IdTitleMap;

namespace Ui {
  class RootForm;
}

class RootForm : public QDialog
{
  Q_OBJECT

public:
  explicit RootForm(QWidget *parent = 0);
  ~RootForm();


  void setProfList(IdTitleMap profList);
private:
  Ui::RootForm *ui;
};

#endif // ROOTFORM_H
