#include "DynamicWidgetList.h"

DynamicWidgetItem::DynamicWidgetItem(QWidget* widget, int index, QWidget* parent)
    : QWidget(parent), widget(widget), index(index)
{
    buttonLayout = new QVBoxLayout();

    removeButton = new QToolButton(this);
    removeButton->setText(QString::fromStdWString(L"×"));
    buttonLayout->addWidget(removeButton);
    //toTopButton = new QToolButton(this);
    //toDownButton = new QToolButton(this);
    //toTopButton->setText(QString::fromStdWString(L"▲"));
    //toDownButton->setText(QString::fromStdWString(L"▼"));
    //buttonLayout->addWidget(toTopButton);
    //buttonLayout->addWidget(toDownButton);

    itemLayout = new QHBoxLayout(this);
    itemLayout->addWidget(widget);
    itemLayout->addItem(buttonLayout);

    connect(removeButton, &QToolButton::clicked, this, &DynamicWidgetItem::remove);
    //connect(toTopButton, &QToolButton::clicked, this, &DynamicWidgetItem::toTop);
    //connect(toDownButton, &QToolButton::clicked, this, &DynamicWidgetItem::toDown);
}

void DynamicWidgetItem::setIndex(int index)
{
    this->index = index;
}

DynamicWidgetList::DynamicWidgetList(std::function<QWidget*(QWidget*)> creater, QWidget *parent)
    : QWidget(parent),
      creater(creater)
{
    layout = new QVBoxLayout(this);
    itemsLayout = new QVBoxLayout();
    layout->addItem(itemsLayout);

    addButton = new QPushButton(this);
    addButton->setText("+");
    layout->addWidget(addButton);

    layout->addStretch(0);

    connect(addButton, &QToolButton::clicked, this, &DynamicWidgetList::add);
}

DynamicWidgetList::~DynamicWidgetList()
{
    disconnect(addButton, &QToolButton::clicked, this, &DynamicWidgetList::add);
}

/*void swap(int from, int to) // TODO swap function
{
    qDebug() << from << ' ' << to;
    if (to >= widgetList.size() || to < 0)
        return;
    qDebug() << "d";
    itemsLayout->removeWidget(widgetList[from]);
    itemsLayout->insertWidget(from - 1, widgetList[from]);

    widgetList[to]->setIndex(from);
    widgetList[from]->setIndex(to);
    widgetList.swapItemsAt(from, to);
}*/

void DynamicWidgetList::add()
{
    widgetList.push_back(new DynamicWidgetItem(creater((QWidget*)this->parent()), widgetList.size(), this));
    itemsLayout->addWidget(widgetList.back());
    widgetList.back()->show();
    connect(widgetList.back(), &DynamicWidgetItem::removed, this, &DynamicWidgetList::remove);
    //connect(widgetList.back(), &DynamicWidgetItem::swaped, this, &DynamicWidgetList::swap);
}

void DynamicWidgetList::remove(int index)
{
    disconnect(widgetList[index], &DynamicWidgetItem::removed, this, &DynamicWidgetList::remove);
    //disconnect(widgetList[index], &DynamicWidgetItem::swaped, this, &DynamicWidgetList::swap);
    widgetList[index]->hide();
    delete widgetList[index];
    widgetList.removeAt(index);
    for (int i = index; i < widgetList.size(); i++)
        widgetList[i]->setIndex(i);
}

QVector<QWidget*> DynamicWidgetList::getWidgets() const
{
    QVector<QWidget*> vec;
    vec.reserve(widgetList.size());
    for (int i = 0; i < widgetList.size(); i++)
        vec.push_back(widgetList[i]->widget);
    return vec;
}
