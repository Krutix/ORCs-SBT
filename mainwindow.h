#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "buttons.h"
#include "iuserinterface.h"
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

    QString GetCMap_Map() override;
    void SetCMap_Map(const QString&) override;

    QString GetT1_Name () override;
    void SetT1_Name (const QString&) override;
    QString GetT2_Name () override;
    void SetT2_Name (const QString&) override;

    QString GetT1_ShortName() override;
    void SetT1_ShortName(const QString&) override;
    QString GetT2_ShortName() override;
    void SetT2_ShortName(const QString&) override;

    int GetCMap_ScoreT1() override;
    void SetCMap_ScoreT1(const int&) override;
    int GetCMap_ScoreT2() override;
    void SetCMap_ScoreT2(const int&) override;

    bool ActConfirmation(const QString& name, const QString& message) override;

    QVector<QString> GetUtilityList() override;
    void SetUtilityList(const QVector<QString>&) override;

    QString GetMutualInfo() override;
    void SetMutualInfo(const QString&) override;

    QString GetT1_Logo() override;
    void SetT1_Logo(const QString&) override;
    QString GetT2_Logo() override;
    void SetT2_Logo(const QString&) override;

    QString GetSideT1() override; //A - attack | D - defence | N - none
    //void SetSideT1(const QString&) override;

    void SetStatus(const QString&) override;

    QString GetPath(const QString&, const QString&);

    QObject* GetButtonCast_Update();
    QObject* GetButtonCast_Reset();
    QObject* GetButtonCMatch_Swap();
    QObject* GetButtonCMatch_Update();
    QObject* GetButtonCMatch_Reset();

private slots:
    void on_toolButton_t1_logo_clicked();

private:
    Ui::MainWindow *ui = nullptr;
};
#endif // MAINWINDOW_H
