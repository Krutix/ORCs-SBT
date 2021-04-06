#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DataTree.h"
#include <QString>

#include <QDebug>

MainWindow::MainWindow(ApplicationSettings* settings, QWidget* parent) :
    QMainWindow(parent),
    settings(settings),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    matchWidget = new MatchInfoWidget("match_info", settings, this);
    ui->matchInfoLayout->addWidget(matchWidget);

    connect(ui->updatePushButton, &QPushButton::clicked, matchWidget, &MatchInfoWidget::updateTeams);
    connect(ui->swapPushButton, &QPushButton::clicked, matchWidget, &MatchInfoWidget::swapTeams);
    connect(ui->clearPushButton, &QPushButton::clicked, matchWidget, &MatchInfoWidget::clearTeams);
}

MainWindow::~MainWindow()
{
    disconnect(ui->updatePushButton, &QPushButton::clicked, matchWidget, &MatchInfoWidget::updateTeams);
    disconnect(ui->swapPushButton, &QPushButton::clicked, matchWidget, &MatchInfoWidget::swapTeams);
    disconnect(ui->clearPushButton, &QPushButton::clicked, matchWidget, &MatchInfoWidget::clearTeams);
    delete ui;
}
