#ifndef IDATATREESTORAGE_H
#define IDATATREESTORAGE_H

#include "DataTree.h"

template<class T>
class IDataTreeStorage
{
protected:
    QString nodeName;
    QVector<IDataTreeStorage<T>*> children;
public:
    using Super = IDataTreeStorage;
    virtual DataTree<T> getData() const
    {
        DataTree<T> tree(nodeName);
        for (auto& c : children) {
            tree.add(c.getData());
        }
    };
    virtual void setData(const DataTree<T>& data) = 0;
    virtual void resetData() = 0;
};

#endif // IDATATREESTORAGE_H
