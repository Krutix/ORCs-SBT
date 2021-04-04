#ifndef TEAMWIDGET_H
#define TEAMWIDGET_H

#include "DataTreeStorage.h"
#include "PlayerListWidget.h"
#include <QWidget>
#include <QString>

namespace Ui {
class TeamWidget;
}

class TeamWidget final : public QWidget, public DataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit TeamWidget(QString const& name, QWidget *parent = nullptr);
    ~TeamWidget();

private:
    Ui::TeamWidget* ui;
    PlayerListWidget* teamPlayers;

    // IDataTreeStorage interface
public:
    DataTree<QString> getData() const override;
    void setData(DataTree<QString> const& data) override;
    void resetData() override;
};

#endif // TEAMWIDGET_H
