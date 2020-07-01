#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "iuserinterface.h"
#include "filecontrol.h"
#include "texteditor.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IUserInterface
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Team GetTeam1() override;
    void SetTeam1(const Team&) override;
    Team GetTeam2() override;
    void SetTeam2(const Team&) override;

    const MutualMapInfo GetMutualMapInfo() override;
    void SetMutualMapInfo(const MutualMapInfo&) override;

    CastTeam GetCastTeam() override;
    void SetCastTeam(const CastTeam& CastTeam) override;

    QString GetCurrentMap();
    void SetCurrentMap(const QString&);

    QString GetTeam1Name ();
    void SetTeam1Name (const QString&);
    QString GetTeam2Name ();
    void SetTeam2Name (const QString&);

    QString GetTeam1ShortName();
    void SetTeam1ShortName(const QString&);
    QString GetTeam2ShortName();
    void SetTeam2ShortName(const QString&);

    int GetTeam1CurrentScore();
    void SetTeam1CurrentScore(const int&);
    int GetTeam2CurrentScore();
    void SetTeam2CurrentScore(const int&);

    bool ActConfirmation(const QString& name, const QString& message) override;

    QVector<QString> GetUtilityList() override;
    void SetUtilityList(const QVector<QString>&) override;

    QString GetMutualInfo();
    void SetMutualInfo(const QString&);

    QString GetTeam1Logo();
    void SetTeam1Logo(const QString&);
    QString GetTeam2Logo();
    void SetTeam2Logo(const QString&);

    QString GetSideT1() override; //A - attack | D - defence | N - none
    //void SetSideT1(const QString&);

    void SetStatus(const QString&) override;

    QObject* GetButtonCast_Update();
    QObject* GetButtonCast_Reset();
    QObject* GetButtonCMatch_Swap();
    QObject* GetButtonCMatch_Update();
    QObject* GetButtonCMatch_Reset();

private slots:
    void on_toolButton_t1_logo_clicked();
    void on_toolButton_t2_logo_clicked();

    void on_toolButton_utility7_clicked();
    void on_toolButton_utility8_clicked();
    void on_toolButton_utility9_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
