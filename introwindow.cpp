#include "introwindow.h"
#include "ui_introwindow.h"

IntroWindow::IntroWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IntroWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setTextBackgroundColor(Qt::red);
    //ui->textBrowser->;
    ui->textBrowser->setText("""In a world where blocks rule.\nOne brave SQUARE will compete\nTo surive."""
                             """\n"""
                             """\nUse D-Pad to control the player.\n"""
                             """If you touch the red wall you die\n"""
                             """\n"""
                             """The green squares want to hurt you!\n"""
                             """The gray slugs want to hurt you\n"""
                             """Avoid everyone at all costs\n"""
                             """\n"""
                             """Good luck and God's speed\n"""
                             """Gods speed = 5pxls\n""");
    ui->textBrowser->setGeometry(QRect(QPoint(200,100),QSize(400,225)));
    scene = new QGraphicsScene(this);
    ui->graphicsView->setWindowTitle("A Square World");
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,450);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/images/firstMap.png"));

    ui->pushButton->setGeometry(QRect(QPoint(450,350),QSize(100,50)));
    ui->pushButton->setText("Continue!");

}

IntroWindow::~IntroWindow()
{
    delete ui;
}

void IntroWindow::on_pushButton_clicked()
{
    gamewindow = new GameWindow();
    gamewindow->setWindowTitle("A SQUARE WORLD");
    gamewindow->setGeometry(QRect(QPoint(500,150),QSize(810,460)));
    gamewindow->show();
    this->hide();
}
