#include "player.h"
#include "item.h"

Player::Player()
{
    speed = 5;
    angel = 5;
    gameCount = 0;
    timeCount = 0;
    setFlag(ItemIsFocusable);
}
Player::Player(int s,int a,int gC,int tC)
{
    speed = s;
    angel = a;
    gameCount = 0;
    timeCount = 0;
    timeFin = tC;
    gameFin = gC;
    setFlag(ItemIsFocusable);
}

// pure virtual function
QRectF Player::boundingRect() const
{
    return QRectF(0,0,40,40);
}
//virtual
void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case(Qt::Key_Left):
        setPos(mapToParent(-(10),0));
        break;
    case(Qt::Key_Right):
        setPos(mapToParent(10,0));
        break;
    case(Qt::Key_Up):
        setPos(mapToParent(0,-(10)));
        break;
    case(Qt::Key_Down):
        setPos(mapToParent(0,10));
        break;
    default:
        break;
    }
}

void Player::Collision()
{
    gameCount++;
    winGame();
    //cout << "Collision count: " << gameCount << endl;
}

bool Player::winGame()
{
    bool fin = false;
    if(gameCount>=gameFin)
    {
        fin = true;
        gameCount = 0;
        timeCount = 0;
        loser = new Loser();
        loser->show();
        loser->setWindowTitle("Loser");
        loser->setGeometry(QRect(QPoint(500,150),QSize(810,460)));
        //delete this->window();
        //delete this;
    }
    else if(timeCount>=timeFin)
    {
        timeCount = 0;
        gameCount = 0;
        winner = new Winner();
        winner->show();
        winner->setWindowTitle("Winner");
        winner->setGeometry(QRect(QPoint(500,150),QSize(810,460)));
        //delete this;
    }
    return fin;
}

//virtual function
void Player::advance(int step)
{
    if(!step){return;}

    winGame();

    Player::operator ++();
}
void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush = (Qt::blue);

    if(scene()->collidingItems(this).isEmpty())
    {
         //no collision
    }
    else
    {
        brush.setColor(Qt::red);
        Collision();
    }
    painter->fillRect(rec,brush);
    painter->drawRect(rec);
    painter->setBrush(Qt::white);
    painter->drawEllipse(10, 10, 8, 8);
    painter->drawEllipse(20, 10, 8, 8);
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(10,10, 4, 4));
    painter->drawEllipse(QRectF(20, 10, 4, 4));
}
//overloaded operator
void Player::operator ++ ()
{
    this -> timeCount++;
    if (timeCount% 350 == 0)
    {
        cout<< "5 seconds left " << endl;
    }
    //cout<<"Time counting: "<<timeCount<<endl;
}

Player::~Player()
{
    delete this;
}

