#ifndef FORM_H
#define FORM_H

#include <QAudioOutput>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QUrl>
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();

private slots:
  void on_result_clicked();

private:
  Ui::Form *ui;
  QMediaPlayer *myplayer;
  QAudioOutput *audioOut;
  void creditarmeniancalc(int days);
};

#endif // FORM_H
