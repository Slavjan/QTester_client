#include "rootwindow.h"
#include "apitestwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ApiTestWindow w;
  w.show();

  return a.exec();
}
