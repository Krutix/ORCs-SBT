#ifndef BUTTONS_H
#define BUTTONS_H

#include <QObject>
#include <QApplication>
#include <QDebug>
#include <memory>
#include "iuserinterface.h"
#include "filecontrol.h"

class Buttons : public QObject
{
    Q_OBJECT
public:
    Buttons();
    ~Buttons();
    Buttons(IUserInterface*);

    void SetUI(IUserInterface*);

public slots:
    void Swap_CurrentTeams();
    void Reset_CurrentMatch();
    void Update_CurrentMatch();

    void Update_CastInfo();
    void Reset_CastInfo();
protected:
    IUserInterface* ui = nullptr;
    const QString cdir = QApplication::applicationDirPath();
};

#endif // BUTTONS_HW
