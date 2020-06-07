#include "mainwindow.h"
#include "updateextdata.h"

#include <QApplication>
#include <QDir>
#include <QDebug>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* MWindow = new MainWindow;
    MWindow->show();
    return a.exec();
}
