#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), upd(new UpdateExtData)
{
    ui->setupUi(this);
    connect(ui->pushButton_swap, SIGNAL(clicked()), this, SLOT(SwapTeams()));
    connect(ui->pushButton_reset, SIGNAL(clicked()), this, SLOT(ResetInput()));
    connect(ui->pushButton_update, SIGNAL(clicked()), this, SLOT(UpdateCM()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete upd;
}


QString MainWindow::GetNameT1 (){
    QString str = ui->lineEdit_t1_name->text();
    qDebug() << "Get team 1 full name: " + str;
    return str;
}

void MainWindow::SetNameT1 (const QString& str){
    ui->lineEdit_t1_name->setText(str);
    qDebug() << "Set team 1 full name: " + str;
}

QString MainWindow::GetNameT2 (){
    QString tbh = ui->lineEdit_t2_name->text();
    qDebug() << "Get team 2 full name: " + tbh;
    return tbh;
}

void MainWindow::SetNameT2 (const QString& str){
    ui->lineEdit_t2_name->setText(str);
    qDebug() << "Set team 2 full name: " + str;
}

QString MainWindow::GetShortNameT1(){
    QString tbh = ui->lineEdit_t1_sn->text();
    qDebug() << "Get team 1 short name: " + tbh;
    return tbh;
}

void MainWindow::SetShortNameT1(const QString& str){
    ui->lineEdit_t1_sn->setText(str);
    qDebug() << "Set team 1 short name: " + str;
}

QString MainWindow::GetShortNameT2(){
    QString tbh = ui->lineEdit_t2_sn->text();
    qDebug() << "Get team 2 short name: " + tbh;
    return tbh;
}

void MainWindow::SetShortNameT2(const QString& str){
    ui->lineEdit_t2_sn->setText(str);
    qDebug() << "Set team 2 short name: " + str;
}

QString MainWindow::GetCurrentMap(){
    QString tbh = ui->comboBox_map->currentText();
    qDebug() << "Get current map: " + tbh;
    return tbh;
}

void MainWindow::SetCurrentMap(const QString&){
    //ui->comboBox_map->;
}

int MainWindow::GetCurrentScoreT1(){
    int tbh = ui->spinBox_t1_score->value();
    qDebug() << "Get current score team 1: " + QString::number(tbh);
    return tbh;
}

void MainWindow::SetCurrentScoreT1(const int& score){
    ui->spinBox_t1_score->setValue(score);
    qDebug() << "Set score team 1: " + QString::number(score);
}

int MainWindow::GetCurrentScoreT2(){
    int tbh = ui->spinBox_t2_score->value();
    qDebug() << "Get current score team 2: " + QString::number(tbh);
    return tbh;
}

void MainWindow::SetCurrentScoreT2(const int& score){
    ui->spinBox_t2_score->setValue(score);
    qDebug() << "Set score team 2: " + QString::number(score);
}

void MainWindow::SwapTeams(){
    qDebug() << "-------Swap full name teams-------";
    QString tbh = GetNameT1();
    SetNameT1(GetNameT2());
    SetNameT2(tbh);
    qDebug() << "-------Swap short name teams------";
    tbh = GetShortNameT1();
    SetShortNameT1(GetShortNameT2());
    SetShortNameT2(tbh);
    qDebug() << "-------Swap score teams-----------";
    int tbhscore = GetCurrentScoreT1();
    SetCurrentScoreT1(GetCurrentScoreT2());
    SetCurrentScoreT2(tbhscore);
}

void MainWindow::ResetInput(){
    qDebug() << "-------Reset Input----------------";
    SetNameT1("");
    SetNameT2("");
    SetShortNameT1("");
    SetShortNameT2("");
    SetCurrentScoreT1(0);
    SetCurrentScoreT2(0);
    //SetCurrentMap("None");
}

void MainWindow::UpdateCM(){
    upd->UpdateNameT1(GetNameT1());
    upd->UpdateNameT2(GetNameT2());
    upd->UpdateShortNameT1(GetShortNameT1());
    upd->UpdateShortNameT2(GetShortNameT2());
    upd->UpdateCurrentMap(GetCurrentMap());

}
