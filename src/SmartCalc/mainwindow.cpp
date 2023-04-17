#include "mainwindow.h"

#include "form.h"
#include "ui_mainwindow.h"

#define MAX_WIDTH 1076
#define MIN_WIDTH 510

extern "C" {
#include "../SmartCalc.h"
}
SmartCalc::SmartCalc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartCalc) {
  ui->setupUi(this);
  zxc = nullptr;

  triggered = false;
  //  ui->result->setReadOnly(true);
  QString begin = ui->Xspinmin->text();
  QString end = ui->Xspin->text();
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");

  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);

  this->setMinimumWidth(MIN_WIDTH);
  this->setMaximumWidth(MIN_WIDTH);

  ui->XDigit->setValidator(new QDoubleValidator());
  connect(ui->button_zero, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_one, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_two, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_three, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_four, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_five, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_six, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_seven, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_eight, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_nine, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->button_plus, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->button_minus, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->button_X, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->button_pow, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->open, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->close, SIGNAL(clicked()), this, SLOT(operations()));

  connect(ui->button_asin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->button_acos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->button_atan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->button_sin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->button_cos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->button_tan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->button_sqrt, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->button_ln, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->button_log, SIGNAL(clicked()), this, SLOT(functions()));
}

SmartCalc::~SmartCalc() {
  delete zxc;
  delete ui;
}

void SmartCalc::trigger() { triggered = !triggered; }

void SmartCalc::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString numbers;
  numbers = button->text();
  ui->result->insert(numbers);
}

void SmartCalc::on_button_dot_clicked() {
  if (!(ui->result->text().contains('.')))
    ui->result->setText(ui->result->text() + ".");
}

void SmartCalc::operations() {
  QPushButton *button = (QPushButton *)sender();
  QString numbers;
  numbers = button->text();
  ui->result->insert(numbers);
}

void SmartCalc::functions() {
  QPushButton *button = (QPushButton *)sender();
  int stepan = ui->result->cursorPosition();
  QString sendertext = button->text() + "()";
  int senderlength = sendertext.length();
  ui->result->insert(sendertext);
  ui->result->setCursorPosition(stepan + senderlength - 1);
}

void SmartCalc::on_button_clean_clicked() { ui->result->setText(""); }

void SmartCalc::on_button_equal_clicked() {
  QString str = ui->result->text();
  QString x_str = ui->XDigit->text();
  ui->result->setText(
      QString::number(calculate(str.toStdString().data(), x_str.toDouble())));
}

void SmartCalc::on_Plot_clicked() {
  if (triggered == false) {
    this->setMinimumWidth(MAX_WIDTH);
  } else {
    this->setMinimumWidth(MIN_WIDTH);
    this->setMaximumWidth(MIN_WIDTH);
#ifdef __APPLE__
    this->setGeometry(this->x(), this->y() + 28, MIN_WIDTH, this->height());
#elif
    this->setGeometry(this->x(), this->y(), MIN_WIDTH, this->height());
#endif
  }
  trigger();
}

void SmartCalc::clearData() {
  vec_x.clear();
  vec_y.clear();
}

void SmartCalc::on_GraphCreate_clicked() {
  clearData();
  QString begin = ui->Xspinmin->text();
  QString end = ui->Xspin->text();
  ui->widget->xAxis->setRange(-end.toDouble(), end.toDouble());
  ui->widget->yAxis->setRange(begin.toDouble() - 1, end.toDouble() * 2 + 1);
  h = 0.1;
  xBegin = begin.toDouble();
  xEnd = end.toDouble() + h;

  N = (xEnd - xBegin) / h + 2;

  for (X1 = xBegin; X1 <= xEnd; X1 += h) {
    vec_x.push_back(X1);
    vec_y.push_back(calculate(ui->result->text().toStdString().data(), X1));
  }
  ui->widget->clearGraphs();
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(vec_x, vec_y);
  ui->widget->replot();
}

void SmartCalc::on_GraphClear_clicked() {
  clearData();
  ui->widget->graph(0)->setData(vec_x, vec_y);
  ui->widget->replot();
  ui->widget->update();
}

void SmartCalc::on_CreditCalc_triggered() {
  if (zxc == nullptr) {
    zxc = new Form;
  }
  zxc->show();
}

void SmartCalc::on_instruction_triggered() {
  QDesktopServices::openUrl(
      QUrl("file:/Users/tandrasc/C7_SmartCalc_v1.0-0/UserGuide/ins.html",
           QUrl::TolerantMode));
}

void SmartCalc::on_button_divide_clicked() { ui->result->insert("/"); }

void SmartCalc::on_button_mult_clicked() { ui->result->insert("*"); }

void SmartCalc::on_button_mod_clicked() { ui->result->insert("%"); }
