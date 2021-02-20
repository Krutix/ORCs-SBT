#include "MatchInfoWidget.h"
#include "ui_MatchInfoWidget.h"

#include "QtDebug"

#include "TeamWidget.h"
#include "DataTree.h"

MatchInfoWidget::MatchInfoWidget(QString const& name, ApplicationSettings* settings, QWidget *parent) :
    QWidget(parent),
    settings(settings),
    ui(new Ui::MatchInfoWidget)
{
    Super::nodeName = name;
    ui->setupUi(this);
    for (int i = 0; i < 2; i++) {
        TeamWidget* team = new TeamWidget(QString("Team %1").arg(i + 1), settings, this);
        dataChildren.push_back(team);
        ui->teamsHorizontalLayout->addWidget(team);
    }
}

MatchInfoWidget::~MatchInfoWidget()
{
    delete ui;
}

void MatchInfoWidget::updateTeams()
{
    DataTree matchInfoTree = getData();
    matchInfoTree.treeTraverse([](QStringList const& path, QString const& name){
        qDebug() << "node path: " << path << ", name: " << name;
    }, [](QStringList const& path, QString const& name, QString const& data){
        qDebug() << "data path: " << path << ", name: " << name << ", data: " << data;
    });
}

void MatchInfoWidget::swapTeams()
{
    DataTree team1 = dataChildren[0]->getData();
    DataTree team2 = dataChildren[1]->getData();

    dataChildren[0]->setData(team2);
    dataChildren[1]->setData(team1);
}

void MatchInfoWidget::clearTeams()
{
    Super::resetData();
}
