#ifndef LOSER_H
#define LOSER_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include <QtCore>
#include <QtGui>
//#include "gamewindow.h"
//#include "ui_gamewindow.h"

namespace Ui {
class Loser;
}

class Loser : public QWidget
{
    Q_OBJECT

public:
    explicit Loser(QWidget *parent = 0);
    virtual ~Loser();
    friend class GameWindow;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Loser *ui;
    //Ui::GameWindow *uig;
    QGraphicsScene *scene;
    //GameWindow *g;

};

#endif // LOSER_H
