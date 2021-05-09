#ifndef IDATATREESTORAGE_H
#define IDATATREESTORAGE_H

#include "DataTree.h"

class DataTreeStorage
{
protected:
    QVector<DataTreeStorage*> dataChildren;

    //! Simple appear to the parent
    using Super = DataTreeStorage;
public:
    //! Name of node
    QString nodeName;

    virtual DataTree getData() const;

    virtual void setData(DataTree const& data);

    virtual void resetData();
};

#endif // IDATATREESTORAGE_H
