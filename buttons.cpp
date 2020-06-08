#include "buttoms.h"

Buttoms::Buttoms(){}

Buttoms::Buttoms(IUserInterface* ui){
    this->ui = ui;
}

void Buttoms::SetUI(IUserInterface* ui){
    this->ui = ui;
}

void Buttoms::Swap_CurrentTeams(){
    qDebug() << "-------Swap full name teams";
    QString tbh = ui->GetNameT1();
    ui->SetNameT1(ui->GetNameT2());
    ui->SetNameT2(tbh);
    qDebug() << "-------Swap short name teams";
    tbh = ui->GetShortNameT1();
    ui->SetShortNameT1(ui->GetShortNameT2());
    ui->SetShortNameT2(tbh);
    qDebug() << "-------Swap score teams";
    int tbhscore = ui->GetCurrentScoreT1();
    ui->SetCurrentScoreT1(ui->GetCurrentScoreT2());
    ui->SetCurrentScoreT2(tbhscore);
}

void Buttoms::ResetInput_CurrentMatch(){
    qDebug() << "-------Reset Input";
    ui->SetNameT1("");
    ui->SetNameT2("");
    ui->SetShortNameT1("");
    ui->SetShortNameT2("");
    ui->SetCurrentScoreT1(0);
    ui->SetCurrentScoreT2(0);
    //SetCurrentMap("None");
}
/*
void Buttoms::Update_CurrentMatch(){
    upd->UpdateNameT1(GetNameT1());
    upd->UpdateNameT2(GetNameT2());
    upd->UpdateShortNameT1(GetShortNameT1());
    upd->UpdateShortNameT2(GetShortNameT2());
    upd->UpdateCurrentMap(GetCurrentMap());
}
*/
