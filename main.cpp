#include "mainwindow.h"
#include "buttons.h"

#include <QObject>
#include <memory>
#include <QDebug>
#include <windows.h>

void StartFoldersCheck();
void ResurcesDefault();
void showInGraphicalShell(QWidget *parent, const QString &pathIn);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartFoldersCheck();
    ResurcesDefault();

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
    if (!QDir(QApplication::applicationDirPath() + "/Info").exists())
        QDir().mkdir(QApplication::applicationDirPath() + "/Info");
    if (!QDir(QApplication::applicationDirPath() + "/Resurces").exists())
        QDir().mkdir(QApplication::applicationDirPath() + "/Resurces");
}

void ResurcesDefault(){
    QFile::copy(":/side_img/attack_red.png",
                QApplication::applicationDirPath() + "/Resurces/side_attack_t1.png");
    QFile::copy(":/side_img/attack_white.png",
                QApplication::applicationDirPath() + "/Resurces/side_attack_t2.png");
    QFile::copy(":/side_img/defend_red.png",
                QApplication::applicationDirPath() + "/Resurces/side_defense_t1.png");
    QFile::copy(":/side_img/defend_white.png",
                QApplication::applicationDirPath() + "/Resurces/side_defense_t2.png");
    QFile::copy(":/side_img/attack_red.png",
                QApplication::applicationDirPath() + "/Resurces/side_none_t1.png");
    QFile::copy(":/side_img/attack_white.png",
                QApplication::applicationDirPath() + "/Resurces/side_none_t2.png");
}

