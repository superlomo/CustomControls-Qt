#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "RoundProgressBar/roundprogressbar.h"
#include "LEDNumber/LedNumber.h"
#include "Loading/Loading.h"

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //********************************
    RoundProgressBar* bar1;
    RoundProgressBar* bar2;

    //********************************
    LEDNumber* num1;
    LEDNumber* num2;
    QTimer timer;
    //********************************
    Loading* loading1;
    Loading* loading2;

private slots:
    void setText();
};

#endif // MAINWINDOW_H
