#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
export module function;
export struct TreeNode {
    int data;
    vector<TreeNode*> children;
    TreeNode* parent;
};
export  TreeNode* getNewNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    return newNode;
}

export void addChild(TreeNode* node, int data) {
    TreeNode* newNode = getNewNode(data);
    newNode->parent = node;
    node->children.push_back(newNode);
}

export void printTree(TreeNode* root, int depth = 0) {
    if (root == nullptr)
        return;

    for (int i = 0; i < depth; i++)
        cout << "  ";
    cout << "|--" << root->data << endl;

    for (TreeNode* child : root->children)
        printTree(child, depth + 1);
}

export TreeNode* findNode(TreeNode* node, int value) {
    if (node == nullptr)
        return nullptr;

    if (node->data == value)
        return node;

    TreeNode* foundNode = nullptr;
    for (TreeNode* child : node->children) {
        foundNode = findNode(child, value);
        if (foundNode != nullptr)
            break;
    }

    return foundNode;
}

export void deleteTree(TreeNode* root) {
    if (root == nullptr)
        return;

    for (TreeNode* child : root->children) {
        deleteTree(child);
    }

    delete root;
}

export TreeNode* deleteNode(TreeNode* root, int value) {
    TreeNode* searchedNode = findNode(root, value);
    if (searchedNode == nullptr) {
        cout << "Узел не найден " << value << endl;
        return root;
    }
    if (searchedNode == root) {
        cout << "Ты только что удалил корневой узел" << endl;
        deleteTree(root);
        return nullptr;
    }
    TreeNode* parent = searchedNode->parent;

    //Если узел является листом, просто удалите его из дочерних элементов родителя.
    if (searchedNode->children.empty()) {
        auto it = remove(parent->children.begin(), parent->children.end(), searchedNode);
        parent->children.erase(it, parent->children.end());
        delete searchedNode;
    }
    //Если у него более одного дочернего элемента и он хочет повысить уровень всех дочерних элементов
    else {
        auto it = remove(parent->children.begin(), parent->children.end(), searchedNode);
        parent->children.erase(it, parent->children.end());
        for (TreeNode* child : searchedNode->children) {
            child->parent = parent;
            parent->children.push_back(child);
        }
        delete searchedNode;
    }

    return root;
}