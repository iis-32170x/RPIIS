#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroyTree();
}

Node* BinarySearchTree::insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

Node* BinarySearchTree::search(Node* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

Node* BinarySearchTree::deleteNode(Node* node, int key) {
    if (node == nullptr) return node;

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

          Node* temp = findMin(node->right);
          node->key = temp->key;
          node->right = deleteNode(node->right, temp->key);
      }
      return node;
  }

  Node* BinarySearchTree::findMin(Node* node) {
      Node* current = node;
      while (current && current->left != nullptr) {
          current = current->left;
      }
      return current;
  } 

  void BinarySearchTree::insert(int key) {
      root = insert(root, key);
  }

  bool BinarySearchTree::search(int key) {
      return search(root, key) != nullptr;
  }
  
  void BinarySearchTree::deleteKey(int key) {
      root = deleteNode(root, key);
  }
  
  void BinarySearchTree::destroyTree(Node* node) {
      if (node) {
          destroyTree(node->left);
          destroyTree(node->right);
          delete node;
      }
  }

  void BinarySearchTree::destroyTree() {
      destroyTree(root);
  }
  
  void BinarySearchTree::inorderTraversal(Node * node) {
      if (node != nullptr) {
          inorderTraversal(node->left);
          std::cout << node->key << " ";
          inorderTraversal(node->right);
      }
  }

  void BinarySearchTree::inorderTraversal() {
      inorderTraversal(root);
      std::cout << std::endl;
  }
  
 
  