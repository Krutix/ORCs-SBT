#ifndef IUSERINTERFACE_H
#define IUSERINTERFACE_H

#include <QString>
#include <QVector>
#include "castom_data.h"

class IUserInterface
{
public:
    IUserInterface() {};

    virtual Team GetTeam1() = 0;
    virtual void SetTeam1(const Team&) = 0;
    virtual Team GetTeam2() = 0;
    virtual void SetTeam2(const Team&) = 0;

    virtual const MutualMapInfo GetMutualMapInfo() = 0;
    virtual void SetMutualMapInfo(const MutualMapInfo&) = 0;

    virtual QString GetCurrentMap() = 0;
    virtual void SetCurrentMap(const QString&) = 0;

    virtual QString GetTeam1Name() = 0;
    virtual void SetTeam1Name(const QString&) = 0;
    virtual QString GetTeam2Name() = 0;
    virtual void SetTeam2Name(const QString&) = 0;

    virtual QString GetTeam1ShortName() = 0;
    virtual void SetTeam1ShortName(const QString&) = 0;
    virtual QString GetTeam2ShortName() = 0;
    virtual void SetTeam2ShortName(const QString&) = 0;

    virtual int GetTeam1CurrentScore() = 0;
    virtual void SetTeam1CurrentScore(const int&) = 0;
    virtual int GetTeam2CurrentScore() = 0;
    virtual void SetTeam2CurrentScore(const int&) = 0;

    virtual QString GetMutualInfo() = 0;
    virtual void SetMutualInfo(const QString&) = 0;

    virtual QString GetSideT1() = 0; //A - attack | D - defence | N - none
    //virtual void SetSideT1(const QString&) = 0;

    virtual QString GetTeam1Logo() = 0;
    virtual void SetTeam1Logo(const QString&) = 0;
    virtual QString GetTeam2Logo() = 0;
    virtual void SetTeam2Logo(const QString&) = 0;

    virtual QVector<QString> GetUtilityList() = 0;
    virtual void SetUtilityList(const QVector<QString>&) = 0;

    virtual bool ActConfirmation(const QString& name, const QString& message) = 0;

    virtual void SetStatus(const QString&) = 0;
};

#endif // IUSERINTERFACE_H