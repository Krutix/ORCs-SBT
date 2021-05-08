#include "PlayerListWidget.h"
#include "PlayerWidget.h"
#include "ui_PlayerListWidget.h"
#include <QString>

PlayerListWidget::PlayerListWidget(QString const& name, ApplicationSettings* settings, QWidget* parent)
    : QWidget(parent),
      settings(settings),
      ui(new Ui::PlayerListWidget)
{
    ui->setupUi(this);
    Super::nodeName = name;
    playerList = new DynamicWidgetList([=](QWidget* parent) -> QWidget*{ return new PlayerWidget("Player", settings, parent); }, this);
    ui->mainVerticalLayout->addWidget(playerList);
    for (int i = 0; i < 5; i++)
        playerList->add();
    ui->mainVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

PlayerListWidget::~PlayerListWidget()
{
    delete ui;
}

DataTree PlayerListWidget::getData() const
{
    DataTree tree = Super::getData();
    QVector<QWidget*> vec = playerList->getWidgets();
    for (int i = 0; i < vec.size(); i++)
    {
        PlayerWidget* pl = static_cast<PlayerWidget*>(vec[i]);
        pl->setName(QString("Player %1").arg(i));
        tree.add(pl->getData());
    }
    return tree;
}

void PlayerListWidget::setData(const DataTree &data)
{
    Super::setData(data);
    QVector<QWidget*> vec = playerList->getWidgets();
    for (int i = 0; i < vec.size(); i++)
    {
        PlayerWidget* pl = static_cast<PlayerWidget*>(vec[i]);
        pl->setData(data.findNode(QString("Player %1").arg(i)));
    }
}

void PlayerListWidget::resetData()
{
    Super::resetData();
    QVector<QWidget*> vec = playerList->getWidgets();
    for (int i = 0; i < vec.size(); i++)
    {
        PlayerWidget* pl = static_cast<PlayerWidget*>(vec[i]);
        pl->resetData();
    }
}
