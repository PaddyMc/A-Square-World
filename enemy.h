#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "item.h"

class Enemy : public QGraphicsItem {

public:
    Enemy();
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);    
    Enemy(int s);
    ~Enemy();
private:
    qreal angel;
    qreal speed;
    void DoCollision();

protected:
    void advance(int step);
};

#endif // ENEMY_H
