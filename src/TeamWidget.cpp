#include "TeamWidget.h"
#include "PlayerWidget.h"
#include "ui_TeamWidget.h"

TeamWidget::TeamWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamWidget)
{
    ui->setupUi(this);
}

TeamWidget::~TeamWidget()
{
    delete ui;
}

DataTree<QString> TeamWidget::getData()
{
    DataTree<QString> tree = Super::getData();
    tree.add("name", ui->teamNameLineEdit->text());
    tree.add("short_name", ui->shortNameLineEdit->text());
    tree.add("logo", ui->logoPath->text());
    return tree;
}
