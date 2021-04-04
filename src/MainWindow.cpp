#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DataTree.h"
#include <QString>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    matchWidget = new MatchInfoWidget("match_info", this);
    ui->matchInfoLayout->addWidget(matchWidget);

    qDebug() << "connect";
    connect(ui->updatePushButton, &QPushButton::clicked, this, &MainWindow::updateButtonClicked);
    connect(ui->swapPushButton, &QPushButton::clicked, matchWidget, &MatchInfoWidget::swapTeams);
}

MainWindow::~MainWindow()
{
    disconnect(ui->updatePushButton, &QPushButton::clicked, this, &MainWindow::updateButtonClicked);
    disconnect(ui->swapPushButton, &QPushButton::clicked, matchWidget, &MatchInfoWidget::swapTeams);
    delete ui;
}

void MainWindow::updateButtonClicked()
{
    qDebug() << "clicked";
    DataTree matchInfoTree = matchWidget->getData();
    matchInfoTree.treeTraverse([](QStringList const& path, QString const& name){
        qDebug() << "node path: " << path << ", name: " << name;
    }, [](QStringList const& path, QString const& name, QString const& data){
        qDebug() << "data path: " << path << ", name: " << name << ", data: " << data;
    });
}
