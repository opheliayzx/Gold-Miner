#include "endwindow.h"
#include "ui_endwindow.h"

endwindow::endwindow(QWidget *parent): QMainWindow(parent), ui(new Ui::endwindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    this->setWindowTitle(tr("The end"));
    //set background picture
    QPixmap background(":/picture/caveBackground.jpg");
    background = background.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    quit_button = new QPushButton("Quit Game");
    QString s = QString::number(score);
    score_label = new QLabel(s);


    layout = new QVBoxLayout;

    layout -> addWidget(score_label);
    layout -> addWidget(quit_button);
    layout->setAlignment(quit_button, Qt::AlignHCenter);
    layout->setAlignment(score_label, Qt::AlignHCenter);
    this -> setLayout(layout);


}

endwindow::~endwindow()
{
    delete ui;
}


void endwindow::new_score(int i) {

    score = i;
}

