#pragma once
#include "Node.h"
#include <string>
void AddString(std::string, Node*);
int DelString(std::string s, Node* root);
void rekurs(Node* current, std::string word);
void ShowBor(Node* root);
int SearchString(std::string s, Node* root);
void DelBor(Node*);