#ifndef PLAYERLISTWIDGET_H
#define PLAYERLISTWIDGET_H

#include <QWidget>
#include "DataTreeStorage.h"
#include "DynamicWidgetList.h"

#include "ApplicationSettings.h"

namespace Ui {
class PlayerListWidget;
}

class PlayerListWidget final : public QWidget, public DataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit PlayerListWidget(QString const& name, ApplicationSettings* settings, QWidget *parent = nullptr);
    ~PlayerListWidget();

    DataTree<QString> getData() const override;

    void setData(const DataTree<QString> &data) override;

    void resetData() override;

private:
    ApplicationSettings*	settings;
    DynamicWidgetList*		playerList;
    Ui::PlayerListWidget*	ui;
};

#endif // PLAYERLISTWIDGET_H
