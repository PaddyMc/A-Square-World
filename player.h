#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QApplication>
#include <QGraphicsScene>
#include <iostream>
#include "item.h"
#include "enemy.h"
#include "winner.h"
#include "loser.h"
using namespace std;
class GameWindow;
class Player : public QGraphicsItem
{
public:
    Player();
    virtual QRectF boundingRect() const;
    Player(int s, int a, int gC, int tC);
    void addEndGame(Item item);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    virtual void keyPressEvent(QKeyEvent *event);
    void operator ++();
    ~Player();
public slots:
    bool winGame();

protected:
    virtual void advance(int step);

private:
    void Collision();
    qreal angel;
    qreal speed;
    int gameCount;
    int timeCount;
    int gameFin;
    int timeFin;
    // template
    QList <QGraphicsItem *> items;
    Winner *winner;
    Loser *loser;
};

#endif // PLAYER_H
