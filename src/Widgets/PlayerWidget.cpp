#include "PlayerWidget.h"
#include "ui_PlayerWidget.h"

PlayerWidget::PlayerWidget(const QString& nodeName, ApplicationSettings* settings, QWidget* parent) :
    QWidget(parent),
    settings(settings),
    ui(new Ui::PlayerWidget)
{
    this->nodeName = nodeName;
    ui->setupUi(this);
    ui->nickNameLEdit->setToolTip(nodeName);
    setHeroes(settings->getHeroes());

    connect(settings, &ApplicationSettings::heroesChange, this, &PlayerWidget::setHeroes);
}

PlayerWidget::~PlayerWidget()
{
    disconnect(settings, &ApplicationSettings::heroesChange, this, &PlayerWidget::setHeroes);
    delete ui;
}

void PlayerWidget::setHeroes(QPair<QStringList, QStringList> heroes)
{
    ui->heroCBox->clear();
    ui->heroCBox->addItems(heroes.first);
    for (int i = 0; i < heroes.second.size(); i++)
    {
        ui->heroCBox->setItemData(i, QVariant::fromValue(heroes.second[i]));
    }
}

DataTree PlayerWidget::getData() const
{
    DataTree tree = Super::getData();
    tree.add("nickname", ui->nickNameLEdit->text());
    tree.add("hero", ui->heroCBox->currentText());
    tree.add("hero_value", ui->heroCBox->currentData().toString());
    return tree;
}

void PlayerWidget::setData(DataTree const& data)
{
    Super::setData(data);

    ui->nickNameLEdit->setText(data.findDataInRoot("nickname"));
    ui->heroCBox->setCurrentText(data.findDataInRoot("hero"));
}

void PlayerWidget::resetData()
{
    Super::resetData();
    ui->nickNameLEdit->setText("");
    ui->heroCBox->setCurrentIndex(0);
}
