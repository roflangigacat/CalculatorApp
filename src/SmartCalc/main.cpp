#include <QApplication>

#include "form.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  SmartCalc w;
  w.show();
  return a.exec();
}
