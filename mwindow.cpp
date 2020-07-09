#include "mwindow.h"

MWindow::MWindow(QWidget *parent)
    :MainWindow(parent)
{}

Team MWindow::GetTeam1()
{
    return { GetTeam1Name(), GetTeam1ShortName(), GetTeam1Logo(), GetTeam1CurrentScore() };
}

Team MWindow::GetTeam2()
{
    return { GetTeam2Name(), GetTeam2ShortName(), GetTeam2Logo(), GetTeam2CurrentScore() };
}

void MWindow::SetTeam1(const Team& team)
{
    SetTeam1Name(team.name);
    SetTeam1ShortName(team.shortName);
    SetTeam1CurrentScore(team.score);
    SetTeam1Logo(team.logoPath);
}

void MWindow::SetTeam2(const Team& team)
{
    SetTeam2Name(team.name);
    SetTeam2ShortName(team.shortName);
    SetTeam2CurrentScore(team.score);
    SetTeam2Logo(team.logoPath);
}

CastTeam MWindow::GetCastTeam()
{
    return { ui->lineEdit_producer_nick->text(), ui->lineEdit_observer1_nick->text(),
    ui->lineEdit_observer2_nick->text(), ui->lineEdit_caster1_nick->text(), ui->lineEdit_caster2_nick->text(),
    ui->lineEdit_host_nick->text(),  ui->lineEdit_analist1_nick->text(), ui->lineEdit_analist2_nick->text() };
}

void MWindow::SetCastTeam(const CastTeam& cTeam)
{
    ui->lineEdit_producer_nick->setText(cTeam.producer);
    ui->lineEdit_observer1_nick->setText(cTeam.observer[0]);
    ui->lineEdit_observer2_nick->setText(cTeam.observer[1]);
    ui->lineEdit_caster1_nick->setText(cTeam.caster[0]);
    ui->lineEdit_caster2_nick->setText(cTeam.caster[1]);
    ui->lineEdit_host_nick->setText(cTeam.host);
    ui->lineEdit_analist1_nick->setText(cTeam.analist[0]);
    ui->lineEdit_analist2_nick->setText(cTeam.analist[1]);
}

const MutualMapInfo MWindow::GetMutualMapInfo()
{
    return { GetCurrentMap(),  GetMutualInfo() };
}

void MWindow::SetMutualMapInfo(const MutualMapInfo& info)
{
    SetCurrentMap(info.currentMap);
    SetMutualInfo(info.mutualInfo);
}


bool MWindow::ActConfirmation(const QString& name, const QString& message)
{
    int conf = QMessageBox::question(this, name, message,
                                     QMessageBox::Yes|QMessageBox::Cancel);
    if (conf == QMessageBox::Yes) {
       return true;
    }
    return false;
}


QVector<QString> MWindow::GetUtilityList(){
    QVector<QString> utilitys;
    utilitys.push_back(ui->lineEdit_utility1->text());
    utilitys.push_back(ui->lineEdit_utility2->text());
    utilitys.push_back(ui->lineEdit_utility3->text());
    utilitys.push_back(ui->lineEdit_utility4->text());
    utilitys.push_back(ui->lineEdit_utility5->text());
    utilitys.push_back(ui->lineEdit_utility6->text());
    utilitys.push_back(ui->lineEdit_utility7->text());
    utilitys.push_back(ui->lineEdit_utility8->text());
    utilitys.push_back(ui->lineEdit_utility9->text());
    return utilitys;
}


QString MWindow::GetSideT1()
{ // TODO Groupe radio buttons
    if (ui->radioButton_side_attack->isChecked())
        return "Attack";
    if (ui->radioButton_side_defence->isChecked())
        return "Defence";
    if (ui->radioButton_side_none->isChecked())
        return "None";
    return "";
}

//void MainWindow::SetSideT1(){}

void MWindow::SetUtilityList(const QVector<QString>& utilitys)
{
    ui->lineEdit_utility1->setText(utilitys[0]);
    ui->lineEdit_utility2->setText(utilitys[1]);
    ui->lineEdit_utility3->setText(utilitys[2]);
    ui->lineEdit_utility4->setText(utilitys[3]);
    ui->lineEdit_utility5->setText(utilitys[4]);
    ui->lineEdit_utility6->setText(utilitys[5]);
    ui->lineEdit_utility7->setText(utilitys[6]);
    ui->lineEdit_utility8->setText(utilitys[7]);
    ui->lineEdit_utility9->setText(utilitys[8]);
}

void MWindow::SetStatus(const QString& status)
{
    ui->statusbar->showMessage(status);
}
