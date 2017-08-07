#ifndef INTROWINDOW_H
#define INTROWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include "gamewindow.h"

namespace Ui {
class IntroWindow;
}

class IntroWindow : public QDialog
{
    Q_OBJECT

public:
    explicit IntroWindow(QWidget *parent = 0);
    virtual ~IntroWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::IntroWindow *ui;
    QGraphicsScene *scene;
    GameWindow *gamewindow;
};

#endif // INTROWINDOW_H
