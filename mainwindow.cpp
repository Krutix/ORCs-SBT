#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow()){
    ui->setupUi(this);
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

void MainWindow::SetCMap_Map(const QString&){
    //ui->comboBox_map->;
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

bool MainWindow::ActConfirmation(const QString& name, const QString& message){
    int conf = QMessageBox::question(this, name, message,
                                     QMessageBox::Yes|QMessageBox::Cancel);
    if (conf == QMessageBox::Yes) {
       return true;
    }
    return false;
}

void MainWindow::SetStatus(const QString& status){
    ui->statusbar->showMessage(status);
}

QObject* MainWindow::GetObjButtonCMatch_Swap(){
    return ui->pushButton_swap;
}

QObject* MainWindow::GetButtonCMatch_Update(){
    return ui->pushButton_update;
}

QObject* MainWindow::GetButtonCMatch_Reset(){
    return ui->pushButton_reset;
}
