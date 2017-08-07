#include "loser.h"
#include "ui_loser.h"

Loser::Loser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loser)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/images/firstMap.png"));
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setGeometry(QRect(QPoint(0,0),QSize(810,460)));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-300,-300,800,450);

    ui->textBrowser->setText("""In a world where blocks rule.\nOne brave SQUARE died horribly\nNo surival here mate."""
                             """\n"""
                             """\nUse D-Pad to control the player.\n"""
                             """\n"""
                             """The green square hurt you!\n"""
                             """The gray slugs hurt you!\n"""
                             """And now you're dead!\n"""
                             """\n"""
                             """Restart or Exit?\n"""
                             """Your choice.""");
    ui->textBrowser->setGeometry(QRect(QPoint(200,100),QSize(400,225)));

    ui->pushButton->setText("Restart");
    ui->pushButton_2->setText("Exit");

    //ui->verticalLayout->setGeometry(QRect(QPoint(400,300),QSize(100,50)));
    ui->verticalLayoutWidget->setGeometry(QRect(QPoint(300,350),QSize(200,100)));
}

Loser::~Loser()
{
    delete ui;
}

void Loser::on_pushButton_clicked()
{
    this->hide();
    //GameWindow::mainLoop(15,15);
    //g = new GameWindow(this);
    //g->show();
    //g->setGeometry(QRect(QPoint(500,150),QSize(810,460)));
}

void Loser::on_pushButton_2_clicked()
{
    QApplication::quit();
}
