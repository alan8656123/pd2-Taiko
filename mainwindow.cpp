#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>
#include<QtCore>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber_2->display(runtime);
    ui->scrollArea->move(QPoint(1000,1000));
    ui->start->move(QPoint(300,400));
    ui->blue->move(QPoint(1000,1000));
    ui->red->move(QPoint(1000,1000));
    ui->red2->move(QPoint(1000,1000));
    ui->add1->move(QPoint(1000,1000));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_J)
    {
        sounds->setSource(QUrl("qrc:/sound/yisell_sound_2010060315174759838_88016.wav"));
        int x=ui->red->x();
        int y=ui->red->y();
        int z=ui->lcdNumber->intValue();
        if(x>=0&&x<=100){
            ui->lcdNumber->display(++intValue);
            ui->red->move(QPoint(1000,40));
            sounds->play();
        }

        int x1=ui->red2->x();
        int y1=ui->red2->y();
        int z1=ui->lcdNumber->intValue();
        if(x1>=0&&x1<=100){
            ui->lcdNumber->display(++intValue);
            ui->red2->move(QPoint(1300,40));
            sounds->play();
        }
    }
    if(event->key()==Qt::Key_K)
    {
        sounds->setSource(QUrl("qrc:/sound/yisell_sound_2010060315174759838_88016.wav"));
        int x=ui->blue->x();
        int y=ui->blue->y();
        int z=ui->lcdNumber->intValue();
        if(x>=0&&x<=100){
            ui->lcdNumber->display(++intValue);
            ui->blue->move(QPoint(1000,40));
            sounds->play();
        }
        event->accept();
    }
}

void MainWindow::MyTimer()
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));
            timer->start(5);
}
void MainWindow::MySlot()
{
    int x=ui->blue->x();
    int y=ui->blue->y();
    ui->blue->move(QPoint(x-3,y));
    if(-100<x&&x<-50)ui->blue->move(QPoint(1000,40));

    int x2=ui->red->x();
    int y2=ui->red->y();
    ui->red->move(QPoint(x2-2,y2));
    if(-100<x2&&x2<-50)ui->red->move(QPoint(1000,40));

    int x3=ui->red2->x();
    int y3=ui->red2->y();
    ui->red2->move(QPoint(x3-2,y3));
    if(-100<x3&&x3<-50)ui->red2->move(QPoint(1000,40));
}
void MainWindow::MyCount()
{
    count=new QTimer(this);
    connect(count,SIGNAL(timeout()),this,SLOT(counter()));
            count->start(1000);
}
void MainWindow::counter()
{
if(time>0)ui->lcdNumber_2->display(--time);
else{
    ui->scrollArea->move(QPoint(200,150));
    ui->blue->move(QPoint(-1000,40));
    ui->red->move(QPoint(-1000,40));
    ui->red2->move(QPoint(-1000,40));
    ui->lcdNumber_3->display(intValue);

    music->setSource(QUrl("qrc:/sound/ffaboss.mp3"));
    music->stop();
    }
}

void MainWindow::on_start_clicked()
{
    MyTimer();
    MyCount();
      music->setSource(QUrl("qrc:/sound/ffaboss.mp3"));
      music->play();
   ui->start->move(QPoint(1000,1000));
   ui->blue->move(QPoint(1000,40));
   ui->red->move(QPoint(1000,40));
   ui->red2->move(QPoint(1200,40));
   ui->startpage->move(QPoint(-5000,40));
}

void MainWindow::on_pushButton_2_clicked()
{
    time=runtime;
    intValue=0;
    ui->scrollArea->move(QPoint(-1000,250));
    ui->blue->move(QPoint(1000,40));
    ui->red->move(QPoint(1000,40));
    ui->red2->move(QPoint(1200,40));
    ui->lcdNumber_2->display(runtime);
    ui->lcdNumber->display(intValue);

    music->setSource(QUrl("qrc:/sound/ffaboss.mp3"));
    music->play();
}

void MainWindow::on_pushButton_3_clicked()
{exit(1);}


