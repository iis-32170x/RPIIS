#ifndef SYMM_DIF_HPP
#define SYMM_DIF_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
#include <fstream>
#include <set>

std::vector<std::string> readSets(const std::string &filepath);
bool bracketsBalance(const std::string& line);
bool stringsAreEqual(const std::string &str1, const std::string &str2);
std::vector<std::string> parseString(const std::string &str);
bool elemInSet(const std::string &elem, std::vector<std::string> set);
void removeMultiOccurence(std::vector<std::string> &set);
void removeDuplicatesRecursive(std::vector<std::string> &set);
std::vector<std::string> set_union(const std::vector<std::string> &set1, const std::vector<std::string> &set2);
std::vector<std::string> set_difference(const std::vector<std::string> &set1, const std::vector<std::string> &set2);

#endif