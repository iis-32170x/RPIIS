#include "Header.h"
using namespace N;
Node::Node(int val) {
	left = nullptr;
	right = nullptr;
	data = val;
    par = nullptr;
}
Node* bst::search(Node* node, int val)
{
    // not found 
    if (node == NULL)
        return NULL;
    // is found
    else if (node->data == val)
        return node;
    // greater
    else if (node->data < val)
        return search(node->right, val);
    // smaller
    else
        return search(node->left, val);
}
bool bst::search(int val)
{
    Node* result = search(root, val);

    return result == NULL ?
        false :
        true;
}
Node* bst::Insert(Node* node, int val)
{
    // new
    if(node == NULL)
    {
        node = new Node(val);
        node->left = NULL;
        node->right = NULL;
        node->par = NULL;
    }
    // greater
    else if (node->data < val)
    {
        node->right = Insert(node->right, val);
        node->right->par = node;
    }
    // smaller
    else
    {
        node->left = Insert(node->left, val);
        node->left->par = node;
    }
    return node;

}
void bst::Insert(int key)
{
    root = Insert(root, key);
}
void bst::bypass(Node* node) {
    //stop
    if (node == NULL)
        return;
    //smallest
    bypass(node->left);

    // Print 
    std::cout << node->data << " ";

    bypass(node->right);
}
void bst::bypass() {
    bypass(root);
    std::cout << std::endl;
}
Node* bst::min(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
Node* bst::Remove(Node* node, int val) {
    // not found
    if (root == nullptr) {
        return root;
    }

    else if (val < root->data) {
        root->left = Remove(root->left, val);
    }
    else if (val > root->data) {
        root->right = Remove(root->right, val);
    }
    else {
        // Узел с ключом найден, производим удаление

        // Узел без потомков или с одним потомком
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Узел с двумя потомками
        Node* minRight = min(root->right);
        root->data = minRight->data;
        root->right = Remove(root->right, minRight->data);
    }

    return root;
}
void bst::Remove(int val) {
    root = Remove(root, val);
}
Node* bst::CreateBSTarr(int arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = CreateBSTarr(arr, start, mid - 1);
    root->right = CreateBSTarr(arr, mid + 1, end);

    return root;
}


