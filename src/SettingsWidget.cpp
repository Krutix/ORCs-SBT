#include "SettingsWidget.h"
#include "ui_SettingsWidget.h"

SettingsWidget::SettingsWidget(ApplicationSettings* settings, QWidget *parent) :
    QDialog(parent),
    settings(settings),
    ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);
}

SettingsWidget::~SettingsWidget()
{
    delete ui;
}
