#ifndef IDATATREESTORAGE_H
#define IDATATREESTORAGE_H

#include "DataTree.h"

template<class T>
class IDataTreeStorage
{
protected:
    QString nodeName;
public:
    virtual DataTree<T> getData() = 0;
    virtual void setData(const DataTree<T>& data) = 0;
    virtual void resetData() = 0;
};

#endif // IDATATREESTORAGE_H
