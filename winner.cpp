#include "winner.h"
#include "ui_winner.h"

Winner::Winner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Winner)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/images/secondMap.png"));
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setGeometry(QRect(QPoint(0,0),QSize(810,460)));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-300,-300,800,450);

    ui->textBrowser->setText("""In a world where blocks rule.\nOne brave SQUARE competed\nAnd surived."""
                             """\n"""
                             """\nUse D-Pad to control the player.\n"""
                             """\n"""
                             """The green square did'nt hurt you!\n"""
                             """The gray slugs did'nt hurt you!\n"""
                             """And you're awesome!\n"""
                             """\n"""
                             """No luck needed, as the fella says.\n"""
                             """Congratulations.\n"""
                             """\n"""
                             """Restart or Exit?\n"""
                             """Your choice.""");
    ui->textBrowser->setGeometry(QRect(QPoint(200,100),QSize(400,225)));

    ui->pushButton->setText("Restart");
    ui->pushButton_2->setText("Exit");

    //ui->verticalLayout->setGeometry(QRect(QPoint(400,300),QSize(100,100)));
    ui->verticalLayoutWidget->setGeometry(QRect(QPoint(300,350),QSize(200,100)));

}

Winner::~Winner()
{
    delete ui;
}

void Winner::on_pushButton_clicked()
{
    //g = new GameWindow();
    this->hide();
    //show();
    //g->show();
    //g->setGeometry(QRect(QPoint(500,150),QSize(810,460)));
}

void Winner::on_pushButton_2_clicked()
{
    QApplication::quit();
}
