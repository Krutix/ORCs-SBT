#include "PlayerListWidget.h"
#include "PlayerWidget.h"
#include "ui_PlayerListWidget.h"
#include <QString>

PlayerListWidget::PlayerListWidget(QString const& name, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::PlayerListWidget)
{
    ui->setupUi(this);
    Super::nodeName = name;
    for (size_t i = 0; i < 5; ++i) {
        PlayerWidget* pl = new PlayerWidget(QString("Player %1").arg(i + 1), this);
        dataChildren.push_back(pl);
        ui->mainVerticalLayout->addWidget(pl);
    }
    ui->mainVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

PlayerListWidget::~PlayerListWidget()
{
    delete ui;
}
