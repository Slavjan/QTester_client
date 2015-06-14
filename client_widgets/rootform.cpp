#include "rootform.h"
#include "ui_rootform.h"

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
