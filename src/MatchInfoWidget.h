#ifndef MATCHINFOWIDGET_H
#define MATCHINFOWIDGET_H

#include <QWidget>
#include <QArrayData>

#include "DataTreeStorage.h"

namespace Ui {
class MatchInfoWidget;
}

class MatchInfoWidget final : public QWidget, public DataTreeStorage<QString>
{
    Q_OBJECT

public:
    explicit MatchInfoWidget(QString const& name, QWidget *parent = nullptr);
    ~MatchInfoWidget();

public slots:
    void swapTeams();
    void clearTeams();

private:
    Ui::MatchInfoWidget *ui;
};

#endif // MATCHINFOWIDGET_H
