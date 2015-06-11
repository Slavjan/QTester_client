#ifndef UISETTER_H
#define UISETTER_H

#include <QObject>
#include <QQmlContext>

class UiSetter : public QObject
{
  Q_OBJECT
  QQmlContext *_root;
public:
  explicit UiSetter(QQmlContext *root, QObject *parent = 0);

signals:

public slots:
  void setFullName( QString fullName );
  void setLogin( QString login );
};

#endif // UISETTER_H
