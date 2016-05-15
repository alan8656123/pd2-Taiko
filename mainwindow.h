#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QtCore>
#include<QMediaPlayer>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void gogogo();

    void MyTimer();
    void MyCount();
    QTimer *timer;
    QTimer *count;
    static const int runtime=30;
public slots:
    void MySlot();
    void counter();
private slots:
    void on_start_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui,*ui2;
        void keyPressEvent(QKeyEvent *event);
        int intValue=0;
        int time=runtime;
        QMediaPlayer * music=new QMediaPlayer();
        QMediaPlayer * sounds=new QMediaPlayer();
};


#endif // MAINWINDOW_H
