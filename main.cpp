#include "mainwindow.h"
//#include "updateextdata.h"
#include "buttons.h"

#include <QObject>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* MWindow = new MainWindow();
    Buttons *buttons = new Buttons(MWindow);
    QObject::connect(MWindow->GetObjButtonCMatch_Swap(), SIGNAL(clicked()),
            buttons, SLOT(Swap_CurrentTeams()));
    QObject::connect(MWindow->GetButtonCMatch_Reset(), SIGNAL(clicked()),
            buttons, SLOT(ResetInput_CurrentMatch()));
    QObject::connect(MWindow->GetButtonCMatch_Update(), SIGNAL(clicked()),
            buttons, SLOT(Update_CurrentMatch()));
    MWindow->show();
    return a.exec();
}
