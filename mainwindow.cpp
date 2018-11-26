#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //*********************** RoundProgressBar ************************
    bar1=new RoundProgressBar(this);
    bar1->setOutterBarWidth(20);
    bar1->setInnerBarWidth(20);
    bar1->setControlFlags(RoundProgressBar::all);

    bar2=new RoundProgressBar(this);
    bar2->setInnerDefaultTextStyle(RoundProgressBar::valueAndMax);
    bar2->setOutterBarWidth(8);
    bar2->setInnerBarWidth(20);
    bar2->setOutterColor(QColor(250,250,240));
    bar2->setDefaultTextColor(QColor(255,190,57));
    bar2->setInnerColor(QColor(255,190,57),QColor(255,230,129));
    bar2->setControlFlags(RoundProgressBar::all);
    ui->gridLayout->addWidget(bar1,0,0);
    ui->gridLayout->addWidget(bar2,0,1);

    //*********************** LEDNumber ************************
    num1=new LEDNumber(this);
    num2=new LEDNumber(this);
    num2->setBackColor(QColor(255,85,85));
    num2->setLineColor(QColor(250,250,250));
    num2->setFrontColor(QColor(50,50,50));
    ui->gridLayout_3->addWidget(num1,0,0);
    ui->gridLayout_3->addWidget(num2,1,0);
    timer.setInterval(1500);
    connect(&timer,&QTimer::timeout,this,&MainWindow::setText);
    timer.start();

    //********************** Loading *************************
}

MainWindow::~MainWindow()
{
    if(timer.isActive())
        timer.stop();
    delete ui;
}

void MainWindow::setText()
{
    //*********************************************
    bar1->setValue(qrand()%100+1);
    bar2->setValue(qrand()%100+1);
    bar1->repaint();
    bar2->repaint();

    //*********************************************
    num1->setText(QString::number(qrand()%10));
    num2->setText(QString::number(qrand()%10));
    num1->repaint();
    num2->repaint();
}

