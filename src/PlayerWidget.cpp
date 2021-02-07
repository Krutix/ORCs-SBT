#include "PlayerWidget.h"
#include "ui_PlayerWidget.h"

PlayerWidget::PlayerWidget(const QString& nodeName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerWidget)
{
    this->nodeName = nodeName;
    ui->setupUi(this);
    ui->nickNameLEdit->setToolTip(nodeName);
}

PlayerWidget::~PlayerWidget()
{
    delete ui;
}

DataTree<QString> PlayerWidget::getData() const
{
    DataTree<QString> tree = Super::getData();
    tree.add("nickname", ui->nickNameLEdit->text());
    tree.add("hero", ui->heroCBox->currentText());
    return tree;
}

void PlayerWidget::setData(DataTree<QString> const& data)
{
    Super::setData(data);

    ui->nickNameLEdit->setText(data.findDataInRoot("nickname"));
    ui->heroCBox->setCurrentText(data.findDataInRoot("hero"));
}

void PlayerWidget::resetData()
{
    Super::resetData();
    ui->nickNameLEdit->setText("");
    ui->heroCBox->setCurrentText("None");
}
