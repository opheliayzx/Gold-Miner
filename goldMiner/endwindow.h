#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class endwindow;
}

QT_END_NAMESPACE

class endwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit endwindow(QWidget *parent = nullptr);
    ~endwindow();

signals:
    void update_score(int);
    void quit_game();

public slots:
    void new_score(int i);




private:
    Ui::endwindow *ui;
    QLabel* score_label;
    QPushButton* quit_button;
    QVBoxLayout* layout;
    int score;



};

#endif // ENDWINDOW_H
