#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MatchInfoWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateButtonClicked();

private:
    Ui::MainWindow* ui;
    MatchInfoWidget* matchWidget;
};

#endif // MAINWINDOW_H
