#include "TeamWidget.h"
#include "PlayerWidget.h"
#include "ui_TeamWidget.h"

TeamWidget::TeamWidget(QString const& name, ApplicationSettings* settings, QWidget *parent) :
    QWidget(parent),
    settings(settings),
    ui(new Ui::TeamWidget)
{
    nodeName = name;
    ui->setupUi(this);
    teamPlayers = new PlayerListWidget("player_list", settings, this);
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

    ui->teamNameLineEdit->setText(data.findDataInRoot("name"));
    ui->shortNameLineEdit->setText(data.findDataInRoot("short_name"));
    ui->logoPath->setText(data.findDataInRoot("logo"));
}

void TeamWidget::resetData()
{
    Super::resetData();
    ui->teamNameLineEdit->setText("");
    ui->shortNameLineEdit->setText("");
    ui->logoPath->setText("");
}
