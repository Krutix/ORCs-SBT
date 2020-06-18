#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow()){
    ui->setupUi(this);
    setWindowTitle("ORCs Scoreboard Tool");
}

MainWindow::~MainWindow(){
    delete ui;
}

QString MainWindow::GetT1_Name (){
    return ui->lineEdit_t1_name->text();
}

void MainWindow::SetT1_Name (const QString& str){
    ui->lineEdit_t1_name->setText(str);
}

QString MainWindow::GetT2_Name (){
    return ui->lineEdit_t2_name->text();
}

void MainWindow::SetT2_Name (const QString& str){
    ui->lineEdit_t2_name->setText(str);
}

QString MainWindow::GetT1_ShortName(){
    return ui->lineEdit_t1_sn->text();
}

void MainWindow::SetT1_ShortName(const QString& str){
    ui->lineEdit_t1_sn->setText(str);
}

QString MainWindow::GetT2_ShortName(){
    return ui->lineEdit_t2_sn->text();
}

void MainWindow::SetT2_ShortName(const QString& str){
    ui->lineEdit_t2_sn->setText(str);
}

QString MainWindow::GetCMap_Map(){
    return ui->comboBox_map->currentText();
}

void MainWindow::SetCMap_Map(const QString& str){
    ui->comboBox_map->setCurrentText(str);
}

int MainWindow::GetCMap_ScoreT1(){
    return ui->spinBox_t1_score->value();
}

void MainWindow::SetCMap_ScoreT1(const int& score){
    ui->spinBox_t1_score->setValue(score);
}

int MainWindow::GetCMap_ScoreT2(){
    return ui->spinBox_t2_score->value();
}

void MainWindow::SetCMap_ScoreT2(const int& score){
    ui->spinBox_t2_score->setValue(score);
}

QString MainWindow::GetT1_Logo(){
    return ui->lineEdit_t1_logo->text();
}

void MainWindow::SetT1_Logo(const QString& dir){
     ui->lineEdit_t1_logo->setText(dir);
}

QString MainWindow::GetT2_Logo(){
    return ui->lineEdit_t2_logo->text();
}

void MainWindow::SetT2_Logo(const QString& dir){
     ui->lineEdit_t2_logo->setText(dir);
}

bool MainWindow::ActConfirmation(const QString& name, const QString& message){
    int conf = QMessageBox::question(this, name, message,
                                     QMessageBox::Yes|QMessageBox::Cancel);
    if (conf == QMessageBox::Yes) {
       return true;
    }
    return false;
}

QString MainWindow::GetMutualInfo(){
    return ui->lineEdit_mutualinfo->text();
}

void MainWindow::SetMutualInfo(const QString& str){
    ui->lineEdit_mutualinfo->setText(str);
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


QString MainWindow::GetSideT1(){ // TODO Groupe radio buttons
    if (ui->radioButton_side_attack->isChecked())
        return "Attack";
    if (ui->radioButton_side_defence->isChecked())
        return "Defence";
    if (ui->radioButton_side_none->isChecked())
        return "None";
    return "";
}

//void MainWindow::SetSideT1(){}

void MainWindow::SetUtilityList(const QVector<QString>& utilitys){
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

void MainWindow::SetStatus(const QString& status){
    ui->statusbar->showMessage(status);
}

QObject* MainWindow::GetButtonCMatch_Swap(){
    return ui->pushButton_swap_match;
}

QObject* MainWindow::GetButtonCMatch_Update(){
    return ui->pushButton_update_match;
}

QObject* MainWindow::GetButtonCMatch_Reset(){
    return ui->pushButton_reset_match;
}

QObject* MainWindow::GetButtonCast_Update(){
    return ui->pushButton_update_cast;
}

QObject* MainWindow::GetButtonCast_Reset(){
    return ui->pushButton_reset_cast;
}



void MainWindow::on_toolButton_t1_logo_clicked()
{
    SetT1_Logo(FileControl::GetPath(this, "Select team 1 logo", "(*.png)"));
}

void MainWindow::on_toolButton_4_clicked()
{
    SetT2_Logo(FileControl::GetPath(this, "Select team 2 logo", "(*.png)"));
}
