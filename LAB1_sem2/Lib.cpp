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
    else if (val > node->data)
    {
        node->right = Insert(node->right, val);
        node->right->par = node;
    }
    // smaller
    else if (val < node->data)
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
    if (node == NULL) {
        return NULL;
    }

    if (val < node->data) {
        node->left = Remove(node->left, val);
    }
    else if (val > node->data) {
        node->right = Remove(node->right, val);
    }
    else {
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = min(node->right);
        node->data = temp->data;
        node->right = Remove(node->right, temp->data);
    }

    return node;
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


