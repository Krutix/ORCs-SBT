#ifndef BUTTONS_H
#define BUTTONS_H

#include <QObject>
#include <QApplication>
#include <QDebug>
#include <memory>
#include "iuserinterface.h"
#include "filewrite.h"

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
    void ResetInput_CurrentMatch();
    void Update_CurrentMatch();
protected:
    IUserInterface* ui = nullptr;
    FileWrite* fwrite = new FileWrite(QApplication::applicationDirPath());
};

#endif // BUTTONS_H
