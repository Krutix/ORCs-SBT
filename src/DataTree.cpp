#include "DataTree.h"

void DataTree::setName(QString const& name)
{
    rootNode->name = name;
}

QString DataTree::getName()
{
    return rootNode->name;
}

void DataTree::add(DataTree const& tree)
{
    rootNode->next.push_back(tree.rootNode);
}

void DataTree::add(QString const& name, QString const& data)
{
    rootNode->data.push_back(QPair(name, data));
}

DataTree DataTree::findNode(QString const& nodeName) const
{
    QQueue<QWeakPointer<Node>> queue;
    queue.append(rootNode);
    while (!queue.isEmpty())
    {
        QWeakPointer<Node> node = queue.dequeue();
        for (auto& p : node.toStrongRef()->next)
        {
            if (p->name == nodeName)
            {
                DataTree find;
                find.rootNode = p;
                return find;
            }
            queue.append(p);
        }
    }
    return DataTree();
}

QString DataTree::findDataInRoot(QString const& key) const
{
    for (auto&[k, d] : rootNode->data)
        if (k == key)
            return d;
    return QString();
}

QString DataTree::findData(QString const& key) const
{
    QQueue<QWeakPointer<Node>> queue;
    queue.append(rootNode);
    while (!queue.isEmpty())
    {
        QWeakPointer<Node> node = queue.dequeue();
        for (auto&[k, d] : node.data()->data)
            if (k == key)
                return d;
        for (auto& p : node.data()->next)
            queue.append(p);
    }
    return QString();
}

void DataTree::treeTraverse(nodeHandleFundtion const& fNode,
                  dataHandleFunction const& fData) const
{
    QStringList path;
    rootNode->traverse(fNode, fData, path);
}


