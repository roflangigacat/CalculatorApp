#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAudioOutput>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QUrl>

#include "form.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

class QMediaPlayer;

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_but_del_clicked();

  void on_but_eq_clicked();

  void on_but_two_clicked();

  void on_but_four_clicked();

  void on_but_one_clicked();

  void on_but_pow_clicked();

  void on_but_nine_clicked();

  void on_but_div_clicked();

  void on_but_five_clicked();

  void on_but_mult_clicked();

  void on_but_mod_clicked();

  void on_but_seven_clicked();

  void on_but_three_clicked();

  void on_but_eight_clicked();

  void on_but_minus_clicked();

  void on_but_plus_clicked();

  void on_but_six_clicked();

  void on_but_credit_clicked();

  void on_but_zero_clicked();

private:
  Ui::MainWindow *ui;
  Form *zxc;
  QMediaPlayer *player;
  QAudioOutput *aOut;
};
#endif // MAINWINDOW_H
