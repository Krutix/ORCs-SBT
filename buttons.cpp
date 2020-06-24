#include "buttons.h"

Buttons::Buttons()
{

}

Buttons::Buttons(IUserInterface* ui)
{
    this->ui = ui;
}

void Buttons::SetUI(IUserInterface* ui)
{
    this->ui = ui;
}

Buttons::~Buttons(){}

void Buttons::Swap_CurrentTeams()
{
    Team team1 (ui->GetTeam1());
    ui->SetTeam1(ui->GetTeam2());
    ui->SetTeam2(team1);
}

void Buttons::Reset_CurrentMatch()
{
    if (!ui->ActConfirmation("Reset match info?", "Reset match info?"))
        return;
    qDebug() << "Reset Input";
    ui->SetTeam1Name("");
    ui->SetTeam2Name("");
    ui->SetTeam1ShortName("");
    ui->SetTeam2ShortName("");
    ui->SetTeam1CurrentScore(0);
    ui->SetTeam2CurrentScore(0);
    ui->SetMutualInfo("");
    ui->SetTeam1Logo("");
    ui->SetTeam2Logo("");
    //ui->SetCMap("None");
    ui->SetStatus("Match fields reset");
}

void Buttons::Update_CurrentMatch()
{
    FileControl::SaveData(cdir + "/CurrentMap/Team1_Name.txt", ui->GetTeam1Name());
    FileControl::SaveData(cdir + "/CurrentMap/Team2_Name.txt", ui->GetTeam2Name());
    FileControl::SaveData(cdir + "/CurrentMap/Team1_ShortName.txt", ui->GetTeam1ShortName());
    FileControl::SaveData(cdir + "/CurrentMap/Team2_ShortName.txt", ui->GetTeam2ShortName());
    FileControl::SaveData(cdir + "/CurrentMap/Map.txt", ui->GetCurrentMap());
    FileControl::SaveData(cdir + "/CurrentMap/Score_Team1.txt",
                     QString::number(ui->GetTeam1CurrentScore()));
    FileControl::SaveData(cdir + "/CurrentMap/Score_Team2.txt",
                     QString::number(ui->GetTeam2CurrentScore()));
    FileControl::SaveData(cdir + "/CurrentMap/MutualInfo.txt", ui->GetMutualInfo());
    QString side = ui->GetSideT1();
    if (side[0] == "A"){
        FileControl::SaveImgPNG(cdir + "/Resurces/side_attack_t1.png", cdir + "/CurrentMap/sideT1");
        FileControl::SaveImgPNG(cdir + "/Resurces/side_defense_t2.png", cdir + "/CurrentMap/sideT2");
    } else if (side[0] == "D"){
        FileControl::SaveImgPNG(cdir + "/Resurces/side_defense_t1.png", cdir + "/CurrentMap/sideT1");
        FileControl::SaveImgPNG(cdir + "/Resurces/side_attack_t2.png", cdir + "/CurrentMap/sideT2");
    } else if (side[0] == "N"){
        FileControl::SaveImgPNG(cdir + "/Resurces/side_none_t1.png", cdir + "/CurrentMap/sideT1");
        FileControl::SaveImgPNG(cdir + "/Resurces/side_none_t2.png", cdir + "/CurrentMap/sideT2");
    }
    FileControl::SaveImgPNG(ui->GetTeam1Logo(), cdir + "/CurrentMap/logoT1");
    FileControl::SaveImgPNG(ui->GetTeam2Logo(), cdir + "/CurrentMap/logoT2");
    ui->SetStatus("Match info update");
}

void Buttons::Update_CastInfo()
{
    int i = 1;
    for (auto saveData : ui->GetUtilityList()){
        FileControl::SaveData(cdir + "/Info/Utility" + QString::number(i++) + ".txt", saveData);
    }
    ui->SetStatus("Cast info updated");
}

void Buttons::Reset_CastInfo()
{
    if (!ui->ActConfirmation("Reset genetal info?", "Reset genetal info?"))
        return;
    QVector<QString> res (9, "");
    ui->SetUtilityList(res);
    ui->SetStatus("Genetal info reset");
}
