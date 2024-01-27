#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "library.h"
int main()
{
  Node *root = nullptr;
  std::ifstream input("input.txt");
  std::vector<int> keys;
  int size;
  input >> size;
  keys.resize(size);
  for (int i = 0; i < size; i++)
  {
    int temp;
    input >> temp;
    keys[i] = temp;
  }
  // EXAMPLE OF BUILDING TREAP///////////////////////////////////
  buildTree(root, keys, size);
  Node *search1 = search(root, 7388);

  std::ofstream file("output.txt");
  file << "---------------------YOUR TREE----------------" << '\n';
  printTree(root, file, 0);
  file << '\n';
  // searching///////////
  file << "----------SEARCH----------" << '\n';
  file << search1 << '\n';
  // removing////////////
  file << "-----------------AFTER REMOVING------------------ " << '\n';
  remove(root, 7388);
  printTree(root, file, 0);
  file.close();

  // creating two "treaps" and their intersection and merge/////////////////////////
  std::vector<int> arr1{3, 2, 5};
  int size1 = arr1.size();
  Node *tree1 = nullptr;
  buildTree(tree1, arr1, size1);

  std::vector<int> arr2{4, 3, 5};
  int size2 = arr2.size();
  Node *tree2 = nullptr;
  buildTree(tree2, arr2, size2);

  Node *intersect = intersection(tree1, tree2);
  Node *merg = merge(tree1, tree2);

  std::ofstream file2("output2.txt");
  file2 << "-------INTERSECTION-------" << '\n';
  printTree(intersect, file2, 0);
  file2 << '\n';
  file2 << "-------MERGE------" << '\n';
  printTree(merg, file2, 0);
  file2.close();

  return 0;
}