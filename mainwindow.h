#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "buttons.h"
#include "iuserinterface.h"
#include <QMainWindow>
#include <memory>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IUserInterface
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString GetCMap_Map();
    void SetCMap_Map(const QString&);

    QString GetT1_Name ();
    void SetT1_Name (const QString&);
    QString GetT2_Name ();
    void SetT2_Name (const QString&);

    QString GetT1_ShortName();
    void SetT1_ShortName(const QString&);
    QString GetT2_ShortName();
    void SetT2_ShortName(const QString&);

    int GetCMap_ScoreT1();
    void SetCMap_ScoreT1(const int&);
    int GetCMap_ScoreT2();
    void SetCMap_ScoreT2(const int&);

    QObject* GetObjButtonCMatch_Swap();
    QObject* GetButtonCMatch_Update();
    QObject* GetButtonCMatch_Reset();

private:
    Ui::MainWindow *ui = nullptr;
};
#endif // MAINWINDOW_H
