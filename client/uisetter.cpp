#include "uisetter.h"

UiSetter::UiSetter(QQmlContext *root, QObject *parent) : QObject(parent)
{
  _root = root;
}

void UiSetter::setFullName(QString fullName)
{
  _root->setContextProperty("fullName", fullName);

}

void UiSetter::setLogin(QString login)
{
   _root->setContextProperty("username", login);
}

