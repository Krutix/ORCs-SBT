#include "mainwindow.h"
#include "updateextdata.h"
#include "buttons.h"

#include <QObject>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* MWindow = new MainWindow();
    Buttons *buttons = new Buttons(MWindow);
    QObject::connect(MWindow->GetButtonSwap_Current(), SIGNAL(clicked()),
                buttons, SLOT(Swap_CurrentTeams()));
    QObject::connect(MWindow->GetButtonReset_Current(), SIGNAL(clicked()),
            buttons, SLOT(ResetInput_CurrentMatch()));
    QObject::connect(MWindow->GetButtonUpdate_Current(), SIGNAL(clicked()),
            buttons, SLOT(Update_CurrentMatch()));
    MWindow->show();
    return a.exec();
}
