#pragma once
struct Branch
{
	int data; //Поле данных

	Branch* left; //УКАЗАТЕЛИ на соседние веточки

	Branch* right;

	Branch(int val) : data(val), left(nullptr), right(nullptr) {}


};
void Add(Branch*& current, int value);
Branch* findMinNode(Branch* node);
void removeNode(Branch*& current, int value);
void proverka(int value, Branch* node, Branch*& mnozhC);
void Peresechenie(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC);
void add1(Branch*& current, Branch*& mnozhC);
void Objedinenie(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC);
void print(Branch* node);
Branch* FindElem(Branch* node, int value);
