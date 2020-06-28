#include <QObject>
#include <memory>
#include <QDebug>
#include <QFile>

#include "mainwindow.h"
#include "iuserinterface.h"
#include "filecontrol.h"
#include "buttons.h"

void StartFoldersCheck();
void ResurcesDefault();
void RestoreUIData(IUserInterface* ui);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* MWindow = new MainWindow();
    Buttons *buttons = new Buttons(MWindow);

    StartFoldersCheck();
    ResurcesDefault();
    //RestoreUIData(MWindow);

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
    const QString cdir = QApplication::applicationDirPath();
    if (!QDir(cdir + "/CurrentMap").exists())
        QDir().mkdir(cdir + "/CurrentMap");
    if (!QDir(cdir + "/Info").exists())
        QDir().mkdir(cdir + "/Info");
    if (!QDir(cdir + "/Resurces").exists())
        QDir().mkdir(cdir + "/Resurces");
}

void ResurcesDefault(){
    const QString cdir = QApplication::applicationDirPath();
    QFile::copy(":/side_img/attack_red.png",
                cdir + "/Resurces/side_attack_t1.png");
    QFile::copy(":/side_img/attack_white.png",
                cdir + "/Resurces/side_attack_t2.png");
    QFile::copy(":/side_img/defend_red.png",
                cdir + "/Resurces/side_defense_t1.png");
    QFile::copy(":/side_img/defend_white.png",
                cdir + "/Resurces/side_defense_t2.png");
    QFile::copy(":/side_img/attack_red.png",
                cdir + "/Resurces/side_none_t1.png");
    QFile::copy(":/side_img/attack_white.png",
                cdir + "/Resurces/side_none_t2.png");
}

void RestoreUIData(IUserInterface* ui){
    const QString cdir = QApplication::applicationDirPath();
    ui->SetTeam1({ FileControl::ReadFile(cdir + "/CurrentMap/Team1_Name.txt"),
        FileControl::ReadFile(cdir + "/CurrentMap/Team1_ShortName.txt"),
        FileControl::ReadFile(cdir + "/CurrentMap/logoT1.txt"),
        FileControl::ReadFile(cdir + "/CurrentMap/Score_Team1.txt").toInt() });
    ui->SetTeam2({ FileControl::ReadFile(cdir + "/CurrentMap/Team2_Name.txt"),
        FileControl::ReadFile(cdir + "/CurrentMap/Team2_ShortName.txt"),
        FileControl::ReadFile(cdir + "/CurrentMap/logoT2.txt"),
        FileControl::ReadFile(cdir + "/CurrentMap/Score_Team2.txt").toInt() });
    ui->SetMutualMapInfo({ FileControl::ReadFile(cdir + "/CurrentMap/Map.txt"), FileControl::ReadFile(cdir + "/CurrentMap/MutualInfo.txt") });
    QVector<QString> util;
    for (int ix = 1; ix < 10; ix++)
        util.push_back(FileControl::ReadFile(cdir + "/Info/Utility" + QString::number(ix) + ".txt"));
    ui->SetUtilityList(util);
}
