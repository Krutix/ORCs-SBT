#include "mainwindow.h"
#include "iuserinterface.h"
#include "buttons.h"

#include <QObject>
#include <memory>
#include <QDebug>
#include <QFile>
#include <windows.h>

void StartFoldersCheck();
void ResurcesDefault();
QString ReadFile(const QString& dir);
void RestoreUIData(IUserInterface* UI);
void showInGraphicalShell(QWidget *parent, const QString &pathIn);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartFoldersCheck();
    ResurcesDefault();

    MainWindow* MWindow = new MainWindow();
    Buttons *buttons = new Buttons(MWindow);

    RestoreUIData(MWindow);

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

void RestoreUIData(IUserInterface* ui){
    QString cdir = QApplication::applicationDirPath();
    ui->SetT1_Name(ReadFile(cdir + "/CurrentMap/Team1_Name.txt"));
    ui->SetT2_Name(ReadFile(cdir + "/CurrentMap/Team2_Name.txt"));
    ui->SetT1_ShortName(ReadFile(cdir + "/CurrentMap/Team1_ShortName.txt"));
    ui->SetT2_ShortName(ReadFile(cdir + "/CurrentMap/Team2_ShortName.txt"));
    ui->SetCMap_ScoreT1(ReadFile(cdir + "/CurrentMap/Score_Team1.txt").toInt());
    ui->SetCMap_ScoreT2(ReadFile(cdir + "/CurrentMap/Score_Team2.txt").toInt());
    ui->SetT1_Logo(ReadFile(cdir + "/CurrentMap/logoT1.txt"));
    ui->SetT2_Logo(ReadFile(cdir + "/CurrentMap/logoT2.txt"));
    ui->SetMutualInfo(ReadFile(cdir + "/CurrentMap/MutualInfo.txt"));
    QVector<QString> util;
    for (int ix = 1; ix < 10; ix++)
        util.push_back(ReadFile(cdir + "/Info/Utility" + QString::number(ix) + ".txt"));
    ui->SetUtilityList(util);
}

QString ReadFile(const QString& dir){
    QString tbh {};
    if (QFile(dir).exists()){
        QFile file (dir);
        file.open(QIODevice::ReadOnly);
        tbh = file.readAll();
        file.close();
    }
    return tbh;
}
