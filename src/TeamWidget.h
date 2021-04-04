#ifndef TEAMWIDGET_H
#define TEAMWIDGET_H

#include "IDataTreeStorage.h"
#include <QWidget>
#include <QString>

namespace Ui {
class TeamWidget;
}

class TeamWidget : public QWidget, public IDataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit TeamWidget(QWidget *parent = nullptr);
    ~TeamWidget();

private:
    Ui::TeamWidget *ui;

    // QPaintDevice interface
public:
    QPaintEngine *paintEngine() const override;

    // IDataTreeStorage interface
public:
    DataTree<QString> getData() override;
    void setData(const DataTree<QString> &data) override;
    void resetData() override;
};

#endif // TEAMWIDGET_H
