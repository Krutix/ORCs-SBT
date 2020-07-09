#include <QObject>
#include <memory>
#include <QDebug>
#include <QFile>

#include "mwindow.h"
#include "iuserinterface.h"
#include "filecontrol.h"
#include "buttons.h"

void StartFoldersCheck();
void ResurcesDefault();
void RestoreUIData(IUserInterface* ui);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MWindow* MainWindow = new MWindow();
    Buttons *buttons = new Buttons(MainWindow);

    StartFoldersCheck();
    ResurcesDefault();
    RestoreUIData(MainWindow);

    //Current match buttons connect
    QObject::connect(MainWindow->GetButtonCMatch_Swap(), SIGNAL(clicked()),
            buttons, SLOT(Swap_CurrentTeams()));
    QObject::connect(MainWindow->GetButtonCMatch_Reset(), SIGNAL(clicked()),
            buttons, SLOT(Reset_CurrentMatch()));
    QObject::connect(MainWindow->GetButtonCMatch_Update(), SIGNAL(clicked()),
            buttons, SLOT(Update_CurrentMatch()));
    //General info buttons connect
    QObject::connect(MainWindow->GetButtonCast_Update(), SIGNAL(clicked()),
            buttons, SLOT(Update_CastInfo()));
    QObject::connect(MainWindow->GetButtonCast_Reset(), SIGNAL(clicked()),
            buttons, SLOT(Reset_CastInfo()));


    MainWindow->show();
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
    QFile::copy(":/side_img/resurces/attack_red.png",
                cdir + "/Resurces/side_attack_t1.png");
    QFile::copy(":/side_img/resurces/attack_white.png",
                cdir + "/Resurces/side_attack_t2.png");
    QFile::copy(":/side_img/resurces/defend_red.png",
                cdir + "/Resurces/side_defense_t1.png");
    QFile::copy(":/side_img/resurces/defend_white.png",
                cdir + "/Resurces/side_defense_t2.png");
    QFile::copy(":/side_img/resurces/attack_red.png",
                cdir + "/Resurces/side_none_t1.png");
    QFile::copy(":/side_img/resurces/attack_white.png",
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
    ui->SetCastTeam({ FileControl::ReadFile(cdir + "/Info/Producer.txt"),
        FileControl::ReadFile(cdir + "/Info/Observer1.txt"),
        FileControl::ReadFile(cdir + "/Info/Observer2.txt"),
        FileControl::ReadFile(cdir + "/Info/Caster1.txt"),
        FileControl::ReadFile(cdir + "/Info/Caster2.txt"),
        FileControl::ReadFile(cdir + "/Info/Host.txt"),
        FileControl::ReadFile(cdir + "/Info/Analist1.txt"),
        FileControl::ReadFile(cdir + "/Info/Analist2.txt") });
    ui->SetMutualMapInfo({ FileControl::ReadFile(cdir + "/CurrentMap/Map.txt"), FileControl::ReadFile(cdir + "/CurrentMap/MutualInfo.txt") });
    QVector<QString> util;
    for (int ix = 1; ix < 10; ix++)
        util.push_back(FileControl::ReadFile(cdir + "/Info/Utility" + QString::number(ix) + ".txt"));
    ui->SetUtilityList(util);
}
