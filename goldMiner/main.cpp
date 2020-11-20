#include "mainwindow.h"
#include "gamewindow.h"
#include "bomb_endwindow.h"
#include "endwindow.h"
#include <QApplication>

bomb_endwindow* b;
GameWindow* gamewindow;
endwindow* end;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    gamewindow = new GameWindow();
    b = new bomb_endwindow();
    end = new endwindow();
//    end = new endwindow();

    //QObject::connect(&dlg,SIGNAL(showmainwindow()),&w,SLOT(receivelogin()));
    //QObject::connect(&w,SIGNAL(dlgshow()),&dlg,SLOT(receiveshow()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));//connect mainwindow quit, application quit
    QObject::connect(&w,SIGNAL(dlgshow()),gamewindow,SLOT(receiveshow()));//connect mainwindow call game window, game window show
    //connect game window call main windiw, maindow show
    QObject::connect(gamewindow,SIGNAL(showmainwindow()),&w,SLOT(receiveReturn()));





//    bomb_endwindow b;
//    b.show();


    return a.exec();
}
