#include "rootform.h"
#include "ui_rootform.h"


//NetworkQueryManager *RootForm::netMan() const
//{
//  return _netMan;
//}

//void RootForm::setNetMan(NetworkQueryManager *netMan)
//{
//  _netMan = netMan;
//}

//JsonParser RootForm::jParser() const
//{
//  return _jParser;
//}

//void RootForm::setJParser(JsonParser jParser)
//{
//  _jParser = jParser;
//}
RootForm::RootForm(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::RootForm)
{
  ui->setupUi(this);
}

RootForm::~RootForm()
{
  delete ui;
}

void RootForm::setProfList(IdTitleMap profList)
{
  ui->ComboBox_Config_Profession->clear();

  for (auto it = profList.begin(); it != profList.end(); ++it) {
    ui->ComboBox_Config_Profession->addItem(it.value(), it.key());
  }
}


