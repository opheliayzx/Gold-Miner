#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMediaPlayer>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QWidget>
#include <QDesktopWidget>
#include <QPixmap>
QT_BEGIN_NAMESPACE


namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
private slots:
    void receiveReturn();//与login中发射的信号关联的槽函数
    void on_buttonStart_clicked();//与start game关联
    void on_buttonRules_clicked();//与rules关联

    void on_buttonMute_clicked();

signals:
    void dlgshow();//显示登录对话框信号
    void quit();//退出信号
private:
    QMediaPlayer* music;
};
#endif // MAINWINDOW_H
