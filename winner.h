#ifndef WINNER_H
#define WINNER_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
//#include "gamewindow.h"
//#include "player.h"
//class GameWindow;
namespace Ui {
class Winner;
}

class Winner : public QWidget
{
    Q_OBJECT

public:
    explicit Winner(QWidget *parent = 0);
    virtual ~Winner();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Winner *ui;
    QGraphicsScene *scene;
    //GameWindow *g;
};

#endif // WINNER_H
