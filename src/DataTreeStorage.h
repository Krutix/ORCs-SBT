#ifndef IDATATREESTORAGE_H
#define IDATATREESTORAGE_H

#include "DataTree.h"

template<class T>
class DataTreeStorage
{
protected:
    QString nodeName;
    QVector<DataTreeStorage<T>*> dataChildren;

    using Super = DataTreeStorage;
public:
    void setName(QString name)
    {
        this->nodeName = name;
    }

    virtual DataTree<T> getData() const
    {
        DataTree<T> tree(nodeName);
        for (auto& c : dataChildren) {
            tree.add(c->getData());
        }
        return tree;
    };

    virtual void setData(DataTree<T> const& data)
    {
        for (auto& c : dataChildren) {
            c->setData(data.findNode(c->nodeName));
        }
    }

    virtual void resetData()
    {
        for (auto& c : dataChildren) {
            c->resetData();
        }
    }
};

#endif // IDATATREESTORAGE_H
