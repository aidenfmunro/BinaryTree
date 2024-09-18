#ifndef ALIB_BTREE_HPP
#define ALIB_BTREE_HPP

#include <iostream>

namespace alib
{

template<typename KeyType, typename ValueType>
class BinaryTree
{
    struct Node
    {
        KeyType   key;
        ValueType value;

        Node* right;
        Node* left;

        Node (KeyType k, ValueType v) : key(k), value(v), right(nullptr), left(nullptr) {}
    };

    Node* root;

public:
    BinaryTree () : root(nullptr) {}

    ValueType find (const KeyType& key) const // Maybe return only value?
    {
        return find (root, key)->value;
    }

    void remove (const KeyType& key)
    {
        remove (root, key);
    }

    void insert (const KeyType& key, const ValueType& value)
    {
        insert (root, key, value);
    }

    void printTree () const
    {
        printTree (root, "", false);
    }

private:
    Node* insert (Node* node, const KeyType& key, const ValueType value)
    {
        if (root == nullptr)
        {
            root = new Node (key, value);

            return root;
        }

        if (key < node->key)
        {
            if (node->left == nullptr)
            {
                node->left = new Node (key, value);

                return node;
            }

            return insert (node->left, key, value);
        }
        else if (key > node->key)
        {
            if (node->right == nullptr)
            {
                node->right = new Node (key, value);

                return node;
            }

            return insert (node->right, key, value);
        }
        else
        {
            node->key   = key;
            node->value = value;
        }

        return node;
    }

    Node* find (Node* node, const KeyType& key) const
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (key > node->key)
        {
            return find (node->right, key);
        }
        else if (key < node->key)
        {
            return find (node->left, key);
        }

        return node;
    }

    Node* remove (Node* node, const KeyType& key)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->key < key)
        {
            if (node->left)
            {
                remove (node->left, key);
            }
        }
        else if (node->key > key)
        {
            if (node->right)
            {
                remove (node->right, key);
            }
        }
        else
        {
            removeSubTree (node);

            delete node;
        }

        return node;
    }

    void removeSubTree (Node* node)
    {
        if (node->right)
        {
            removeSubTree (node->right);
        }

        if (node->left)
        {
            removeSubTree (node->left);
        }

        delete node;
    }

    Node* findMin (Node* node) const
    {
        while (node)
        {
            node = node->left;
        }

        return node;
    }

    void printTree (Node* node, const std::string& prefix, bool isLeft) const
    {
        if (node == nullptr)
        {
            return;
        }

        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );

        std::cout << node->value << std::endl;

        printTree(node->left,  prefix + (isLeft ? "│   " : "    "), true);
        printTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
};

}

#endif // ALIB_BTREE_HPP
