#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow())
{
    ui->setupUi(this);
    setWindowTitle("ORCs Scoreboard Tool");
    utilityList.reserve(9);
    utilityList = { ui->lineEdit_utility1, ui->lineEdit_utility2,
                        ui->lineEdit_utility3, ui->lineEdit_utility4,
                        ui->lineEdit_utility5, ui->lineEdit_utility6,
                        ui->lineEdit_utility7, ui->lineEdit_utility8,
                        ui->lineEdit_utility9 };
}


MainWindow::~MainWindow()
{
    delete ui;
}

QVector<QString> MainWindow::GetUtilitiesText() const
{
    QVector<QString> utilityText;
    utilityText.reserve(9);
    for (int ix = 0; ix < 9; ix++)
        utilityText.push_back(utilityList[ix]->text());
    return utilityText;
}

void MainWindow::SetUtilitiesText(const QVector<QString>& utilityText)
{
    for (int ix = 0; ix < 9; ix++)
        utilityList[ix]->setText(utilityText[ix]);
}

CastTeam MainWindow::GetCastTeamText() const
{
    return { ui->lineEdit_producer_nick->text(), ui->lineEdit_observer1_nick->text(),
    ui->lineEdit_observer2_nick->text(), ui->lineEdit_caster1_nick->text(), ui->lineEdit_caster2_nick->text(),
    ui->lineEdit_host_nick->text(),  ui->lineEdit_analist1_nick->text(), ui->lineEdit_analist2_nick->text() };
}

void MainWindow::SetCastTeamText(const CastTeam& cTeam)
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
