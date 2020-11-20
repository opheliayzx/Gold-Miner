#include "anchor.h"

#include <QList> //COLLIDE
#include "items.h"
#include "gamewindow.h"
#include "bomb_endwindow.h"

extern GameWindow* gamewindow;
extern bomb_endwindow* b;

Anchor::Anchor(QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/picture/new anchor.png"));

    //(move down)
    timer = new QTimer();//timer: set a time, when time go to zero, signal execute
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);//every 50 millisec, anchor move

    //in charge of moving the anchor up
    timer_two = new QTimer();

}

void Anchor::move()
{
    //move the anchor down
    setPos(x(),y()+5);


    //check collision,if collides with gold, move up (colliding items)
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i<colliding_items.size();++i)
    {
        if((typeid (*colliding_items[i]) == typeid (Items))
                || (typeid (*colliding_items[i]) == typeid (Diamond)))
        {


            //make both the anchor and the item return to the miner's position
            timer->stop();//if collide, stop the move_down timer

            //turn on timer_two to move the anchor up
            connect(timer_two,SIGNAL(timeout()),this,SLOT(move_up()));
            timer_two->start(50);

           //remove and delete the colliding items------how????

//            scene()->removeItem(colliding_items[i]);
//            delete colliding_items[i];

            return;
        }
        else if (typeid (*colliding_items[i]) == typeid (Bomb))
        {

            timer->stop();//if collide, stop the move_down timer

            //turn on timer_two to move the anchor up
            connect(timer_two,SIGNAL(timeout()),this,SLOT(move_up_bomb()));
            timer_two->start(50);
            return;
        }

    }


    //check if it is off the screen
    if(pos().y()>600)
    {
        scene()->removeItem(this);
        delete this;

    }


}

void Anchor::move_up()
{
    //move the anchor up
    setPos(x(),y()-10);

    //check if it passed the miner
    if(pos().y() < 30)
    {
        scene()->removeItem(this);
        delete this;

    }

}

void Anchor::move_up_bomb()
{
    setPos(x(),y()-10);

    //check if it passed the miner
    if(pos().y() < 30)
    {
        gamewindow->hide();
        b->new_score(gamewindow->get_score());
        b->show();
    }
};

Anchor::~Anchor(){
    delete timer;
    delete timer_two;
};
