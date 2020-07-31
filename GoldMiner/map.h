#ifndef MAP_H
#define MAP_H

#include"items.h"
#include<stdlib.h>

#include<QtGui>

class map
{
private:
    item *item[14];
    int cur_item;
public:
    map();
    int get_cur_item(){return cur_item;}//number of current item
    double get_cur_speed(){return item[cur_item]->get_speed();}
    int get_cur_price(){return item[cur_item]->get_price();}
    int get_cur_type(){return item[cur_item]->get_type();}
    QPoint get_point(const int &i);//获取第i个物体的坐标(QPoint)
    int get_kind(const int &i);
    bool is_visible(const int &i);//查看i物体是否可见

    bool detect(const int &x,const int &y);//碰撞检测

    void invisible();//使cur_item不可见
    void rand();//随机生成矿石

    void init();
};
#endif // MAP_H

