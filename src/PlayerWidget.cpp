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

DataTree<QString> PlayerWidget::getData()
{
    DataTree<QString> ret(nodeName);
    ret.add("nickname", ui->nickNameLEdit->text());
    ret.add("hero", ui->heroCBox->currentText());
    return ret;
}

void PlayerWidget::setData(const DataTree<QString> &data)
{
    QString find;
    if ((find = data.find("nickname", true)) != QString())
        ui->nickNameLEdit->setText(find);
    if ((find = data.find("hero", true)) != QString())
        ui->heroCBox->setCurrentText(find);
}

void PlayerWidget::resetData()
{
    ui->nickNameLEdit->setText("");
    ui->heroCBox->setCurrentText("None");
}
