#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MatchInfoWidget.h"
#include "ApplicationSettings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ApplicationSettings* settings = nullptr, QWidget* parent = nullptr);
    ~MainWindow();

private:
    MatchInfoWidget* matchWidget;
    ApplicationSettings* settings;
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
