#ifndef BOMB_H
#define BOMB_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "items.h"

class Bomb: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bomb(QGraphicsItem* parent=0);
    ~Bomb();

public slots:
    void bomb_spawn();
    void bomb_check_collide();
    void bomb_moveup();

private:
    QTimer* bomb_timer;
};

#endif // BOMB_H
