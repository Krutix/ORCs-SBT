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
    //ui->SetCMap("None");
    ui->SetStatus("Match fields reset");
}

void Buttons::Update_CurrentMatch(){

    fwrite->SaveData("/CurrentMap/Team1_Name.txt", ui->GetT1_Name());
    fwrite->SaveData("/CurrentMap/Team2_Name.txt", ui->GetT2_Name());
    fwrite->SaveData("/CurrentMap/Team1_ShortName.txt", ui->GetT1_ShortName());
    fwrite->SaveData("/CurrentMap/Team2_ShortName.txt", ui->GetT2_ShortName());
    fwrite->SaveData("/CurrentMap/Map.txt", ui->GetCMap_Map());
    fwrite->SaveData("/CurrentMap/Score_Team1.txt",
                     QString::number(ui->GetCMap_ScoreT1()));
    fwrite->SaveData("/CurrentMap/Score_Team2.txt",
                     QString::number(ui->GetCMap_ScoreT2()));
    fwrite->SaveData("/CurrentMap/MutualInfo.txt", ui->GetMutualInfo());
    QString side = ui->GetSideT1();
    if (side[0] == "A"){
        fwrite->ReplaceFile(QApplication::applicationDirPath()
                            + "/Resurces/side_attack_T1.png",
                            "/CurrentMap/sideT1.png");
        fwrite->SaveData("/CurrentMap/sideT1.txt",
                         QApplication::applicationDirPath()
                         + "/Resurces/side_attack_T1.png");
        fwrite->ReplaceFile(QApplication::applicationDirPath()
                            + "/Resurces/side_defense_T2.png",
                            "/CurrentMap/sideT2.png");
        fwrite->SaveData("/CurrentMap/sideT2.txt",
                         QApplication::applicationDirPath()
                         + "/Resurces/side_defense_T2.png");
    } else if (side[0] == "D"){
        fwrite->ReplaceFile(QApplication::applicationDirPath()
                            + "/Resurces/side_defense_T1.png",
                            "/CurrentMap/sideT1.png");
        fwrite->SaveData("/CurrentMap/sideT1.txt",
                         QApplication::applicationDirPath()
                         + "/Resurces/side_defense_T1.png");
        fwrite->ReplaceFile(QApplication::applicationDirPath()
                            + "/Resurces/side_attack_T2.png",
                            "/CurrentMap/sideT2.png");
        fwrite->SaveData("/CurrentMap/sideT2.txt",
                         QApplication::applicationDirPath()
                         + "/Resurces/side_attack_T2.png");
    } else if (side[0] == "N"){
        fwrite->ReplaceFile(QApplication::applicationDirPath()
                            + "/Resurces/side_none_T1.png",
                            "/CurrentMap/sideT1.png");
        fwrite->SaveData("/CurrentMap/sideT1.txt",
                         QApplication::applicationDirPath()
                         + "/Resurces/side_none_T1.png");
        fwrite->ReplaceFile(QApplication::applicationDirPath()
                            + "/Resurces/side_none_T2.png",
                            "/CurrentMap/sideT2.png");
        fwrite->SaveData("/CurrentMap/sideT2.txt",
                         QApplication::applicationDirPath()
                         + "/Resurces/side_none_T2.png");
    }
    fwrite->ReplaceFile(ui->GetT1_Logo(),
                        "/CurrentMap/logoT1.png");
    fwrite->SaveData("/CurrentMap/logoT1.txt",
                     ui->GetT1_Logo());
    fwrite->ReplaceFile(ui->GetT2_Logo(),
                        "/CurrentMap/logoT2.png");
    fwrite->SaveData("/CurrentMap/logoT2.txt",
                     ui->GetT2_Logo());
    ui->SetStatus("Match data update");
}

void Buttons::Update_CastInfo(){
    int i = 1;
    for (auto saveData : ui->GetUtilityList()){
        fwrite->SaveData("/Info/Utility" + QString::number(i++) + ".txt", saveData);
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
