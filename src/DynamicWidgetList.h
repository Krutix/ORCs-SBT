#ifndef DYNAMICWIDGETLISTITEM_H
#define DYNAMICWIDGETLISTITEM_H

#include <QWidget>
#include <QToolButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QList>
#include <QVector>
#include <QtDebug>
#include <algorithm>

class DynamicWidgetItem : public QWidget
{
    Q_OBJECT

public:
    QWidget		*widget;
    int			index;

    DynamicWidgetItem(QWidget* widget, int index, QWidget* parent = nullptr);

    void setIndex(int index);
public slots:
    void remove() { emit removed(index); }

signals:
    void removed(int index);

private:
    QHBoxLayout *itemLayout;

    QVBoxLayout *buttonLayout;
    QToolButton *removeButton;
};



class DynamicWidgetList : public QWidget
{
    Q_OBJECT

public:
    DynamicWidgetList(std::function<QWidget*(QWidget*)> creater, QWidget *parent = nullptr);

    ~DynamicWidgetList();

    QVector<QWidget*> getWidgets() const;

public slots:
    void add();

    void clear();

    void remove(int index);

private:
    QList<DynamicWidgetItem*> widgetList;
    QVBoxLayout* itemsLayout;
    QPushButton* addButton;
    QVBoxLayout* layout;
    std::function<QWidget*(QWidget* parent)> creater;
};

#endif // DYNAMICWIDGETLISTITEM_H
