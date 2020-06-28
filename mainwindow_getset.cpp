#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::GetTeam1Name()
{
    return ui->lineEdit_t1_name->text();
}

void MainWindow::SetTeam1Name(const QString& str)
{
    ui->lineEdit_t1_name->setText(str);
}

QString MainWindow::GetTeam2Name()
{
    return ui->lineEdit_t2_name->text();
}

void MainWindow::SetTeam2Name(const QString& str)
{
    ui->lineEdit_t2_name->setText(str);
}

QString MainWindow::GetTeam1ShortName()
{
    return ui->lineEdit_t1_sn->text();
}

void MainWindow::SetTeam1ShortName(const QString& str)
{
    ui->lineEdit_t1_sn->setText(str);
}

QString MainWindow::GetTeam2ShortName()
{
    return ui->lineEdit_t2_sn->text();
}

void MainWindow::SetTeam2ShortName(const QString& str)
{
    ui->lineEdit_t2_sn->setText(str);
}

QString MainWindow::GetCurrentMap()
{
    return ui->comboBox_map->currentText();
}

void MainWindow::SetCurrentMap(const QString& str)
{
    ui->comboBox_map->setCurrentText(str);
}

int MainWindow::GetTeam1CurrentScore()
{
    return ui->spinBox_t1_score->value();
}

void MainWindow::SetTeam1CurrentScore(const int& score)
{
    ui->spinBox_t1_score->setValue(score);
}

int MainWindow::GetTeam2CurrentScore() {
    return ui->spinBox_t2_score->value();
}

void MainWindow::SetTeam2CurrentScore(const int& score)
{
    ui->spinBox_t2_score->setValue(score);
}

QString MainWindow::GetTeam1Logo()
{
    return ui->lineEdit_t1_logo->text();
}

void MainWindow::SetTeam1Logo(const QString& dir)
{
    ui->lineEdit_t1_logo->setText(dir);
}

QString MainWindow::GetTeam2Logo()
{
    return ui->lineEdit_t2_logo->text();
}

void MainWindow::SetTeam2Logo(const QString& dir)
{
    ui->lineEdit_t2_logo->setText(dir);
}

QString MainWindow::GetMutualInfo()
{
    return ui->lineEdit_mutualinfo->text();
}

void MainWindow::SetMutualInfo(const QString& str)
{
    ui->lineEdit_mutualinfo->setText(str);
}
