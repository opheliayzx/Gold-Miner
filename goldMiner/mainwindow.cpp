#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(800, 600);
    //setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle(tr("Gold Miner 1.0"));
    //window set central
    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

    //add background picture
    QPixmap background(":/picture/blackBackground.jpg");
    background=background.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,background);
    this->setPalette(palette);

    //play background music     --need mute option
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/back2.mp3"));
    music->play();

//    //start button
//    QPushButton *buttonStart=new QPushButton;
//    buttonStart->setFixedSize(200,100);

//    buttonStart->setStyleSheet("QPushButton{""background-image:url(:/picture/playButton.png);"//设置按钮背景图片
//                                        "background-repeat:repeat-xy;" //设置按钮的背景图片的重复规则，x方向y方向，xy方向
//                                        "background-position:Center;" //设定背景图片在按钮中的位置,按左对齐Left，右Right，中间Center，上Top，底部Bottom
//                                        "background-attachment:fixed;"
//                                        "background-clip:padding}");

//    buttonStart->setStyleSheet(tr("background-image: url(:/picture/playButton.png);"));



//    QPushButton *buttonRules=new QPushButton;
//    buttonRules->setFixedSize(100,50);

//    QPushButton *buttonMute=new QPushButton;
//    buttonMute->setFixedSize(100,50);

//    QVBoxLayout *layout=new QVBoxLayout;



//    layout->addWidget(buttonStart);
//    layout->addSpacing(30);
//    layout->addWidget(buttonRules);
//    layout->addSpacing(30);
//    layout->addWidget(buttonMute);
//    layout->setAlignment(Qt::AlignRight);
//    layout->setContentsMargins(550,5,5,5);

//    QWidget *widget1=new QWidget;

//    widget1->setLayout(layout);

//    this->setCentralWidget(widget1);



}

MainWindow::~MainWindow()
{
    delete ui;
}


//start button , start new game
void MainWindow::on_buttonStart_clicked()
{
    this->hide();
    emit dlgshow();
    //emit quit();
}

//rules, direct to rules & instruction page
void MainWindow::on_buttonRules_clicked()
{
    this->hide();
    emit quit();
}

//receive signal from game page, return main window
void MainWindow::receiveReturn()
{
    this->show();
}

void MainWindow::on_buttonMute_clicked()
{
    music->setMuted(true);
}
