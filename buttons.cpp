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

    fwrite->SaveDataInDir("/CurrentMap/Team1_Name.txt", ui->GetT1_Name());
    fwrite->SaveDataInDir("/CurrentMap/Team2_Name.txt", ui->GetT2_Name());
    fwrite->SaveDataInDir("/CurrentMap/Team1_ShortName.txt", ui->GetT1_ShortName());
    fwrite->SaveDataInDir("/CurrentMap/Team2_ShortName.txt", ui->GetT2_ShortName());
    fwrite->SaveDataInDir("/CurrentMap/Map.txt", ui->GetCMap_Map());
    fwrite->SaveDataInDir("/CurrentMap/Score_Team1.txt",
                     QString::number(ui->GetCMap_ScoreT1()));
    fwrite->SaveDataInDir("/CurrentMap/Score_Team2.txt",
                     QString::number(ui->GetCMap_ScoreT2()));
    fwrite->SaveDataInDir("/CurrentMap/MutualInfo.txt", ui->GetMutualInfo());
    QString side = ui->GetSideT1();
    if (side[0] == "A"){
        fwrite->SaveImgToDir(QApplication::applicationDirPath()
                        + "/Resurces/side_attack_t1.png", "/CurrentMap/sideT1");
        fwrite->SaveImgToDir(QApplication::applicationDirPath()
                        + "/Resurces/side_defense_t2.png", "/CurrentMap/sideT2");
    } else if (side[0] == "D"){
        fwrite->SaveImgToDir(QApplication::applicationDirPath()
                        + "/Resurces/side_defense_t1.png", "/CurrentMap/sideT1");
        fwrite->SaveImgToDir(QApplication::applicationDirPath()
                        + "/Resurces/side_attack_t2.png", "/CurrentMap/sideT2");
    } else if (side[0] == "N"){
        fwrite->SaveImgToDir(QApplication::applicationDirPath()
                        + "/Resurces/side_none_t1.png", "/CurrentMap/sideT1");
        fwrite->SaveImgToDir(QApplication::applicationDirPath()
                        + "/Resurces/side_none_t2.png", "/CurrentMap/sideT2");
    }
    fwrite->SaveImgToDir(ui->GetT1_Logo(), "/CurrentMap/logoT1");
    fwrite->SaveImgToDir(ui->GetT2_Logo(), "/CurrentMap/logoT2");
    ui->SetStatus("Match data update");
}

void Buttons::Update_CastInfo(){
    int i = 1;
    for (auto saveData : ui->GetUtilityList()){
        fwrite->SaveDataInDir("/Info/Utility" + QString::number(i++) + ".txt", saveData);
    }
    ui->SetStatus("Cast info updated");
}

void Buttons::Reset_CastInfo(){
    if (!ui->ActConfirmation("Reset cast info?", "Reset cast info?"))
        return;
    QVector<QString> res (9, "");
    ui->SetUtilityList(res);
    ui->SetStatus("Cast info reseted");
}
