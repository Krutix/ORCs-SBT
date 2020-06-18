#include "buttons.h"

Buttons::Buttons(){

}

Buttons::Buttons(IUserInterface* ui){
    this->ui = ui;
}

void Buttons::SetUI(IUserInterface* ui){
    this->ui = ui;
}

Buttons::~Buttons(){}

void Buttons::Swap_CurrentTeams(){
    qDebug() << "Swap full name teams";
    QString tbh = ui->GetT1_Name();
    ui->SetT1_Name(ui->GetT2_Name());
    ui->SetT2_Name(tbh);
    qDebug() << "Swap short name teams";
    tbh = ui->GetT1_ShortName();
    ui->SetT1_ShortName(ui->GetT2_ShortName());
    ui->SetT2_ShortName(tbh);
    qDebug() << "Swap score teams";
    int tbhscore = ui->GetCMap_ScoreT1();
    ui->SetCMap_ScoreT1(ui->GetCMap_ScoreT2());
    ui->SetCMap_ScoreT2(tbhscore);
    qDebug() << "Swap teams logo";
    tbh = ui->GetT1_Logo();
    ui->SetT1_Logo(ui->GetT2_Logo());
    ui->SetT2_Logo(tbh);
    ui->SetStatus("Team swaped");
}

void Buttons::Reset_CurrentMatch(){
    if (!ui->ActConfirmation("Reset match info?", "Reset match info?"))
        return;
    qDebug() << "Reset Input";
    ui->SetT1_Name("");
    ui->SetT2_Name("");
    ui->SetT1_ShortName("");
    ui->SetT2_ShortName("");
    ui->SetCMap_ScoreT1(0);
    ui->SetCMap_ScoreT2(0);
    ui->SetMutualInfo("");
    ui->SetT1_Logo("");
    ui->SetT2_Logo("");
    //ui->SetCMap("None");
    ui->SetStatus("Match fields reset");
}

void Buttons::Update_CurrentMatch(){
    FileControl::SaveData(cdir + "/CurrentMap/Team1_Name.txt", ui->GetT1_Name());
    FileControl::SaveData(cdir + "/CurrentMap/Team2_Name.txt", ui->GetT2_Name());
    FileControl::SaveData(cdir + "/CurrentMap/Team1_ShortName.txt", ui->GetT1_ShortName());
    FileControl::SaveData(cdir + "/CurrentMap/Team2_ShortName.txt", ui->GetT2_ShortName());
    FileControl::SaveData(cdir + "/CurrentMap/Map.txt", ui->GetCMap_Map());
    FileControl::SaveData(cdir + "/CurrentMap/Score_Team1.txt",
                     QString::number(ui->GetCMap_ScoreT1()));
    FileControl::SaveData(cdir + "/CurrentMap/Score_Team2.txt",
                     QString::number(ui->GetCMap_ScoreT2()));
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
    FileControl::SaveImgPNG(ui->GetT1_Logo(), cdir + "/CurrentMap/logoT1");
    FileControl::SaveImgPNG(ui->GetT2_Logo(), cdir + "/CurrentMap/logoT2");
    ui->SetStatus("Match info update");
}

void Buttons::Update_CastInfo(){
    int i = 1;
    for (auto saveData : ui->GetUtilityList()){
        FileControl::SaveData(cdir + "/Info/Utility" + QString::number(i++) + ".txt", saveData);
    }
    ui->SetStatus("Cast info updated");
}

void Buttons::Reset_CastInfo(){
    if (!ui->ActConfirmation("Reset genetal info?", "Reset genetal info?"))
        return;
    QVector<QString> res (9, "");
    ui->SetUtilityList(res);
    ui->SetStatus("Genetal info reset");
}
