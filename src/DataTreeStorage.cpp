#include "DataTreeStorage.h"

DataTree DataTreeStorage::getData() const
{
    DataTree tree(nodeName);
    for (auto& c : dataChildren) {
        tree.add(c->getData());
    }
    return tree;
};

void DataTreeStorage::setData(DataTree const& data)
{
    for (auto& c : dataChildren) {
        c->setData(data.findNode(c->nodeName));
    }
}

void DataTreeStorage::resetData()
{
    for (auto& c : dataChildren) {
        c->resetData();
    }
}
