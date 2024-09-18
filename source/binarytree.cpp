#include <iostream>

#include "binarytree.hpp"

int main ()
{
    alib::BinaryTree<int, int> tree = {};

    tree.insert(5, 100);

    tree.insert(3, 120);
    tree.insert(7, 130);
    tree.insert(2, 140);
    tree.insert(4, 150);

    tree.printTree();

    tree.remove(3); // Remove node with key 3
    tree.printTree();
    std::cout << "Inorder Traversal after removing key 3:" << std::endl;

    return 0;
}
