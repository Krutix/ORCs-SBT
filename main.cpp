#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <memory>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<MainWindow> MWindow = std::make_shared<MainWindow> ();
    MWindow->show();
    return a.exec();
}
