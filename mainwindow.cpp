#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow())
{
    ui->setupUi(this);
    setWindowTitle("ORCs SBT");
    utilitiesList.reserve(9);
    utilitiesList = { ui->lineEdit_utility1, ui->lineEdit_utility2,
                        ui->lineEdit_utility3, ui->lineEdit_utility4,
                        ui->lineEdit_utility5, ui->lineEdit_utility6,
                        ui->lineEdit_utility7, ui->lineEdit_utility8,
                        ui->lineEdit_utility9 };
    playersT1 = { ui->lineEdit_t1_nick_p1, ui->lineEdit_t1_nick_p2,
                ui->lineEdit_t1_nick_p3, ui->lineEdit_t1_nick_p4,
                ui->lineEdit_t1_nick_p5 };
    playersT2 = { ui->lineEdit_t2_nick_p1, ui->lineEdit_t2_nick_p2,
                ui->lineEdit_t2_nick_p3, ui->lineEdit_t2_nick_p4,
                ui->lineEdit_t2_nick_p5 };
    playersHeroT1 = { ui->comboBox_t1_hero_p1, ui->comboBox_t1_hero_p2,
                ui->comboBox_t1_hero_p3, ui->comboBox_t1_hero_p4,
                ui->comboBox_t1_hero_p5 };
    playersHeroT2 = { ui->comboBox_t2_hero_p1, ui->comboBox_t2_hero_p2,
                ui->comboBox_t2_hero_p3, ui->comboBox_t2_hero_p4,
                ui->comboBox_t2_hero_p5 };
    QStringList HeroList = { "None", "Breach", "Brimstone", "Cypher", "Jett",
                             "Omen", "Phoenix", "Raze", "Reyna", "Sage",
                             "Sova", "Viper" };
    for (auto playersHero : playersHeroT1)
        playersHero->addItems(HeroList);
    for (auto playersHero : playersHeroT2)
        playersHero->addItems(HeroList);

    /* Tips setup */

    ui->lineEdit_t1_name->setToolTip("/CurrentMap/Team1_Name.txt");
    ui->lineEdit_t2_name->setToolTip("/CurrentMap/Team2_Name.txt");
    ui->lineEdit_t1_sn->setToolTip("/CurrentMap/Team1_ShortName.txt");
    ui->lineEdit_t2_sn->setToolTip("/CurrentMap/Team2_ShortName.txt");

    ui->spinBox_t1_score->setToolTip("/CurrentMap/Score_Team1.txt");
    ui->spinBox_t2_score->setToolTip("/CurrentMap/Score_Team2.txt");

    ui->radioButton_side_attack->setToolTip("/CurrentMap/sideT1, /CurrentMap/sideT2");
    ui->radioButton_side_defence->setToolTip("/CurrentMap/sideT1, /CurrentMap/sideT2");
    ui->radioButton_side_none->setToolTip("/CurrentMap/sideT1, /CurrentMap/sideT2");
    ui->comboBox_map->setToolTip("/CurrentMap/Map.txt");
    ui->lineEdit_mutualinfo->setToolTip("/CurrentMap/MutualInfo.txt");

    ui->lineEdit_t1_logo->setToolTip("/CurrentMap/logoT1");
    ui->lineEdit_t2_logo->setToolTip("/CurrentMap/logoT2");

    ui->lineEdit_producer_nick->setToolTip("/Info/Producer.txt");
    ui->lineEdit_observer1_nick->setToolTip("/Info/Observer1.txt");
    ui->lineEdit_observer2_nick->setToolTip("/Info/Observer2.txt");
    ui->lineEdit_caster1_nick->setToolTip("/Info/Caster1.txt");
    ui->lineEdit_caster2_nick->setToolTip("/Info/Caster2.txt");
    ui->lineEdit_host_nick->setToolTip("/Info/Host.txt");
    ui->lineEdit_analist1_nick->setToolTip("/Info/Analist1.txt");
    ui->lineEdit_analist2_nick->setToolTip("/Info/Analist2.txt");

    for (int i = 0; i < 9; i++)
        utilitiesList[i]->setToolTip("/Info/Utility" + QString::number(i + 1) + ".txt");

    for (int i = 0; i < 5; i++) {
        playersT1[i]->setToolTip("/Players/T1Player" + QString::number(i + 1) + "Nick.txt");
        playersT2[i]->setToolTip("/Players/T2Player" + QString::number(i + 1) + "Nick.txt");
        playersHeroT1[i]->setToolTip("/Players/T1Player" + QString::number(i + 1) + "Hero");
        playersHeroT2[i]->setToolTip("/Players/T2Player" + QString::number(i + 1) + "Hero");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::GetUtilitiesText() const
{
    QStringList utilityText;
    utilityText.reserve(9);
    for (int ix = 0; ix < 9; ix++)
        utilityText.push_back(utilitiesList[ix]->text());
    return utilityText;
}

void MainWindow::SetUtilitiesText(const QStringList& utilityText)
{
    for (int ix = 0; ix < 9; ix++)
        utilitiesList[ix]->setText(utilityText[ix]);
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

QStringList MainWindow::GetTeam1PlayersNick()
{
    return { playersT1[0]->text(), playersT1[1]->text(), playersT1[2]->text(),
        playersT1[3]->text(), playersT1[4]->text() };
}

void MainWindow::SetTeam1PlayersNick(const QStringList& list)
{
    for (int i = 0; i < 5; i++)
        playersT1[i]->setText(list[i]);
}

QStringList MainWindow::GetTeam2PlayersNick()
{
    return { playersT2[0]->text(), playersT2[1]->text(), playersT2[2]->text(),
        playersT2[3]->text(), playersT2[4]->text() };
}

void MainWindow::SetTeam2PlayersNick(const QStringList& list)
{
    for (int i = 0; i < 5; i++)
        playersT2[i]->setText(list[i]);
}

QStringList MainWindow::GetTeam1PlayersHero()
{
    return { playersHeroT1[0]->currentText(), playersHeroT1[1]->currentText(),
                playersHeroT1[2]->currentText(), playersHeroT1[3]->currentText(),
                playersHeroT1[4]->currentText() };
}

void MainWindow::SetTeam1PlayersHero(const QStringList& list)
{
    for (int i = 0; i < 5; i++)
        playersHeroT1[i]->setCurrentText(list[i]);
}

QStringList MainWindow::GetTeam2PlayersHero()
{
    return { playersHeroT2[0]->currentText(), playersHeroT2[1]->currentText(),
                playersHeroT2[2]->currentText(), playersHeroT2[3]->currentText(),
                playersHeroT2[4]->currentText() };
}

void MainWindow::SetTeam2PlayersHero(const QStringList& list)
{
    for (int i = 0; i < 5; i++)
        playersHeroT2[i]->setCurrentText(list[i]);
}

void MainWindow::on_toolButton_t1_logo_clicked()
{
    SetTeam1Logo(FileControl::GetPath(this, "Select team 1 logo", "(*.png)"));
}

void MainWindow::on_toolButton_t2_logo_clicked()
{
    SetTeam2Logo(FileControl::GetPath(this, "Select team 2 logo", "(*.png)"));
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

void MainWindow::on_actionGit_Hub_triggered()
{
    int conf = QMessageBox::question(this, "Open external url?",
                                     "Press Yes to open external url\n"
                                     "in your default browser",
                                     QMessageBox::Yes|QMessageBox::Cancel);
    if (conf == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl(
                "https://github.com/Krutix/ORCs-Scoreboard-Tool"));
    }
}

void MainWindow::on_actionAbout_ORCs_SBT_triggered()
{
    about aboutWindow(this);
    aboutWindow.exec();
}
