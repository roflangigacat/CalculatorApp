#ifndef FORM_H
#define FORM_H
#include <QAction>
#include <QApplication>
#include <QDoubleValidator>
#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QVector>
#include <QWidget>
#include <QtMath>
#include <iostream>

namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();

private:
  Ui::Form *ui;
  QDoubleValidator m_doubleValidator;

private slots:
  double Annuity(double amount, double percent, int count);
  double Difference(double amount, int count);
  void CreditAnnuityPayment(double amount, double percent, int count);
  void CreditDifferencePayment(double amount, double percent, int count);
  void on_calculate_clicked();
};

#endif // FORM_H
