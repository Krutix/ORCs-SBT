#ifndef TEAMWIDGET_H
#define TEAMWIDGET_H

#include "DataTreeStorage.h"
#include "PlayerListWidget.h"
#include "ApplicationSettings.h"
#include <QWidget>
#include <QString>

namespace Ui {
class TeamWidget;
}

class TeamWidget final : public QWidget, public DataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit TeamWidget(QString const& name, ApplicationSettings* settings, QWidget* parent = nullptr);
    ~TeamWidget();

    // IDataTreeStorage interface
public:
    DataTree<QString> getData() const override;
    void setData(DataTree<QString> const& data) override;
    void resetData() override;

private:
    ApplicationSettings* settings;
    PlayerListWidget* teamPlayers;
    Ui::TeamWidget* ui;
};

#endif // TEAMWIDGET_H
