#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::GetNameT1 (){
    QString tbh = ui->lineEdit_t1_name->text();
    qDebug() << "Getter team 1 full name <" + tbh + ">";
    return tbh;
}

void MainWindow::SetNameT1 (const QString&){

}

QString MainWindow::GetNameT2 (){
    QString tbh = ui->lineEdit_t2_name->text();
    qDebug() << "Getter team 2 full name <" + tbh + ">";
    return tbh;
}

void MainWindow::SetNameT2 (const QString&){

}

QString MainWindow::GetShortNameT1(){
    QString tbh = ui->lineEdit_t1_sn->text();
    qDebug() << "Getter team 1 short name <" + tbh + ">";
    return tbh;
}

void MainWindow::SetShortNameT1(const QString&){

}

QString MainWindow::GetShortNameT2(){
    QString tbh = ui->lineEdit_t2_sn->text();
    qDebug() << "Getter team 2 short name <" + tbh + ">";
    return tbh;
}

void MainWindow::SetShortNameT2(const QString&){

}

QString MainWindow::GetCurrentMap(){
    QString tbh = ui->comboBox_map->currentText();
    qDebug() << "Getter current map <" + tbh + ">";
    return tbh;
}

void MainWindow::SetCurrentMap(const QString&){

}

QString MainWindow::GetCurrentScoreT1(){
    QString tbh = ui->spinBox_t1_score->text();
    qDebug() << "Getter current score team 1 <" + tbh + ">";
    return tbh;
}

void MainWindow::SetCurrentScoreT1(const int&){

}

QString MainWindow::GetCurrentScoreT2(){
    QString tbh = ui->spinBox_t1_score->text();
    qDebug() << "Getter current score team 2 <" + tbh + ">";
    return tbh;
}

void MainWindow::SetCurrentScoreT2(const int&){

}
