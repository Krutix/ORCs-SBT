#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QString>
#include "DataTreeStorage.h"

namespace Ui {
class PlayerWidget;
}

class PlayerWidget final : public QWidget, public DataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit PlayerWidget(QString const& nodeName, QWidget *parent = nullptr);
    ~PlayerWidget();

    DataTree<QString> getData() const override;
    void setData(DataTree<QString> const& data) override;
    void resetData() override;

private:
    Ui::PlayerWidget *ui;
};

#endif // PLAYERWIDGET_H
