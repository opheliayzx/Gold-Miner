#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QtGui>
#include<QLabel>
#include<QTimer>
#include<QKeyEvent>


#include<items.h>
#include<miner.h>
#include<map.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

    bool detection(); //if an item is reached
    void do_stop();
    void resume();
    void init();//initialize

private slots:
    void countdown();//timer countdown
    void rotate();//rotates the hook
    void stretch(); //streches the string down


    void on_toolButton_reset_clicked();
    void on_toolButton_continue_clicked();
    void on_toolButton_start_clicked();
    void on_toolButton_pause_clicked();
    void on_toolButton_restart_clicked();
    void on_toolButton_cancel_clicked();


private:
    Ui::MainWindow *ui;
    QPixmap pix;
    QImage background,hook;


    int cur_item;
    double rad;//radian to degrees
    int angle_change;
    int k;//multiple

    miner *miner;
    map *map;

    //计时器
    QTimer timer_angle,timer_clock,timer_s;
    int interval_angle,interval_miner;
    int time_left;
    int time;//time elapsed, generately items after 10 seconds
    int time_inc,time_dec;//how long inc/dec has effect

    QLabel *lable[15];//前2个为大金矿，后4个为小金矿,6-9为随机产生的石头（可重复产生）

};
#endif // MAINWINDOW_H
