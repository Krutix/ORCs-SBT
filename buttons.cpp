#include "buttons.h"

Buttons::Buttons(){

}

Buttons::Buttons(IUserInterface* ui){
    this->ui = ui;
}

void Buttons::SetUI(IUserInterface* ui){
    this->ui = ui;
}

Buttons::~Buttons(){
    delete fwrite;
}

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
}

void Buttons::ResetInput_CurrentMatch(){
    qDebug() << "Reset Input";
    ui->SetT1_Name("");
    ui->SetT2_Name("");
    ui->SetT1_ShortName("");
    ui->SetT2_ShortName("");
    ui->SetCMap_ScoreT1(0);
    ui->SetCMap_ScoreT2(0);
    //SetCurrentMap("None");
}

void Buttons::Update_CurrentMatch(){
    fwrite->SaveData("/CurrentMap/Team1_Name.txt", ui->GetT1_Name());
    fwrite->SaveData("/CurrentMap/Team2_Name.txt", ui->GetT2_Name());
    fwrite->SaveData("/CurrentMap/Team1_ShortName.txt", ui->GetT1_ShortName());
    fwrite->SaveData("/CurrentMap/Team2_ShortName.txt", ui->GetT2_ShortName());
    fwrite->SaveData("/CurrentMap/Map.txt", ui->GetCMap_Map());
    fwrite->SaveData("/CurrentMap/Score_Team1.txt", QString::number(ui->GetCMap_ScoreT1()));
    fwrite->SaveData("/CurrentMap/Score_Team2.txt", QString::number(ui->GetCMap_ScoreT2()));
}
