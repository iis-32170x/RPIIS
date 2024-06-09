#include "Header.h"
#include <iostream>
using namespace std;
void Add(vetka*& current, int value) {
	if (!current) {
		current = new vetka(value);
		return;
	}
	else
		if (value < current->data) {
			Add(current->left, value);
		}
		else if (value > current->data)
		{
			Add(current->right, value);
		}
		else 	return;
}

vetka* findMinNode(vetka* node) {
	if (node == nullptr) {
		return nullptr; 
	}
	else if (node->left == nullptr) {
		return node; 
	}
	else {
		return findMinNode(node->left); 
	}
}

void removeNode(vetka*& current, int value) {
	if (current == nullptr) {
		return; 
	}
	if (value < current->data) {
		
		removeNode(current->left, value);
	}
	else if (value > current->data) {
		
		removeNode(current->right, value);
	}
	else {
		
		if (current->left == nullptr) {
			
			vetka* temp = current;
			current = current->right;
			delete temp;
		}
		else if (current->right == nullptr) {
			
			vetka* temp = current;
			current = current->left;
			delete temp;
		}
		else {
			
			vetka* minRight = findMinNode(current->right);
			current->data = minRight->data;
			removeNode(current->right, minRight->data);
		}
	}
}

void proverka(int value, vetka* node, vetka*& mnozhC) {
	if (!node) return;
	if (node->data == value) {
		Add(mnozhC, value);
		return;
	}
	proverka(value, node->left, mnozhC);
	proverka(value, node->right, mnozhC);
}



void Peresechenie(vetka* mnozhA, vetka* mnozhB, vetka*& mnozhC) {
	if (!mnozhA) return;
	proverka(mnozhA->data, mnozhB, mnozhC);

	Peresechenie(mnozhA->left, mnozhB, mnozhC);
	Peresechenie(mnozhA->right, mnozhB, mnozhC);
}


void add1(vetka*& current, vetka*& mnozhC) {
	if (!current) return;
	Add(mnozhC, current->data);
	add1(current->right, mnozhC);
	add1(current->left, mnozhC);
}

void Objedinenie(vetka* mnozhA, vetka* mnozhB, vetka*& mnozhC) {
	add1(mnozhA, mnozhC);
	add1(mnozhB, mnozhC);
}

vetka* FindElem(vetka* node, int value) {
	setlocale(LC_ALL, "Russian");
	if (!node) {
		cout << "Ёлемент не найден";
		return NULL;
	}
	if (node->data == value) {
		cout << "Ёлемент найден";
		return node;
	}
	if (node->data < value)
		FindElem(node->right, value);
	else
		FindElem(node->left, value);
}

void print(vetka* node) {
	if (!node) return;

	print(node->left);
	cout << node->data << " ";
	print(node->right);
}