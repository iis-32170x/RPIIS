#ifndef TREAP1_H
#define TREAP1_H

#include <iostream>
#include <fstream>
#include <random>

struct Node
{
  int key;
  int priority;
  Node *left;
  Node *right;

  Node(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////

Node *merge(Node *left, Node *right)
{
  if (left == nullptr)
    return right;
  if (right == nullptr)
    return left;

  if (left->priority > right->priority)
  {
    left->right = merge(left->right, right);
    return left;
  }
  else
  {
    right->left = merge(left, right->left);
    return right;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void split(Node *root, int key, Node *&left, Node *&right)
{
  if (root == nullptr)
  {
    left = nullptr;
    right = nullptr;
  }
  else if (root->key <= key)
  {
    split(root->right, key, root->right, right);
    left = root;
  }
  else
  {
    split(root->left, key, left, root->left);
    right = root;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void insert(Node *&root, int key)
{
  Node *newNode = new Node(key);
  Node *left;
  Node *right;
  split(root, key, left, right);
  root = merge(merge(left, newNode), right);
}
////////////////////////////////////////////////////////////////////////////////////////////////

Node *intersection(Node *left, Node *right)
{
  if (left == nullptr || right == nullptr)
    return nullptr;

  if (left->key == right->key)
  {
    Node *newtree = new Node(left->key);
    insert(newtree, left->key);
    newtree->left = intersection(left->left, right->left);
    newtree->right = intersection(left->right, right->right);
    return newtree;
  }
  else
  {
    if (left->key < right->key)

      return intersection(left->right, right);

    else

        if (left->key > right->key)

      return intersection(left, right->right);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////

Node *search(Node *root, int key)
{
  if (root == nullptr || root->key == key)
  {
    return root;
  }
  else if (key < root->key)
  {
    return search(root->left, key);
  }
  else
  {
    return search(root->right, key);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void remove(Node *&root, int key)
{
  if (root == nullptr)
    return;

  if (root->key == key)
  {
    Node *temp = root;
    root = merge(root->left, root->right);
    delete temp;
  }
  else if (key < root->key)
  {
    remove(root->left, key);
  }
  else
  {
    remove(root->right, key);
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void buildTree(Node *&root, std::vector<int> arr, int n)
{

  for (int i = 0; i < n; i++)
  {
    insert(root, arr[i]);
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void printTree(Node *root, std::ofstream &file, int level)
{
  if (root == nullptr)
    return;

  printTree(root->right, file, level + 1);
  for (int i = 0; i < level; i++)
    file << "          ";
  file << root->key << '\n';
  printTree(root->left, file, level + 1);
}
#endif