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

void MainWindow::on_toolButton_t1_logo_clicked()
{
    SetTeam1Logo(FileControl::GetPath(this, "Select team 1 logo", "(*.png)"));
}

void MainWindow::on_toolButton_t2_logo_clicked()
{
    SetTeam1Logo(FileControl::GetPath(this, "Select team 2 logo", "(*.png)"));
}

void MainWindow::on_toolButton_utility7_clicked()
{
    TextEditor te(this);
    te.setWindowTitle("Utility7");
    te.SetText(ui->lineEdit_utility7->text());
    if (te.exec())
        ui->lineEdit_utility7->setText(te.GetText());
}

void MainWindow::on_toolButton_utility8_clicked()
{
    TextEditor te(this);
    te.setWindowTitle("Utility8");
    te.SetText(ui->lineEdit_utility8->text());
    if (te.exec())
        ui->lineEdit_utility8->setText(te.GetText());
}

void MainWindow::on_toolButton_utility9_clicked()
{
    TextEditor te(this);
    te.setWindowTitle("Utility9");
    te.SetText(ui->lineEdit_utility9->text());
    if (te.exec())
        ui->lineEdit_utility9->setText(te.GetText());
}
