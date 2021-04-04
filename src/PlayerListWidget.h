#ifndef PLAYERLISTWIDGET_H
#define PLAYERLISTWIDGET_H

#include <QWidget>

namespace Ui {
class PlayerListWidget;
}

class PlayerListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerListWidget(QWidget *parent = nullptr);
    ~PlayerListWidget();

private:
    Ui::PlayerListWidget *ui;
};

#endif // PLAYERLISTWIDGET_H
