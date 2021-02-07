#ifndef PLAYERLISTWIDGET_H
#define PLAYERLISTWIDGET_H

#include <QWidget>
#include "DataTreeStorage.h"

namespace Ui {
class PlayerListWidget;
}

class PlayerListWidget final : public QWidget, public DataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit PlayerListWidget(QString const& name, QWidget *parent = nullptr);
    ~PlayerListWidget();

private:
    Ui::PlayerListWidget *ui;
};

#endif // PLAYERLISTWIDGET_H
