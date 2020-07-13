#ifndef MWINDOW_H
#define MWINDOW_H

#include "mainwindow.h"
#include "iuserinterface.h"

class MWindow
        : public MainWindow, public IUserInterface
{
public:
    MWindow(QWidget *parent = nullptr);

    Team GetTeam1() override;
    void SetTeam1(const Team&) override;
    Team GetTeam2() override;
    void SetTeam2(const Team&) override;

    const MutualMapInfo GetMutualMapInfo() override;
    void SetMutualMapInfo(const MutualMapInfo&) override;

    CastTeam GetCastTeam() override;
    void SetCastTeam(const CastTeam& CastTeam) override;

    QVector<QString> GetUtilities() override;
    void SetUtilities(const QVector<QString>&) override;

    inline QString GetSideT1() override; //A - attack | D - defence | N - none

    bool ActConfirmation(const QString& name, const QString& message) override;

    void SetStatus(const QString&) override;
};

#endif // MWINDOW_H
