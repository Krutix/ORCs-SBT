#ifndef DATATREE_H
#define DATATREE_H

#include <QSharedPointer>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QQueue>

template<class T>
class DataTree
{
private:
    struct Node {
        QString name;
        QVector<QPair<QString, T>> data;
        QVector<QSharedPointer<Node>> next;

        Node(const QString& name)
            : name(name) {}

        void traverse(std::function<void(const QStringList&, const QString&)>& fNode,
                      std::function<void(const QStringList&, const QString&, const T&)>& fData,
                      QStringList& path) {
            fNode(path, name);
            for (auto d : data)
                fData(path, d.first, d.second);
            path << name;
            for (auto n : next)
                n->traverse(fNode, fData);
            path.removeLast();
        }
    };
    QSharedPointer<Node> rootNode;
public:

    DataTree(const QString& name = "None")
        : rootNode(new Node(name)) { }

    ~DataTree();

    void setName(const QString& name) {
        rootNode->name = name;
    }

    void add(const DataTree& tree) {
        rootNode->next.pushBack(tree.rootNode);
    }

    void add(const QString& name, const T& data) {
        rootNode->data.pushBack(QPair(name, data));
    }

    T find(const QString& key, bool onlyRoot = false) const {
        if (onlyRoot)
        {
            for (auto&[k, d] : rootNode->data)
                if (k == key)
                    return d;
        }
        else
        {
            QQueue<QWeakPointer<Node>> queue;
            queue.append(rootNode);
            while (!queue.isEmpty())
            {
                QWeakPointer<Node> node = queue.dequeue();
                for (auto&[k, d] : node->data)
                    if (k == key)
                        return d;
                for (auto& p : node->next)
                    queue.append(p);
            }
        }
        return T();
    }

    void treeTraverse(std::function<void(const QStringList&, const QString&)>& fNode,
                      std::function<void(const QStringList&, const QString&, const T&)>& fData) const {
        rootNode->traverse(fNode, fData, QStringList());
    }
};

#endif
