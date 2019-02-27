#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addPixel(int x, int y);

signals:
    void environmentChanged(bool ok);

public slots:
    void clearField();
    void startCheck();


private:
    Ui::MainWindow *ui;
    const int SIZE=28;
    QVector <int> qv_x ;                    // storing the 1.0 value pixels
    QVector <int> qv_y ;

protected:
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void onMouseEvent(const QString &eventName, const QPoint &pos);

    

};

#endif // MAINWINDOW_H
