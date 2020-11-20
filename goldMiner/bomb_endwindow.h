#ifndef BOMB_ENDWINDOW_H
#define BOMB_ENDWINDOW_H

#include <QMainWindow>
#include<QGraphicsPixmapItem>
#include<QPixmap>

#include<score.h>

namespace Ui {
class bomb_endwindow;
}

class bomb_endwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit bomb_endwindow(QWidget *parent = nullptr);
    ~bomb_endwindow();

signals:
    void update_score(int);

public slots:
    void new_score(int i);



private:
    Ui::bomb_endwindow *ui;
    int score;
};

#endif // BOMB_ENDWINDOW_H
