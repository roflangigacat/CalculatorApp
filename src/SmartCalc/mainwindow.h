#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qcustomplot.h>
#include <string.h>

#include <QAction>
#include <QApplication>
#include <QDesktopServices>
#include <QDoubleValidator>
#include <QMainWindow>
#include <QPainter>
#include <QTextCursor>
#include <QTimer>
#include <QVector>
#include <QWidget>
#include <QtMath>
#include <iostream>

#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SmartCalc;
}
QT_END_NAMESPACE

class SmartCalc : public QMainWindow {
  Q_OBJECT

public:
  SmartCalc(QWidget *parent = nullptr);
  ~SmartCalc();
  void clearData();
  void plot();

private slots:

private:
  Ui::SmartCalc *ui;
  Form *zxc;
  bool triggered;
  void trigger();
  QVector<double> vec_x, vec_y;
  double xBegin, xEnd, h, X1;
  int N;

private slots:
  void digits_numbers();
  void on_button_dot_clicked();
  void operations();
  void functions();
  void on_button_clean_clicked();
  void on_button_equal_clicked();
  void on_Plot_clicked();
  void on_GraphCreate_clicked();
  void on_GraphClear_clicked();
  void on_CreditCalc_triggered();
  void on_instruction_triggered();
  void on_button_divide_clicked();
  void on_button_mult_clicked();
  void on_button_mod_clicked();
};

#endif // MAINWINDOW_H
