#include "mwindow.h"

MWindow::MWindow(QWidget *parent)
    :MainWindow(parent)
{}

Team MWindow::GetTeam1()
{
    return { GetTeam1Name(), GetTeam1ShortName(), GetTeam1Logo(), GetTeam1CurrentScore(),
                GetTeam1PlayersNick(), GetTeam1PlayersHero() };
}

Team MWindow::GetTeam2()
{
    return { GetTeam2Name(), GetTeam2ShortName(), GetTeam2Logo(), GetTeam2CurrentScore(),
                GetTeam2PlayersNick(), GetTeam2PlayersHero() };
}

void MWindow::SetTeam1(const Team& team)
{
    SetTeam1Name(team.name);
    SetTeam1ShortName(team.shortName);
    SetTeam1CurrentScore(team.score);
    SetTeam1Logo(team.logoPath);
    SetTeam1PlayersNick(team.playersNick);
    SetTeam1PlayersHero(team.playersHero);
}

void MWindow::SetTeam2(const Team& team)
{
    SetTeam2Name(team.name);
    SetTeam2ShortName(team.shortName);
    SetTeam2CurrentScore(team.score);
    SetTeam2Logo(team.logoPath);
    SetTeam2PlayersNick(team.playersNick);
    SetTeam2PlayersHero(team.playersHero);
}

const MutualMapInfo MWindow::GetMutualMapInfo()
{
    return { GetCurrentMap(), GetMutualInfo() };
}

void MWindow::SetMutualMapInfo(const MutualMapInfo& info)
{
    SetCurrentMap(info.currentMap);
    SetMutualInfo(info.mutualInfo);
}


bool MWindow::ActConfirmation(const QString& name, const QString& message)
{
    int conf = QMessageBox::question(this, name, message,
                                     QMessageBox::Yes|QMessageBox::Cancel);
    if (conf == QMessageBox::Yes) {
       return true;
    }
    return false;
}


QStringList MWindow::GetUtilities(){
    return { GetUtilitiesText() };
}

void MWindow::SetUtilities(const QStringList& utilitys)
{
    SetUtilitiesText(utilitys);
}

CastTeam MWindow::GetCastTeam()
{
    return GetCastTeamText();
}

void MWindow::SetCastTeam(const CastTeam& castTeam)
{
    SetCastTeamText(castTeam);
}

QString MWindow::GetSideT1()
{
    return GetSide();
}

void MWindow::SetStatus(const QString& status)
{
    ui->statusbar->showMessage(status);
}
