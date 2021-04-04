#ifndef IDATATREESTORAGE_H
#define IDATATREESTORAGE_H

#include "datatree.h"

template<class T>
class IDataTreeStorage
{
    virtual DataTree<T> getData() = 0;
    virtual void setData(DataTree<T> data) = 0;
    virtual void resetData() = 0;
};

#endif // IDATATREESTORAGE_H
