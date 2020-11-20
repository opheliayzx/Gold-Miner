#include "bomb.h"
#include "anchor.h"

#include "gamewindow.h"
#include "bomb_endwindow.h"

#include <stdlib.h>
#include <QTimer>
#include <QList>
#include <QDebug>
#include<iostream>
#include<QRandomGenerator>

extern GameWindow* gamewindow;
extern bomb_endwindow* b;

Bomb::Bomb(QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent)
{
       setPixmap(QPixmap(":/picture/bomb.png"));
       setScale(0.03);
       int random_number = QRandomGenerator::global()->bounded(30,700);
       int random_number2 = QRandomGenerator::global()->bounded(140,500);
       setPos(random_number,random_number2);
       bomb_timer = new QTimer();
       connect(bomb_timer,SIGNAL(timeout()),this,SLOT(bomb_check_collide()));
       bomb_timer->start(50);//every 50 millisec, anchor move

}

void Bomb::bomb_spawn(){
    Bomb* bombs = new Bomb();
    scene()->addItem(bombs);
};

void Bomb::bomb_check_collide(){
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i<colliding_items.size();++i)
    {
        if(typeid (*colliding_items[i]) == typeid (Anchor))
        {

       //turn on timer_two to move the anchor up
            QTimer* timer = new QTimer();
            connect(timer,SIGNAL(timeout()),this,SLOT(bomb_moveup()));
            timer->start(50);

            return;
        }
    }
};

void Bomb::bomb_moveup()
{
    //move the anchor up
    setPos(x(),y()-10);

};


Bomb::~Bomb(){
    delete bomb_timer;
};


