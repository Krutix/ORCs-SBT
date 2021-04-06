#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QString>
#include "DataTreeStorage.h"
#include "ApplicationSettings.h"

namespace Ui {
class PlayerWidget;
}

class PlayerWidget final : public QWidget, public DataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit PlayerWidget(QString const& nodeName, ApplicationSettings* settings, QWidget *parent = nullptr);
    ~PlayerWidget();

public slots:
    void setHeroes(QPair<QStringList, QStringList> heroes);

    // IDataTreeStorage interface
public:
    DataTree<QString> getData() const override;
    void setData(DataTree<QString> const& data) override;
    void resetData() override;

private:
    ApplicationSettings* settings;
    Ui::PlayerWidget* ui;
};

#endif // PLAYERWIDGET_H
