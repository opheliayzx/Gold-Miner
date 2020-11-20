#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <mainwindow.h>
#include <QGraphicsView>
#include <QTimer>
#include <QLCDNumber>
#include <QGraphicsProxyWidget>
#include"anchor.h"
#include "miner.h"
#include "items.h"
#include"bomb.h"
#include "diamond.h"
#include "endwindow.h"
#include "score.h"

//namespace Ui {
//class GameWindow;
//}


class GameWindow :public QGraphicsView{
    Q_OBJECT

public:
    GameWindow();
    ~GameWindow();

    void generateItems();
    void increase_Score();
    int get_score();//return score to the bomb_endwindow

private slots:
    void receiveshow();//receive signal from mainwindow, show game window
    void on_returnmainButton_clicked();//return main window
    void update_time(); //countdown
//    void time_up(); //when countdown is done



signals:
    void showmainwindow();//connect to mainwindow, return main window
    void quit();//quit app
    void countdown_timeout(); //times up
private:
    QGraphicsScene* scene;
    Miner* miner;
    Items* items;
    Score* score;
    Bomb* bombs;
    Anchor* anchor;
    Diamond* diamonds;
    QTimer* countdown;
    QTimer* bomb_timer;
    QTimer* gold_timer;
    QTimer* diamond_timer;
    QLCDNumber* timeLCD;

    QPushButton *button;
    int time_left;

    endwindow* end;
    //Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
