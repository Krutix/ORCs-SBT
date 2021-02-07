#include "TeamWidget.h"
#include "PlayerWidget.h"
#include "ui_TeamWidget.h"

TeamWidget::TeamWidget(QString const& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamWidget)
{
    nodeName = name;
    ui->setupUi(this);
    teamPlayers = new PlayerListWidget("player_list", this);
    ui->playerListLayout->addWidget(teamPlayers);
    dataChildren.push_back(teamPlayers);
}

TeamWidget::~TeamWidget()
{
    delete ui;
}

DataTree<QString> TeamWidget::getData() const
{
    DataTree<QString> tree = Super::getData();
    tree.add("name", ui->teamNameLineEdit->text());
    tree.add("short_name", ui->shortNameLineEdit->text());
    tree.add("logo", ui->logoPath->text());
    return tree;
}

void TeamWidget::setData(DataTree<QString> const& data)
{
    Super::setData(data);
    QString find;

    if ((find = data.findDataInRoot("name")) != QString())
        ui->teamNameLineEdit->setText(find);
    if ((find = data.findDataInRoot("short_name")) != QString())
        ui->shortNameLineEdit->setText(find);
    if ((find = data.findDataInRoot("logo")) != QString())
        ui->logoPath->setText(find);
}

void TeamWidget::resetData()
{
    Super::resetData();
    ui->teamNameLineEdit->setText("");
    ui->shortNameLineEdit->setText("");
    ui->logoPath->setText("");
}
