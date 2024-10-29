//
// Created by xinardelis on 29/10/24.
//

#include "dictionary.h"
#include <iostream>
#include <fstream>

Dictionary::Dictionary() {
  this->root_ = nullptr;
  this->size_ = 0;
}

Dictionary::Dictionary(Dictionary &tree) {
  this->size_ = tree.size_;
  this->root_ = copyTree_(tree.root_);
}

Dictionary::Node *Dictionary::copyTree_(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
  Node *newNode = new Node;
  newNode->key = node->key;
  newNode->value = node->value;
  newNode->left = copyTree_(node->left);
  newNode->right = copyTree_(node->right);
  return newNode;
}

Dictionary::~Dictionary() {
  deleteTree_(this->root_);
}

void Dictionary::deleteTree_(Node *node) {
  if (node == nullptr) {
    return;
  }
  deleteTree_(node->left);
  deleteTree_(node->right);
  delete node;
}

std::string &Dictionary::operator[](const std::string &key) {
  Node *node = root_;
  while (node != nullptr) {
    if (node->key == key) {
      return node->value;
    }
    if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }

  throw std::out_of_range("Key not found");
}

void Dictionary::operator-=(const std::string &key) {
  Node *node = root_;
  Node *parent = nullptr;
  while (node != nullptr) {
    if (node->key == key) {
      if (node->left == nullptr && node->right == nullptr) {
        if (parent == nullptr) {
          root_ = nullptr;
        } else if (parent->left == node) {
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
        delete node;
        size_--;
        return;
      }
      if (node->left == nullptr) {
        if (parent == nullptr) {
          root_ = node->right;
        } else if (parent->left == node) {
          parent->left = node->right;
        } else {
          parent->right = node->right;
        }
        delete node;
        size_--;
        return;
      }
      if (node->right == nullptr) {
        if (parent == nullptr) {
          root_ = node->left;
        } else if (parent->left == node) {
          parent->left = node->left;
        } else {
          parent->right = node->left;
        }
        delete node;
        size_--;
        return;
      }
      Node *minNode = node->right;
      Node *minParent = node;
      while (minNode->left != nullptr) {
        minParent = minNode;
        minNode = minNode->left;
      }
      node->key = minNode->key;
      node->value = minNode->value;
      if (minParent->left == minNode) {
        minParent->left = minNode->right;
      } else {
        minParent->right = minNode->right;
      }
      delete minNode;
      size_--;
      return;
    }
    parent = node;
    if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
}

void Dictionary::operator+=(const std::string &key) {
  Node *node = root_;
  Node *parent = nullptr;
  while (node != nullptr) {
    if (node->key == key) {
      return;
    }
    parent = node;
    if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  node = new Node;
  node->key = key;
  node->value = "";
  node->left = nullptr;
  node->right = nullptr;
  if (parent == nullptr) {
    root_ = node;
  } else if (key < parent->key) {
    parent->left = node;
  } else {
    parent->right = node;
  }
  size_++;
}

int Dictionary::size() const {
  return this->size_;
}

void Dictionary::save(const std::string &filename) const {
  std::ofstream file(filename);
  saveNode_(file, root_);
  file.close();
}

void Dictionary::saveNode_(std::ofstream &file, Dictionary::Node *node) const {
    if (node == nullptr) {
        file << "#\n";
        return;
    }
    file << node->key << ' ' << node->value << '\n';
    saveNode_(file, node->left);
    saveNode_(file, node->right);
}

void Dictionary::loadNode_(std::ifstream &file, Dictionary::Node *&node, int &size) {
    std::string key, value;
    if (!(file >> key) || key == "#") {
        node = nullptr;
        return;
    }
    file >> value;
    node = new Node;
    node->key = key;
    node->value = value;
    size += 1;
    loadNode_(file, node->left, size);
    loadNode_(file, node->right, size);
}

void Dictionary::load(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("File not found");
  }

  deleteTree_(root_);
  this->size_ = 0;
  root_ = nullptr;

  loadNode_(file, this->root_, this->size_);

  file.close();
}

