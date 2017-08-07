#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsScene>
using namespace std;

class Item  : public QGraphicsItem {

public:
    Item();
    Item(string t,qreal s);
    ~Item();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPainterPath shape() const;

public slots:
    void rotate(int step);
    virtual void advance(int step);

private:
    string type;
    qreal angel;
    qreal speed;
    void DoCollision();
};

#endif // ITEM_H
