//
// Created by xinardelis on 29/10/24.
//

#ifndef LW1_PUSHKO_INCLUDE_BINARY_TREE_H_
#define LW1_PUSHKO_INCLUDE_BINARY_TREE_H_

#include <string>
#include <fstream>

/**
 * @class Dictionary
 * @brief A class representing a binary tree dictionary.
 */
class Dictionary {
 public:
  /**
   * @brief Default constructor for Dictionary.
   */
  Dictionary();

  /**
   * @brief Copy constructor for Dictionary.
   * @param tree The Dictionary to copy.
   */
  Dictionary(Dictionary &tree);

  /**
   * @brief Destructor for Dictionary.
   */
  ~Dictionary();

  /**
   * @brief Overloaded subscript operator to access or modify the value associated with a key.
   * @param key The key to access or modify.
   * @return Reference to the value associated with the key.
   */
  std::string &operator[](const std::string &key);

  /**
   * @brief Overloaded -= operator to remove a key-value pair from the dictionary.
   * @param key The key to remove.
   */
  void operator-=(const std::string &key);

  /**
   * @brief Overloaded += operator to add a key-value pair to the dictionary.
   * @param key The key to add.
   */
  void operator+=(const std::string &key);

  /**
   * @brief Load the dictionary from a file.
   * @param filename The name of the file to load from.
   */
  void load(const std::string &filename);

  /**
   * @brief Save the dictionary to a file.
   * @param filename The name of the file to save to.
   */
  void save(const std::string &filename) const;

  /**
   * @brief Get the size of the dictionary.
   * @return The number of key-value pairs in the dictionary.
   */
  [[nodiscard]] int size() const;

 private:
  /**
   * @struct Node
   * @brief A structure representing a node in the binary tree.
   */
  struct Node {
    std::string key;   ///< The key of the node.
    std::string value; ///< The value of the node.
    Node *left;        ///< Pointer to the left child node.
    Node *right;       ///< Pointer to the right child node.
  };

  Node *root_; ///< Pointer to the root node of the binary tree.
  int size_;   ///< The number of key-value pairs in the dictionary.

  /**
   * @brief Copy the binary tree.
   * @param node The root node of the tree to copy.
   * @return Pointer to the root node of the copied tree.
   */
  Node *copyTree_(Node *node);

  /**
   * @brief Delete the binary tree.
   * @param node The root node of the tree to delete.
   */
  void deleteTree_(Node *node);

  /**
   * @brief Save a node and its children to a file.
   * @param file The file stream to write to.
   * @param node The node to save.
   */
  void saveNode_(std::ofstream &file, Node *node) const;

  /**
   * @brief Load a node and its children from a file.
   * @param file The file stream to read from.
   * @param node Reference to the node pointer to load into.
   * @param size_ Reference to the size counter to update.
   */
  void loadNode_(std::ifstream &file, Node *&node, int &size_);
};

#endif //LW1_PUSHKO_INCLUDE_BINARY_TREE_H_