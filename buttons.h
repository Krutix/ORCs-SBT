#ifndef BUTTOMS_H
#define BUTTOMS_H

#include <QObject>
#include <QDebug>
#include <memory>
#include "iuserinterface.h"

class Buttoms : public QObject
{
    Q_OBJECT
public:
    Buttoms();
    Buttoms(IUserInterface*);

    void SetUI(IUserInterface*);

public slots:
    void Swap_CurrentTeams();
    void ResetInput_CurrentMatch();/*
    void Update_CurrentMatch();
*/
protected:
    IUserInterface* ui = nullptr;
};

#endif // BUTTOMS_H
