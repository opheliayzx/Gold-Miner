#include "gamewindow.h"

#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QImage>
#include<QGraphicsProxyWidget>

GameWindow::GameWindow()
{

    scene = new QGraphicsScene();
    this->setFixedSize(800, 600);
    scene->setSceneRect(0,0,800,600);//both to be 800x600
    this->setWindowTitle(tr("Gold Miner 1.0"));
    setBackgroundBrush(QBrush(QImage(":/picture/newdinasourBackground.png")));//pass the background image

    //add miner
    miner = new Miner();
    scene->addItem(miner);

    //add items
    items = new Items();
    scene->addItem(items);

    //add the score
    score = new Score();
    scene->addItem(score);

    //add bombs
    bombs=new Bomb();
    scene->addItem(bombs);

    //add diamonds
    diamonds=new Diamond();
    scene->addItem(diamonds);

    //add countdown timer
    countdown = new QTimer(this);
    time_left = 60;
    connect(countdown, SIGNAL(timeout()), this, SLOT(update_time()));
    //countdown->start( 1000 );

    //countdown display with lcd
    timeLCD = new QLCDNumber();
    timeLCD->display(60);
    timeLCD->setSegmentStyle(QLCDNumber::Filled);
    timeLCD->setAttribute( Qt::WA_NoBackground );
    timeLCD->setFrameStyle( QFrame::NoFrame );
    QGraphicsProxyWidget *proxy = this->scene->addWidget(timeLCD);
    proxy->setPos(720, 10);

    this->setScene(scene);

    //make the miner focusable so it can move
    miner->setFlag(QGraphicsItem::ItemIsFocusable);
    miner->setFocus();
    //place the miner object at the top center
    miner->setPos(this->width()/2 - miner->pixmap().width()/2,15);

//    //play background music     --need mute option
//    QMediaPlayer* music = new QMediaPlayer();
//    music->setMedia(QUrl("qrc:/music/back2.mp3"));
//    music->play();

    generateItems();


    button = new QPushButton;
    QGraphicsProxyWidget *returnButton = this->scene->addWidget(button);
    returnButton->setPos(0,-10);

    button->setFlat(true);
    button->setAutoFillBackground(true);


    QPixmap pixmap(":/picture/returnButton.png");
    QIcon ButtonIcon(pixmap);
    button->setIcon(ButtonIcon);
    button->setFixedSize(pixmap.width(),pixmap.height());
    button->setIconSize(pixmap.size());
    button->setStyleSheet("background-color: rgba(255, 255, 255, 0);");


    QObject::connect(button,SIGNAL(clicked()),this,SLOT(on_returnmainButton_clicked()));

    //initialize end window
    end = new endwindow();
}

int GameWindow::get_score() {
    return score->getScore();
}

void GameWindow::generateItems()
{
    //generate gold
    gold_timer = new QTimer();
    connect(gold_timer,SIGNAL(timeout()),items,SLOT(spawn()));

    //generate bombs
    bomb_timer = new QTimer();
    connect(bomb_timer,SIGNAL(timeout()),bombs,SLOT(bomb_spawn()));

    //generate diamonds
    diamond_timer = new QTimer();
    connect(diamond_timer,SIGNAL(timeout()),diamonds,SLOT(spawn()));


}

void GameWindow::increase_Score()
{
    score->increase();
}

//show game page, when signal receive from mainwindow start
void GameWindow::receiveshow()
{
    countdown->start(1000); //countdown by second
    gold_timer->start(3000);//every 3 sec, generate golds
    diamond_timer->start(10000); //every 7 seconds, generate diamond
    bomb_timer->start(12000); //every 10 seconds, generate bomb
    this->show();
}


//return back to main window
void GameWindow::on_returnmainButton_clicked()
{
   miner->setFlag(QGraphicsItem::ItemIsFocusable);
   miner->setFocus();
   countdown->stop();

   this->hide();
   emit showmainwindow();
}

GameWindow::~GameWindow(){
    delete scene;
    delete miner;
    delete items;
    delete score;
    delete bombs;
    delete diamonds;
    delete countdown;
    delete diamond_timer;
    delete gold_timer;
    delete bomb_timer;
}

void GameWindow::update_time(){
    time_left-=1;
    timeLCD->display(time_left);
    if (time_left==0){
        countdown->stop();
        emit countdown_timeout();
        this -> hide();
        end ->new_score(this->get_score());
        end ->show();

//        this -> quit();

    }

}




