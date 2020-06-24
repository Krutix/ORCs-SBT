#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow())
{
    ui->setupUi(this);
    setWindowTitle("ORCs Scoreboard Tool");
}

MainWindow::~MainWindow()
{
    delete ui;
}

Team MainWindow::GetTeam1() 
{
    return { GetTeam1Name(), GetTeam1ShortName(), GetTeam1Logo(), GetTeam1CurrentScore() };
}

Team MainWindow::GetTeam2() 
{
    return { GetTeam2Name(), GetTeam2ShortName(), GetTeam2Logo(), GetTeam2CurrentScore() };
}

void MainWindow::SetTeam1(const Team& team) 
{
    SetTeam1Name(team.name);
    SetTeam1ShortName(team.shortName);
    SetTeam1CurrentScore(team.score);
    SetTeam1Logo(team.logoPath);
}

void MainWindow::SetTeam2(const Team& team) 
{
    SetTeam2Name(team.name);
    SetTeam2ShortName(team.shortName);
    SetTeam2CurrentScore(team.score);
    SetTeam2Logo(team.logoPath);
}

const MutualMapInfo MainWindow::GetMutualMapInfo() 
{
    return { GetCurrentMap(),  GetMutualInfo() };
}

void MainWindow::SetMutualMapInfo(const MutualMapInfo& info)
{
    SetCurrentMap(info.currentMap);
    SetMutualInfo(info.mutualInfo);
}


bool MainWindow::ActConfirmation(const QString& name, const QString& message)
{
    int conf = QMessageBox::question(this, name, message,
                                     QMessageBox::Yes|QMessageBox::Cancel);
    if (conf == QMessageBox::Yes) {
       return true;
    }
    return false;
}


QVector<QString> MainWindow::GetUtilityList(){
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


QString MainWindow::GetSideT1()
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

void MainWindow::SetUtilityList(const QVector<QString>& utilitys)
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

void MainWindow::SetStatus(const QString& status)
{
    ui->statusbar->showMessage(status);
}

QObject* MainWindow::GetButtonCMatch_Swap()
{
    return ui->pushButton_swap_match;
}

QObject* MainWindow::GetButtonCMatch_Update()
{
    return ui->pushButton_update_match;
}

QObject* MainWindow::GetButtonCMatch_Reset()
{
    return ui->pushButton_reset_match;
}

QObject* MainWindow::GetButtonCast_Update()
{
    return ui->pushButton_update_cast;
}

QObject* MainWindow::GetButtonCast_Reset()
{
    return ui->pushButton_reset_cast;
}

void MainWindow::on_toolButton_t1_logo_clicked()
{
    SetTeam1Logo(FileControl::GetPath(this, "Select team 1 logo", "(*.png)"));
}

void MainWindow::on_toolButton_4_clicked()
{
    SetTeam2Logo(FileControl::GetPath(this, "Select team 2 logo", "(*.png)"));
}
