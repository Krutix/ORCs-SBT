#ifndef IUSERINTERFACE_H
#define IUSERINTERFACE_H

#include <QString>

class IUserInterface
{
public:
    IUserInterface() {};

    virtual QString GetCurrentMap() = 0;
    virtual void SetCurrentMap(const QString&) = 0;

    virtual QString GetNameT1 () = 0;
    virtual void SetNameT1 (const QString&) = 0;
    virtual QString GetNameT2 () = 0;
    virtual void SetNameT2 (const QString&) = 0;

    virtual QString GetShortNameT1();
    virtual void SetShortNameT1(const QString&) = 0;
    virtual QString GetShortNameT2() = 0;
    virtual void SetShortNameT2(const QString&) = 0;

    virtual int GetCurrentScoreT1() = 0;
    virtual void SetCurrentScoreT1(const int&) = 0;
    virtual int GetCurrentScoreT2() = 0;
    virtual void SetCurrentScoreT2(const int&) = 0;
};

#endif // IUSERINTERFACE_H
