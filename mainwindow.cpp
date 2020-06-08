#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow())
{
    ui->setupUi(this);
    //connect(ui->pushButton_swap, SIGNAL(clicked()),
    //        buttoms, SLOT(Swap_CurrentTeams()));
    //connect(ui->pushButton_reset, SIGNAL(clicked()),
    //        buttoms, SLOT(ResetInput_CurrentMatch()));
    //connect(ui->pushButton_update, SIGNAL(clicked()),
    //        this, SLOT(buttoms->Update_CurrentMatch()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::GetNameT1 (){
    return ui->lineEdit_t1_name->text();
}

void MainWindow::SetNameT1 (const QString& str){
    ui->lineEdit_t1_name->setText(str);
}

QString MainWindow::GetNameT2 (){
    return ui->lineEdit_t2_name->text();
}

void MainWindow::SetNameT2 (const QString& str){
    ui->lineEdit_t2_name->setText(str);
}

QString MainWindow::GetShortNameT1(){
    return ui->lineEdit_t1_sn->text();
}

void MainWindow::SetShortNameT1(const QString& str){
    ui->lineEdit_t1_sn->setText(str);
}

QString MainWindow::GetShortNameT2(){
    return ui->lineEdit_t2_sn->text();
}

void MainWindow::SetShortNameT2(const QString& str){
    ui->lineEdit_t2_sn->setText(str);
}

QString MainWindow::GetCurrentMap(){
    return ui->comboBox_map->currentText();
}

void MainWindow::SetCurrentMap(const QString&){
    //ui->comboBox_map->;
}

int MainWindow::GetCurrentScoreT1(){
    return ui->spinBox_t1_score->value();
}

void MainWindow::SetCurrentScoreT1(const int& score){
    ui->spinBox_t1_score->setValue(score);
}

int MainWindow::GetCurrentScoreT2(){
    return ui->spinBox_t2_score->value();
}

void MainWindow::SetCurrentScoreT2(const int& score){
    ui->spinBox_t2_score->setValue(score);
}

QObject* MainWindow::GetButtonSwap_Current(){
    return ui->pushButton_swap;
}

QObject* MainWindow::GetButtonUpdate_Current(){
    return ui->pushButton_update;
}

QObject* MainWindow::GetButtonReset_Current(){
    return ui->pushButton_reset;
}
