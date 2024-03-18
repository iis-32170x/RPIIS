#ifndef BRANCH_H
#define BRANCH_H

struct Branch {
    int data;
    Branch* left;
    Branch* right;

    Branch(int value) : data(value), left(nullptr), right(nullptr) {}
};

void Add(Branch*& current, int value);
Branch* findMinNode(Branch* node);
void removeNode(Branch*& current, int value);
Branch* FindElem(Branch* node, int value);
void print(Branch* node);
void UnionAdd(Branch*& current, Branch*& mnozhC);
void Union(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC);
void proverka(int value, Branch* node, Branch*& mnozhC);
void Intersection(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC);

#endif
