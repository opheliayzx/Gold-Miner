#include "miner.h"
#include "anchor.h"

Miner::Miner(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/picture/1 copy.png"));

}

void Miner::keyPressEvent(QKeyEvent *event)
{
    {
        if(event->key() == Qt::Key_Left)
        {
            if(x()>0)//pos().x()>0
            {
                setPos(x()-15,y());
            }

        }
        else if(event->key() == Qt::Key_Right)
        {
            if(x()+pixmap().width()<800)
            {
                setPos(x()+15,y());
            }
        }
        else if(event->key() == Qt::Key_Space)
        {
            this->clearFocus();

            //release the anchor
            Anchor* anchor = new Anchor();
            anchor->setPos(x()+45,y()+pixmap().height());
            scene()->addItem(anchor);


//            //play grab_sound
//            if(grab_sound->state() == QMediaPlayer::PlayingState)//if already played, rewind it
//            {
//                grab_sound->setPosition(0);
//            }
//            else if(grab_sound->state() == QMediaPlayer::StoppedState)
//            {
//                grab_sound->play();//only play once if this is only line
//            }

        }


    }
}
