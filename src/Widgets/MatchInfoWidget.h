#ifndef MATCHINFOWIDGET_H
#define MATCHINFOWIDGET_H

#include <QWidget>
#include <QArrayData>
#include "ApplicationSettings.h"

#include "DataTreeStorage.h"

namespace Ui {
class MatchInfoWidget;
}

class MatchInfoWidget final : public QWidget, public DataTreeStorage
{
    Q_OBJECT

public:
    explicit MatchInfoWidget(QString const& sting, ApplicationSettings* settings = nullptr, QWidget *parent = nullptr);
    ~MatchInfoWidget();

public slots:
    void updateTeams();
    void swapTeams();
    void clearTeams();

private:
    ApplicationSettings* settings;
    Ui::MatchInfoWidget* ui;
};

#endif // MATCHINFOWIDGET_H
