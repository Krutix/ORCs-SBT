#ifndef DATATREE_H
#define DATATREE_H

#include <QSharedPointer>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QQueue>

/*!
 * /brief Concentrate and stores information in a tree-like form
 */
class DataTree
{
public:
    using nodeHandleFundtion = //!< Function signature used for handle nodes in the tree (path, node_name)
        std::function<void(QStringList const& path, QString const& nodeName)>;
    using dataHandleFunction = //!< Function signature used for handle data in the tree (path, key, data)
        std::function<void(QStringList const& path, QString const& key, QString const& data)>;

    DataTree(QString const& name = QString())
        : rootNode(new Node(name)) { }

    DataTree(DataTree const&  tree)
        : rootNode(tree.rootNode) { }

    ~DataTree() { }

    void setName(QString const& name);

    QString getName();

    void add(DataTree const& tree);

    void add(QString const& name, QString const& data);

    DataTree findNode(QString const& nodeName) const;

    QString findDataInRoot(QString const& key) const;

    QString findData(QString const& key) const;

    void treeTraverse(nodeHandleFundtion const& fNode,
                      dataHandleFunction const& fData) const;
private:
    struct Node
    {
        QString name;
        QVector<QPair<QString, QString>> data;
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
