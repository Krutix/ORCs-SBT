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

    virtual QVector<QString> GetUtilityList() = 0;
    virtual void SetUtilityList(const QVector<QString>&) = 0;

    virtual CastTeam GetCastTeam() = 0;
    virtual void SetCastTeam(const CastTeam& CastTeam) = 0;

    virtual QString GetSideT1() = 0;

    virtual bool ActConfirmation(const QString& name, const QString& message) = 0;

    virtual void SetStatus(const QString&) = 0;
};

#endif // IUSERINTERFACE_H
