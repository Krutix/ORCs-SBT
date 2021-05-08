#ifndef IDATATREESTORAGE_H
#define IDATATREESTORAGE_H

#include "DataTree.h"

class DataTreeStorage
{
protected:
    QString nodeName;
    QVector<DataTreeStorage*> dataChildren;

    using Super = DataTreeStorage;
public:
    void setName(QString name)
    {
        this->nodeName = name;
    }

    virtual DataTree getData() const
    {
        DataTree tree(nodeName);
        for (auto& c : dataChildren) {
            tree.add(c->getData());
        }
        return tree;
    };

    virtual void setData(DataTree const& data)
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
