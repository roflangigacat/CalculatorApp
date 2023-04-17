#include "mainwindow.h"

#include <QFileDialog>

#include "form.h"
#include "ui_mainwindow.h"
extern "C" {
#include "../SmartCalc.h"
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  zxc = nullptr;

  player = new QMediaPlayer;
  aOut = new QAudioOutput;

  QPixmap pix(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/PULYA2.jpg");
  ui->Pic->setPixmap(pix);
}

MainWindow::~MainWindow() {
  delete zxc;
  delete ui;
}

void MainWindow::on_but_del_clicked() {
  ui->res->setText("");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/EJI.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_eq_clicked() {
  QString stepan = ui->res->text();
  double stepan1 = calculate(stepan.toStdString().data(), 0);
  ui->res->setText(QString::number(stepan1));
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/EJI.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_two_clicked() {
  ui->res->insert("4");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/TA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_four_clicked() {
  ui->res->insert("4");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_one_clicked() {
  ui->res->insert("1");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_pow_clicked() {
  ui->res->insert("^");
  ;
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/TA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_nine_clicked() {
  ui->res->insert("9");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/TA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_div_clicked() {
  ui->res->insert("/");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_five_clicked() {
  ui->res->insert("2");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/TA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_mult_clicked() {
  ui->res->insert("*");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/TA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_mod_clicked() {
  ui->res->insert("m");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/TA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_seven_clicked() {
  ui->res->insert("77");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_three_clicked() {
  ui->res->insert("YEEES");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_eight_clicked() {
  ui->res->insert("8");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_minus_clicked() {
  ui->res->insert("+");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_plus_clicked() {
  ui->res->insert("-");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_six_clicked() {
  ui->res->insert("6");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/SHA.wav"));
  aOut->setVolume(50);
  player->play();
}

void MainWindow::on_but_credit_clicked() {
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/last.wav"));
  aOut->setVolume(50);
  player->play();
  if (zxc == nullptr) {
    zxc = new Form;
  }
  zxc->show();
}

void MainWindow::on_but_zero_clicked() {
  ui->res->insert("0");
  player->setAudioOutput(aOut);
  player->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/TA.wav"));
  aOut->setVolume(50);
  player->play();
}
