#include "enemy.h"

Enemy::Enemy()
{
    angel = (qrand()%360);
    speed = 5;
    setFlag(ItemIsMovable);
    setRotation(angel);
}
Enemy::Enemy(int s)
{
    angel = (qrand()%360);
    speed = s;
    setFlag(ItemIsMovable);
    setRotation(angel);
}

QRectF Enemy::boundingRect() const
{
    return QRectF(-10,-20,20,40);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QRectF rec = boundingRect();
    //QBrush brush = (Qt::gray);
    painter->setBrush(Qt::gray);
    painter->drawEllipse(-10, -20, 20, 40);

    painter->setBrush(Qt::white);
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);
    painter->setBrush(Qt::black);
    //painter->drawEllipse(QRectF(-2, -22, 4, 4));
    painter->drawEllipse(QRectF(-8.0, -17, 4, 4));
    painter->drawEllipse(QRectF(4.0, -17, 4, 4));

    if(scene()->collidingItems(this).isEmpty())
    {
        //no collision
    }
    else
    {
        DoCollision();
    }

}

void Enemy::DoCollision()
{
    if(qrand()%1)
    {
        setRotation(rotation()+(180 + (qrand() % 10)));
    }
    else
    {
        setRotation(rotation()+(180 + (qrand() % -10)));
    }

    QPointF newpoint = mapToParent(-(boundingRect().width()),-(boundingRect().width()+2));

    if(!scene()->sceneRect().contains((newpoint)))
    {
        //move it inside bounds
        newpoint = mapToParent(0,0);
    }
    else
    {
        //set the new position
        setPos(newpoint);
    }

}

void Enemy::advance(int step)
{
    if(!step){return;}

    //QPointF location = this->pos();

    setPos(mapToParent(0,-(speed)));
}
Enemy::~Enemy()
{
    delete this;
}

