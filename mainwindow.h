#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "buttons.h"
#include "iuserinterface.h"
#include "filecontrol.h"
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

    QString GetCurrentMap() override;
    void SetCurrentMap(const QString&) override;

    QString GetTeam1Name () override;
    void SetTeam1Name (const QString&) override;
    QString GetTeam2Name () override;
    void SetTeam2Name (const QString&) override;

    QString GetTeam1ShortName() override;
    void SetTeam1ShortName(const QString&) override;
    QString GetTeam2ShortName() override;
    void SetTeam2ShortName(const QString&) override;

    int GetTeam1CurrentScore() override;
    void SetTeam1CurrentScore(const int&) override;
    int GetTeam2CurrentScore() override;
    void SetTeam2CurrentScore(const int&) override;

    bool ActConfirmation(const QString& name, const QString& message) override;

    QVector<QString> GetUtilityList() override;
    void SetUtilityList(const QVector<QString>&) override;

    QString GetMutualInfo() override;
    void SetMutualInfo(const QString&) override;

    QString GetTeam1Logo() override;
    void SetTeam1Logo(const QString&) override;
    QString GetTeam2Logo() override;
    void SetTeam2Logo(const QString&) override;

    QString GetSideT1() override; //A - attack | D - defence | N - none
    //void SetSideT1(const QString&) override;

    void SetStatus(const QString&) override;

    QObject* GetButtonCast_Update();
    QObject* GetButtonCast_Reset();
    QObject* GetButtonCMatch_Swap();
    QObject* GetButtonCMatch_Update();
    QObject* GetButtonCMatch_Reset();

private slots:
    void on_toolButton_t1_logo_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::MainWindow *ui = nullptr;
};
#endif // MAINWINDOW_H
