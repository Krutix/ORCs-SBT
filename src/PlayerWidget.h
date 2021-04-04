#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QString>
#include "IDataTreeStorage.h"

namespace Ui {
class PlayerWidget;
}

class PlayerWidget : public QWidget, public IDataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit PlayerWidget(const QString& nodeName, QWidget *parent = nullptr);
    ~PlayerWidget();

    DataTree<QString> getData() override;
    void setData(const DataTree<QString>& data) override;
    void resetData() override;

private:
    Ui::PlayerWidget *ui;
};

#endif // PLAYERWIDGET_H
