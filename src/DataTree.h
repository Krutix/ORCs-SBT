#ifndef DATATREE_H
#define DATATREE_H

#include <QSharedPointer>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QQueue>

/*!
 * /brief Хранение информации в древовидном виде
 */
template<class T>
class DataTree
{
public:
    using nodeHandleFundtion = std::function<void(QStringList const& path, QString const& nodeName)>;
    using dataHandleFunction = std::function<void(QStringList const& path, QString const& key, T const& data)>;

    DataTree(QString const& name = QString())
        : rootNode(new Node(name)) { }

    DataTree(DataTree const&  tree)
        : rootNode(tree.rootNode) { }

    ~DataTree() { }

    void setName(QString const& name)
    {
        rootNode->name = name;
    }

    void getName()
    {
        return rootNode->name;
    }

    void add(DataTree const& tree)
    {
        rootNode->next.push_back(tree.rootNode);
    }

    void add(QString const& name, T const& data)
    {
        rootNode->data.push_back(QPair(name, data));
    }

    DataTree findNode(QString const& nodeName) const
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

    T findDataInRoot(QString const& key) const
    {
        for (auto&[k, d] : rootNode->data)
            if (k == key)
                return d;
        return T();
    }

    T findData(QString const& key) const
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
        return T();
    }

    void treeTraverse(nodeHandleFundtion const& fNode,
                      dataHandleFunction const& fData) const
    {
        QStringList path;
        rootNode->traverse(fNode, fData, path);
    }
private:
    struct Node
    {
        QString name;
        QVector<QPair<QString, T>> data;
        QVector<QSharedPointer<Node>> next;

        Node(QString const& name)
            : name(name) { }

        void traverse(nodeHandleFundtion const& fNode,
                      dataHandleFunction const& fData,
                      QStringList& path) {
            fNode(path, name);
            for (auto d : data)
                fData(path, d.first, d.second);
            path << name;
            for (auto n : next)
                n->traverse(fNode, fData, path);
            path.removeLast();
        }
    };

    QSharedPointer<Node> rootNode;
};

#endif
