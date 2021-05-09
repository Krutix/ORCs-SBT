#ifndef DATATREE_H
#define DATATREE_H

#include <QSharedPointer>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QQueue>

/*!
 * @brief Concentrate and stores information in a tree-like form
 */
class DataTree
{
public:
    //! Function signature used for handle nodes in the tree (path, node_name)
    using nodeHandleFundtion =
        std::function<void(QStringList const& path, QString const& nodeName)>;
    //! Function signature used for handle data in the tree (path, key, data)
    using dataHandleFunction =
        std::function<void(QStringList const& path, QString const& key, QString const& data)>;

    //! Simple default constructor. Create root node with given name
    DataTree(QString const& name = QString())
        : rootNode(new Node(name)) { }

    //! Create copy of the tree
    //! @todo full copy of the tree
    DataTree(DataTree const&  tree)
        : rootNode(tree.rootNode) { }

    virtual ~DataTree() { }

    //! Set root node name
    void setName(QString const& name);

    //! Get root node name
    QString getName();

    //! Add root node subtree
    void add(DataTree const& tree);

    //! Add root node data
    void add(QString const& name, QString const& data);

    //! Find subtree by root node name. Algorithm - Breadth First Search
    DataTree findNode(QString const& nodeName) const;

    //! Find data in root node by name
    QString findDataInRoot(QString const& key) const;

    //! Find data in subtrees by name. Algorithm - Breadth First Search
    QString findData(QString const& key) const;

    //! Inorder tree traverse with handle each node and data field
    //! @param fNode function to handle subtree root node
    //! @param fData function to handle data for last hendled node
    void treeTraverse(nodeHandleFundtion const& fNode,
                      dataHandleFunction const& fData) const;
private:
    struct Node
    {
        QString name;
        //! @todo replace vector to hash table (faster)
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
