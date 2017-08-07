#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "player.h"
#include "item.h"
#include "enemy.h"

//function prototypes
void advance(int step);
void rotate(int step);
bool winGame();

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/images/secondMap.png"));
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setGeometry(QRect(QPoint(0,0),QSize(810,460)));

    mainLoop(15,15);
}
void GameWindow::mainLoop(int eC,int iC)
{
    setFocusPolicy(Qt::StrongFocus);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-300,-300,800,450);
    game = true;

    if(game)
    {
        enmCount = eC;
        itemCount = iC;

        for(int i=0;i<itemCount;i++)
        {
            if(qrand() % 2)
            {
                //not a memory leak
                Item *item = new Item();
                //item ->setPos(qrand() % 260, qrand() % 260);
                scene->addItem(item);
                items.push_back(item);
            }
            else
            {
                Item *item = new Item();
                item->setPos(qrand()%(500), qrand()%150);
                scene->addItem(item);
                items.push_back(item);
            }

        }
        for(int i=0;i<enmCount;i++)
        {
            if(qrand() % 2)
            {
                Enemy *enemy = new Enemy((qrand() % 10)+1);
                enemy->setPos(qrand() % 500,qrand() % 300);
                scene->addItem(enemy);
                enemys.push_back(enemy);
            }
            else
            {
                Enemy *enemy = new Enemy((qrand() % 10)+1);
                enemy->setPos(qrand() % -(300),qrand() % -(150));
                scene->addItem(enemy);
                enemys.push_back(enemy);

            }
        }

        player = new Player(5,5,15,400);
        player->setPos(-150,-150);
        scene->addItem(player);

        QPen mypen = QPen(Qt::red);

        QLineF TopLine(scene->sceneRect().topLeft(),scene->sceneRect().topRight());
        QLineF LeftLine(scene->sceneRect().topLeft(),scene->sceneRect().bottomLeft());
        QLineF RightLine(scene->sceneRect().topRight(),scene->sceneRect().bottomRight());
        QLineF BottomLine(scene->sceneRect().bottomLeft(),scene->sceneRect().bottomRight());

        scene->addLine(TopLine,mypen);
        scene->addLine(LeftLine,mypen);
        scene->addLine(RightLine,mypen);
        scene->addLine(BottomLine,mypen);

        timer = new QTimer(this);
        timer->connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
        timer->start(100);

        a = new QTimer(this);
        a->connect(a,SIGNAL(timeout()),scene,SLOT(isActive()));
        timer->start(100);
        scene -> setActivePanel(player);
        scene -> setFocusItem(player);

        if(player->isActive())
        {
            game = false;
            cout<<"yea"<<endl;
        }
        else
        {
            //cout<<"no"<<endl;
            game = true;
        }
    }
}

//virtual function
GameWindow::~GameWindow()
{
    delete ui;
    for(int i = 0;i<items.length();i++)
    {
        delete items[i];
    }
    for(int i = 0;i<enemys.length();i++)
    {
        delete enemys[i];
    }

}
