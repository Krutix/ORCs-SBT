#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QDialog>
#include "ApplicationSettings.h"

namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWidget(ApplicationSettings* settings, QWidget *parent = nullptr);
    ~SettingsWidget();

private:
    ApplicationSettings* settings;
    Ui::SettingsWidget* ui;
};

#endif // SETTINGSWIDGET_H
