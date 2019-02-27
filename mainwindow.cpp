#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QColor>
#include <QVector>
#include <QPen>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->clearButton, SIGNAL(clicked()),SLOT(clearField()));
    connect(ui->startButton,SIGNAL(clicked()),SLOT(startCheck()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen net(QColor("red"));
    net.setWidth(3);
    painter.setPen(net);

        if (qv_x.size() != 0)
        {
        for (int i = 0;  i < qv_x.size(); i++)
            painter.drawPoint(qv_x[i],qv_y[i]);
        }



     QPen ellipse(QColor("black"));              //use this pen for the circle
     ellipse.setWidth(0.1);
     painter.setPen(ellipse);
     QRect gameLayout(3,3,320,410);
     painter.drawRect(gameLayout);;
}




void MainWindow::addPixel(int x, int y)
{
    if (qv_x.size() != 0)
    {
        qv_x.append(x);
        qv_y.append(y);
        qDebug("Point Added");
    }

}

void MainWindow::clearField()
{
    qDebug("Cleared");
}

void MainWindow::startCheck()
{
    qDebug("Started");
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    emit environmentChanged(true);
    onMouseEvent("Press",e->pos());             // if the user clicks

    update();


}

void MainWindow::onMouseEvent(const QString &eventName, const QPoint &pos)
{
    emit environmentChanged(true);
    addPixel(pos.x(),pos.y());

}
