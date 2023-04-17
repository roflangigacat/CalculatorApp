#include "form.h"

#include <QDoubleValidator>

#include "ui_form.h"

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form) {
  ui->setupUi(this);

  myplayer = new QMediaPlayer;
  audioOut = new QAudioOutput;

  QPixmap pix(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/PULYA.jpg");
  ui->pic_2->setPixmap(pix);
  ui->tableWidget->horizontalHeader()->resizeSection(0, 568);
  ui->amount->setValidator(new QDoubleValidator());
  ui->days->setValidator(new QIntValidator());
}

Form::~Form() { delete ui; }

void Form::creditarmeniancalc(int days) {
  int kvartira = 0;
  for (int i = 0; i <= days; i++) {
    kvartira = i + 1;
    ui->tableWidget->insertRow(i);
    QTableWidgetItem *mp =
        new QTableWidgetItem(QString::number(kvartira) + " Квартир");
    ui->tableWidget->setItem(i, 0, mp);
  }
  ui->tableWidget->insertRow(days + 1);
  QTableWidgetItem *ml = new QTableWidgetItem("ДОЖЕН КВАРТИР");
  ui->tableWidget->setItem(days + 1, 0, ml);
}

void Form::on_result_clicked() {
  QString stepan = ui->days->text();
  creditarmeniancalc(stepan.toInt());
  myplayer->setAudioOutput(audioOut);
  myplayer->setSource(QUrl::fromLocalFile(
      "/Users/tandrasc/CalculatorApp/src/ArmenianCounter/TA.wav"));
  audioOut->setVolume(50);
  myplayer->play();
}
