#include "form.h"

#include "mainwindow.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent), ui(new Ui::Form), m_doubleValidator(1, 50, 2, this) {
  ui->setupUi(this);

#define MIN_HEIGHT 426
#define MAX_HEIGHT 1000

  ui->tableWidget->horizontalHeader()->resizeSection(0, 120);
  ui->tableWidget->horizontalHeader()->resizeSection(1, 200);
  ui->tableWidget->horizontalHeader()->resizeSection(2, 150);
  ui->tableWidget->horizontalHeader()->resizeSection(3, 120);
  ui->amount->setValidator(new QDoubleValidator());
  ui->count->setValidator(&m_doubleValidator);
  ui->Percent->setValidator(new QDoubleValidator());
  this->setMinimumHeight(MIN_HEIGHT);
  this->setMaximumHeight(MIN_HEIGHT);
}

Form::~Form() {
  delete ui;
  m_doubleValidator.setNotation(QDoubleValidator::StandardNotation);
}

double Form::Annuity(double amount, double percent, int count) {
  double result = (amount * (percent / (12 * 100)) /
                   (1 - pow(1 + percent / (12 * 100), -count)));
  return result;
}

double Form::Difference(double amount, int count) {
  double result = amount / count;
  return result;
}

void Form::CreditAnnuityPayment(double amount, double percent, int count) {
  double overpay = 0;
  double osndolg = 0;
  double percentpay = 0;
  double ostatok = amount;
  if (ui->countMY->currentText() == "Лет") {
    count *= 12;
  }
  if (ui->Annuity->isChecked()) {
    percentpay = ostatok * ((percent * 0.01) / 12);
    double monthlypay = Annuity(amount, percent, count);
    overpay = monthlypay * count - amount;
    double FinalResPay = overpay + amount;
    QString monthpayvalue = QString::number(monthlypay, 'f', 3);
    QString overpayvalue = QString::number(overpay, 'f', 3);
    QString overpayplusamount = QString::number(FinalResPay, 'f', 3);
    ui->AddedPercentResult->setText(overpayvalue);
    ui->AmountPlusPercentsResult->setText(overpayplusamount);
    ui->MonthlyPayResult->setText(monthpayvalue);
    for (int i = 0; i <= count; i++) {
      ui->tableWidget->insertRow(i);
      ostatok = ostatok - osndolg;
      percentpay = ostatok * ((percent * 0.01) / 12);
      osndolg = monthlypay - percentpay;
      QTableWidgetItem *mp = new QTableWidgetItem(QString::number(monthlypay));
      ui->tableWidget->setItem(i, 0, mp);
      QTableWidgetItem *mainpay =
          new QTableWidgetItem(QString::number(osndolg));
      ui->tableWidget->setItem(i, 1, mainpay);
      QTableWidgetItem *pp = new QTableWidgetItem(QString::number(percentpay));
      ui->tableWidget->setItem(i, 2, pp);
      QTableWidgetItem *remainder =
          new QTableWidgetItem(QString::number(ostatok));
      ui->tableWidget->setItem(i, 3, remainder);
    }
  }
}

void Form::CreditDifferencePayment(double amount, double percent, int count) {
  double monthlypay = 0;
  double percentpay = 0;
  double finalpay = 0;
  double ostatok = amount;
  if (ui->countMY->currentText() == "Лет") {
    count *= 12;
  }
  if (ui->Differencity->isChecked()) {
    double mainpay = Difference(amount, count);
    for (int i = 0; i < count; i++) {
      ui->tableWidget->insertRow(i);
      monthlypay = mainpay + (amount - mainpay * i) * (percent * 0.01) / 12;
      percentpay = ostatok * ((percent * 0.01) / 12);
      finalpay = monthlypay + percentpay;
      ostatok = ostatok - mainpay;
      QTableWidgetItem *mp = new QTableWidgetItem(QString::number(monthlypay));
      ui->tableWidget->setItem(i, 0, mp);
      QTableWidgetItem *Mainp = new QTableWidgetItem(QString::number(mainpay));
      ui->tableWidget->setItem(i, 1, Mainp);
      QTableWidgetItem *pp = new QTableWidgetItem(QString::number(percentpay));
      ui->tableWidget->setItem(i, 2, pp);
      QTableWidgetItem *remainder =
          new QTableWidgetItem(QString::number(ostatok));
      ui->tableWidget->setItem(i, 3, remainder);
    }
    double monthlypayfirst =
        mainpay + (amount - mainpay * 0) * (percent * 0.01) / 12;
    double monthlypaylast =
        mainpay + (amount - mainpay * count) * (percent * 0.01) / 12;
    QString monthpayvalue = QString::number(monthlypayfirst, 'f', 3);
    QString monthpayvalue1 = QString::number(monthlypaylast, 'f', 3);
    ui->MonthlyPayResult->setText(monthpayvalue + " ...");
    ui->maxpayvalue->setText(monthpayvalue1);
    double overpay = monthlypay * count - amount;
    QString overpayvalue = QString::number(overpay, 'f', 3);
    ui->AddedPercentResult->setText(overpayvalue);
    double FinalResPay = overpay + amount;
    QString overpayplusamount = QString::number(FinalResPay, 'f', 3);
    ui->AmountPlusPercentsResult->setText(overpayplusamount);
  }
}

void Form::on_calculate_clicked() {
  QString amount = ui->amount->text().toStdString().data();
  QString percent = ui->Percent->text().toStdString().data();
  QString count = ui->count->text().toStdString().data();
  if (ui->Annuity->isChecked()) {
    CreditAnnuityPayment(amount.toDouble(), percent.toDouble(), count.toInt());
  }
  this->setMinimumHeight(MAX_HEIGHT);
  this->setMaximumHeight(MAX_HEIGHT);
  if (ui->Differencity->isChecked()) {
    CreditDifferencePayment(amount.toDouble(), percent.toDouble(),
                            count.toInt());
  }
}
