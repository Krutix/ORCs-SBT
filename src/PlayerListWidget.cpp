#include "PlayerListWidget.h"
#include "ui_PlayerListWidget.h"

PlayerListWidget::PlayerListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerListWidget)
{
    ui->setupUi(this);
}

PlayerListWidget::~PlayerListWidget()
{
    delete ui;
}
