#include "MainWindow.h"
#include "ApplicationSettings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ApplicationSettings settings;

    QStringList l("None");
    l.append("Sigma");
    settings.setHeroes(qMakePair(l, QStringList()));

    MainWindow window(&settings);
    window.show();
    return app.exec();
}
