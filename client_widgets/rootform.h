#ifndef ROOTFORM_H
#define ROOTFORM_H

#include <QWidget>
#include <QDialog>
#include "networkquerymanager.h"
#include "jsonparser.h"

typedef QMap<QString, QString> IdTitleMap;

namespace Ui {
  class RootForm;
}

class RootForm : public QDialog // то из-зи этого получается неведомая хрень
{
  Q_OBJECT
private:
  Ui::RootForm *ui;

  NetworkQueryManager *_netMan;
  JsonParser *_parser; // если сделать так


public:
  explicit RootForm(QWidget *parent = 0);
  ~RootForm();
//  NetworkQueryManager *_netMan;
//  JsonParser _jParser;

  void setProfList(IdTitleMap profList);

  NetworkQueryManager *netMan() const;
  void setNetMan(NetworkQueryManager *netMan);
//  JsonParser jParser() const;
//  void setJParser(JsonParser jParser);
};

#endif // ROOTFORM_H
