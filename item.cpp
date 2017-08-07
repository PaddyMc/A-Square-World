#include "item.h"

Item::Item()
{
    type = "";
    //set the r angel
    angel = (qrand()%360);
    //set the speed(pixels)
    speed = 5;
    setFlag(ItemIsMovable);
    setRotation(angel);

    int StartX = 0;
    int StartY = 0;

    if ((qrand() %1))
    {
        StartX = (qrand() % 200);
        StartY = (qrand() % 200);
    }
    else
    {
        StartX = (qrand() % -100);
        StartY = (qrand() % -100);
    }

    setPos(mapToParent(StartX,StartY));
}

Item::Item(string t, qreal s)
{
    type = t;
    speed = s;
    angel = (qrand()%360);
    setFlag(ItemIsMovable);
    setRotation(angel);

    int StartX = 0;
    int StartY = 0;

    if ((qrand() %1))
    {
        StartX = (qrand() % 200);
        StartY = (qrand() % 200);
    }
    else
    {
        StartX = (qrand() % -100);
        StartY = (qrand() % -100);
    }

    setPos(mapToParent(StartX,StartY));
}
Item::~Item()
{
    delete this;
}
QRectF Item::boundingRect() const
{
    return QRectF(0,0,25,25);
}
void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush = (Qt::gray);
    //basic collision detection
    if(scene()->collidingItems(this).isEmpty())
    {
        //no collision
        brush.setColor(Qt::green);
    }
    else
    {
        //collision
        brush.setColor(Qt::red);
        DoCollision();
    }
    painter->fillRect(rec,brush);
    painter->drawRect(rec);
    painter->setBrush(Qt::white);
    painter->drawEllipse(5, 10, 8, 8);
    painter->drawEllipse(15, 10, 8, 8);
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(7, 13, 2, 2));
    painter->drawEllipse(QRectF(17, 13, 2, 2));
}

void Item::DoCollision()
{
    //Change the angle
    if(qrand()%1)
    {
        setRotation(rotation()+(180 + (qrand() % 10)));
    }
    else
    {
        setRotation(rotation()+(180 + (qrand() % -10)));
    }

    //see if the new position is inside bounds

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

void Item::rotate(int step)
{
    if(!step){return;}

    setRotation(this->rotation()+ angel);
}
void Item::advance(int step)
{
    if(!step){return;}

    //QPointF location = this->pos();

    setPos(mapToParent(0,-(speed)));

}
QPainterPath Item::shape() const
{
    QPainterPath path;
    path.addRect(-10,-20,20,40);
    return path;
}

