#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString GetNameT1 ();
    void SetNameT1 (const QString&);
    QString GetNameT2 ();
    void SetNameT2 (const QString&);

    QString GetShortNameT1();
    void SetShortNameT1(const QString&);
    QString GetShortNameT2();
    void SetShortNameT2(const QString&);

    QString GetCurrentMap();
    void SetCurrentMap(const QString&);

    int GetCurrentScoreT1();
    void SetCurrentScoreT1(const int&);
    int GetCurrentScoreT2();
    void SetCurrentScoreT2(const int&);

private slots:
    void SwapTeams();
    void ResetInput();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
