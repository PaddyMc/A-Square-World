#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setFixedWidth(600);
    ui->centralWidget->setWindowTitle("A Square World");

    // adding a background to a graphics scene Obj
    scene = new QGraphicsScene(this);
    ui->graphicsView->setWindowTitle("A Square World");
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,450);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/images/firstMap.png"));


    ui->pushButton->setText("Start");
    ui->pushButton->setGeometry(QRect(QPoint(125,50),QSize(150,150)));
    ui->pushButton_2->setText("Exit");
    ui->pushButton_2->setGeometry(QRect(QPoint(325,50),QSize(150,150)));
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    introWindow = new IntroWindow();
    introWindow->show();
    introWindow->setGeometry(QRect(QPoint(500,150),QSize(810,460)));
    this->hide();
    //delete this;
}
void StartWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}
