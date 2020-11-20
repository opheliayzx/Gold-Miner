#ifndef ANCHOR_H
#define ANCHOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Anchor: public QObject,public QGraphicsPixmapItem{
        Q_OBJECT
public:
    Anchor(QGraphicsItem* parent=0);
    ~Anchor();

public slots:
    void move();
    void move_up();
    void move_up_bomb();
private:
    QTimer* timer;
    QTimer* timer_two;
};

#endif // ANCHOR_H
