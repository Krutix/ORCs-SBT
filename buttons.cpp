#include "buttons.h"

Buttons::Buttons() {}

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
    ui->SetTeam1(Team());
    ui->SetTeam2(Team());
    ui->SetMutualMapInfo(MutualMapInfo());
    ui->SetStatus("Match fields reset");
}

void Buttons::Update_CurrentMatch()
{
    const Team Team1 = ui->GetTeam1();
    const Team Team2 = ui->GetTeam2();
    const MutualMapInfo MapInfo = ui->GetMutualMapInfo();
    FileControl::SaveData(cdir + "/CurrentMap/Team1_Name.txt", Team1.name);
    FileControl::SaveData(cdir + "/CurrentMap/Team2_Name.txt", Team2.name);
    FileControl::SaveData(cdir + "/CurrentMap/Team1_ShortName.txt", Team1.shortName);
    FileControl::SaveData(cdir + "/CurrentMap/Team2_ShortName.txt", Team2.shortName);
    FileControl::SaveData(cdir + "/CurrentMap/Map.txt", MapInfo.currentMap);
    FileControl::SaveData(cdir + "/CurrentMap/Score_Team1.txt",
                     QString::number(Team1.score));
    FileControl::SaveData(cdir + "/CurrentMap/Score_Team2.txt",
                     QString::number(Team2.score));
    FileControl::SaveData(cdir + "/CurrentMap/MutualInfo.txt", MapInfo.mutualInfo);
    /*QString side = ui->GetSideT1();
    if (side[0] == "A"){
        FileControl::SaveImgPNG(cdir + "/Resurces/side_attack_t1.png", cdir + "/CurrentMap/sideT1");
        FileControl::SaveImgPNG(cdir + "/Resurces/side_defense_t2.png", cdir + "/CurrentMap/sideT2");
    } else if (side[0] == "D"){
        FileControl::SaveImgPNG(cdir + "/Resurces/side_defense_t1.png", cdir + "/CurrentMap/sideT1");
        FileControl::SaveImgPNG(cdir + "/Resurces/side_attack_t2.png", cdir + "/CurrentMap/sideT2");
    } else if (side[0] == "N"){
        FileControl::SaveImgPNG(cdir + "/Resurces/side_none_t1.png", cdir + "/CurrentMap/sideT1");
        FileControl::SaveImgPNG(cdir + "/Resurces/side_none_t2.png", cdir + "/CurrentMap/sideT2");
    }*/
    FileControl::SaveImgPNG(Team1.logoPath, cdir + "/CurrentMap/logoT1");
    FileControl::SaveImgPNG(Team1.logoPath, cdir + "/CurrentMap/logoT2");
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
