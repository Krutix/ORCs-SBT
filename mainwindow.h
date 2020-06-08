#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "buttoms.h"
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

    QString GetCurrentMap();
    void SetCurrentMap(const QString&);

    QString GetNameT1 ();
    void SetNameT1 (const QString&);
    QString GetNameT2 ();
    void SetNameT2 (const QString&);

    QString GetShortNameT1();
    void SetShortNameT1(const QString&);
    QString GetShortNameT2();
    void SetShortNameT2(const QString&);

    int GetCurrentScoreT1();
    void SetCurrentScoreT1(const int&);
    int GetCurrentScoreT2();
    void SetCurrentScoreT2(const int&);

    QObject* GetButtonSwap_Current();
    QObject* GetButtonUpdate_Current();
    QObject* GetButtonReset_Current();

private:
    Ui::MainWindow *ui = nullptr;
};
#endif // MAINWINDOW_H
