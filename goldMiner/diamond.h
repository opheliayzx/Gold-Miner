#ifndef DIAMOND_H
#define DIAMOND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QRandomGenerator>
#include<QTimer>
#include"items.h"

class Diamond: public Items
{
public:
    Diamond();
    void spawn();
    ~Diamond();
private:
    QTimer* diamond_timer;
};

#endif // DIAMOND_H
