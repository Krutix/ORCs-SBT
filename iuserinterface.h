#ifndef IUSERINTERFACE_H
#define IUSERINTERFACE_H

#include <QString>

class IUserInterface
{
public:
    IUserInterface() {};

    virtual QString GetCMap_Map() = 0;
    virtual void SetCMap_Map(const QString&) = 0;

    virtual QString GetT1_Name () = 0;
    virtual void SetT1_Name (const QString&) = 0;
    virtual QString GetT2_Name () = 0;
    virtual void SetT2_Name (const QString&) = 0;

    virtual QString GetT1_ShortName();
    virtual void SetT1_ShortName(const QString&) = 0;
    virtual QString GetT2_ShortName() = 0;
    virtual void SetT2_ShortName(const QString&) = 0;

    virtual int GetCMap_ScoreT1() = 0;
    virtual void SetCMap_ScoreT1(const int&) = 0;
    virtual int GetCMap_ScoreT2() = 0;
    virtual void SetCMap_ScoreT2(const int&) = 0;

    virtual bool ActConfirmation(const QString&) = 0;

    virtual void SetStatus(const QString&) = 0;
};

#endif // IUSERINTERFACE_H
