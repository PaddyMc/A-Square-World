#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
// pre processer directives
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include "player.h"
#include "item.h"
#include "enemy.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    virtual ~GameWindow();
    int baddieCount;
    int keyItemCount;

    void mainLoop(int a,int b);

private:
    Ui::GameWindow *ui;
    bool game;
    int enmCount;
    int itemCount;
    int gameCount;
    QGraphicsScene *scene;
    QTimer *timer;
    QGraphicsRectItem *rect;
    Player *player;
    Item *item;
    QTimer *a;
    Enemy *enemy;
    //templates
    QList<Item *> items;
    QList<Enemy *> enemys;
};

#endif // GAMEWINDOW_H
