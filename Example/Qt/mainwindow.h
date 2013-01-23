#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MixerMicrophoneValue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void timerEvent(QTimerEvent * event);
private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    MixerMicrophoneValue MixerInVolume;
};

#endif // MAINWINDOW_H
