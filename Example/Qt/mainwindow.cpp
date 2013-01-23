#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTextCodec"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MixerInVolume.LinkToDevice(std::string("default"));
    QTextCodec *strconvert=QTextCodec::codecForLocale();
    ui->labelNameDevice->setText(strconvert->toUnicode(MixerInVolume.GetNameOfLinkedDevice().c_str()));
    startTimer(25);
    double vol=MixerInVolume.GetVolume();
    int delta=ui->horizontalSlider->maximum()-ui->horizontalSlider->minimum();
    int value=(int)(vol*(double)delta)+ui->horizontalSlider->minimum();
    ui->horizontalSlider->setValue(value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    double vol=MixerInVolume.GetVolume();
    ui->labelVolume->setText(QString().sprintf("%e",vol));
    bool muteoff=MixerInVolume.IsMuteOff();
    ui->checkBox->setCheckState(muteoff?Qt::Unchecked:Qt::Checked);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    int delta=ui->horizontalSlider->maximum()-ui->horizontalSlider->minimum();
    MixerInVolume.SetVolume((double)(value-ui->horizontalSlider->minimum())/(double)(delta));

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    switch(arg1){
    case Qt::Checked:
        MixerInVolume.MuteOff(false);
        break;
    case Qt::Unchecked:
        MixerInVolume.MuteOff(true);
        break;
    }
}
