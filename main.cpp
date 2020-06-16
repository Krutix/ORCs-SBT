#include "mainwindow.h"
#include "buttons.h"

#include <QObject>
#include <memory>
#include <QDebug>

void StartFoldersCheck();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartFoldersCheck();

    MainWindow* MWindow = new MainWindow();

    Buttons *buttons = new Buttons(MWindow);
    QObject::connect(MWindow->GetButtonCMatch_Swap(), SIGNAL(clicked()),
            buttons, SLOT(Swap_CurrentTeams()));
    QObject::connect(MWindow->GetButtonCMatch_Reset(), SIGNAL(clicked()),
            buttons, SLOT(Reset_CurrentMatch()));
    QObject::connect(MWindow->GetButtonCMatch_Update(), SIGNAL(clicked()),
            buttons, SLOT(Update_CurrentMatch()));
    QObject::connect(MWindow->GetButtonCast_Update(), SIGNAL(clicked()),
            buttons, SLOT(Update_CastInfo()));
    QObject::connect(MWindow->GetButtonCast_Reset(), SIGNAL(clicked()),
            buttons, SLOT(Reset_CastInfo()));
    MWindow->show();
    return a.exec();
}

void StartFoldersCheck(){
    if (!QDir(QApplication::applicationDirPath() + "/CurrentMap").exists())
        QDir().mkdir(QApplication::applicationDirPath() + "/CurrentMap");
    if (!QDir(QApplication::applicationDirPath() + "/CastInfo").exists())
        QDir().mkdir(QApplication::applicationDirPath() + "/CastInfo");
}
