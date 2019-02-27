#include "mainwindow.h"
#include <QApplication>
#include "neuron.h"
#include "weightsmatrix.h"
#include <iostream>
#include <qdebug.h>
#include "neuronnet.h"


int main(int argc, char *argv[])
{
    vector<int> test {10,10,5};
    qDebug() << test;
    NeuronNet bla(test);






    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
