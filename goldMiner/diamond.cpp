#include"diamond.h"

Diamond::Diamond():Items()
{
    setPixmap(QPixmap(":/picture/diamond.png"));
    setScale(0.1);
    int random_number = QRandomGenerator::global()->bounded(30,700);
    int random_number2 = QRandomGenerator::global()->bounded(140,500);
    setPos(random_number,random_number2);

    diamond_timer = new QTimer();//timer: set a time, when time go to zero, signal execute
    connect(diamond_timer,SIGNAL(timeout()),this,SLOT(check_collide()));
    diamond_timer->start(50);//every 50 millisec, anchor move

}

void Diamond::spawn(){
    Diamond* diamonds=new Diamond();
    scene()->addItem(diamonds);
};

Diamond::~Diamond(){
    delete diamond_timer;
};
