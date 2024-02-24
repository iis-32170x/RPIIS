#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct treenode {
    int data;
    vector<treenode*> children;
    treenode* parent;
};

treenode* getnewnode(int data) {
    treenode* newnode = new treenode();
    newnode->data = data;
    return newnode;
}

void addchild(treenode* node, int data) {
    treenode* newnode = getnewnode(data);
    newnode->parent = node;
    node->children.push_back(newnode);
}

void printTree(treenode* root, int depth = 0) {
    if (root == nullptr)
        return;

    // Print the current node
    for (int i = 0; i < depth; i++)
        cout << "  ";
    cout << "|--" << root->data << endl;

    // Print each child
    for (treenode* child : root->children)
        printTree(child, depth + 1);
}

treenode* findnode(treenode* node, int a) {
    if (node == nullptr)
        return nullptr;

    if (node->data == a)
        return node;

    treenode* foundnode = nullptr;
    for (treenode* child : node->children) {
        foundnode = findnode(child, a);
        if (foundnode != nullptr)
            break;
    }

    return foundnode;
}
void deleteTree(treenode* root) {
    if (root == nullptr)
        return;

    for (treenode* child : root->children) {
        deleteTree(child);
    }

    delete root;
}

treenode* deletenode(treenode* root, int a) {
    treenode* searchednode = findnode(root, a);
    if (searchednode == nullptr) {
        cout << "Node with data " << a << " not found." << endl;
        return root;
    }
    if (searchednode == root)
    {
        cout << " u have just deleted the tree" << endl;
        deleteTree(root);
        return 0;
}
    treenode* parent = searchednode->parent;

    if (searchednode->children.empty()) {
        // If the node is a leaf, simply remove it from the parent's children
        auto it = std::remove(parent->children.begin(), parent->children.end(), searchednode);
        parent->children.erase(it, parent->children.end());
        delete searchednode;
    }
    else
        // If it has more than one child and wants to promote all children
    {
        auto it = std::remove(parent->children.begin(), parent->children.end(), searchednode);
        parent->children.erase(it, parent->children.end());
        for (treenode* child : searchednode->children) {
            child->parent = parent;
            parent->children.push_back(child);
        }
        delete searchednode;
    }
    

    return root;
}
