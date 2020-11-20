#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class Items:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Items(QGraphicsItem* parent=0);
        virtual ~Items();

public slots:
    virtual void spawn();
    void check_collide();
    void moveup();

private:
    QTimer* timer;

};

#endif // MAP_H
