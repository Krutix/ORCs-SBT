#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filecontrol.h"
#include "texteditor.h"
#include "ui_mainwindow.h"
#include "castom_data.h"
#include "about.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <QDebug>
#include <memory>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    inline QString GetCurrentMap() const { return ui->comboBox_map->currentText(); }
    inline void SetCurrentMap(const QString& str) { ui->comboBox_map->setCurrentText(str); }

    inline QString GetTeam1Name () const { return ui->lineEdit_t1_name->text(); }
    inline void SetTeam1Name (const QString& str) { ui->lineEdit_t1_name->setText(str); }
    inline QString GetTeam2Name () const { return ui->lineEdit_t2_name->text(); }
    inline void SetTeam2Name (const QString& str) { ui->lineEdit_t2_name->setText(str); }

    inline QString GetTeam1ShortName() const {return ui->lineEdit_t1_sn->text();}
    inline void SetTeam1ShortName(const QString& str) { ui->lineEdit_t1_sn->setText(str); }
    inline QString GetTeam2ShortName() const { return ui->lineEdit_t2_sn->text(); }
    inline void SetTeam2ShortName(const QString& str) { ui->lineEdit_t2_sn->setText(str); }

    inline int GetTeam1CurrentScore() const { return ui->spinBox_t1_score->value(); }
    inline void SetTeam1CurrentScore(const int& score) { ui->spinBox_t1_score->setValue(score); }
    inline int GetTeam2CurrentScore() const { return ui->spinBox_t2_score->value(); }
    inline void SetTeam2CurrentScore(const int& score) { ui->spinBox_t2_score->setValue(score); }

    inline QString GetMutualInfo() const { return ui->lineEdit_mutualinfo->text(); }
    inline void SetMutualInfo(const QString& str){ ui->lineEdit_mutualinfo->setText(str); }

    inline QString GetTeam1Logo() const { return ui->lineEdit_t1_logo->text(); }
    inline void SetTeam1Logo(const QString& dir) { ui->lineEdit_t1_logo->setText(dir); }
    inline QString GetTeam2Logo() const { return ui->lineEdit_t2_logo->text(); }
    inline void SetTeam2Logo(const QString& dir) { ui->lineEdit_t2_logo->setText(dir); }

    QVector<QString> GetUtilitiesText() const;
    void SetUtilitiesText(const QVector<QString>&);

    CastTeam GetCastTeamText() const;
    void SetCastTeamText(const CastTeam&);

    inline QString GetSide()
    {
        if (ui->buttonGroup_side->checkedButton())
            return ui->buttonGroup_side->checkedButton()->text();
        return "0";
    }

    inline QObject* GetButtonCast_Update() const { return ui->pushButton_update_cast; }
    inline QObject* GetButtonCast_Reset() const { return ui->pushButton_reset_cast; }
    inline QObject* GetButtonCMatch_Swap() const { return ui->pushButton_swap_match; }
    inline QObject* GetButtonCMatch_Update() const { return ui->pushButton_update_match; }
    inline QObject* GetButtonCMatch_Reset() const { return ui->pushButton_reset_match; }

private slots:
    void on_toolButton_t1_logo_clicked();
    void on_toolButton_t2_logo_clicked();

    void on_toolButton_utility7_clicked();
    void on_toolButton_utility8_clicked();
    void on_toolButton_utility9_clicked();

    void on_actionGit_Hub_triggered();

    void on_actionAbout_ORCs_SBT_triggered();

protected:
    Ui::MainWindow *ui;

private:
    QVector<QLineEdit*> utilitiesList;
};
#endif // MAINWINDOW_H
