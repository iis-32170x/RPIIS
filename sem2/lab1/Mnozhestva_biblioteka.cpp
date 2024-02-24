#include "Mnozhestva.h"
#include <iostream>

void Add(Branch*& current, int value) {
	if (!current) {
		current = new Branch(value);
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

Branch* findMinNode(Branch* node) {
	if (node == nullptr) {
		return nullptr; // Не найден минимальный узел
	}
	else if (node->left == nullptr) {
		return node; // Мы достигли самого левого узла в дереве
	}
	else {
		return findMinNode(node->left); // Рекурсивно ищем в левом поддереве
	}
}

void removeNode(Branch*& current, int value) {
	if (current == nullptr) {
		return; // Узел не найден
	}
	if (value < current->data) {
		// Ищем в левом поддереве
		removeNode(current->left, value);
	}
	else if (value > current->data) {
		// Ищем в правом поддереве
		removeNode(current->right, value);
	}
	else {
		// Нашли узел
		if (current->left == nullptr) {
			// Узел имеет только правого потомка
			Branch* temp = current;
			current = current->right;
			delete temp;
		}
		else if (current->right == nullptr) {
			// Узел имеет только левого потомка
			Branch* temp = current;
			current = current->left;
			delete temp;
		}
		else {
			// Узел имеет двух потомков, находим и удаляем узел с минимальным значением в правом поддереве
			Branch* minRight = findMinNode(current->right);
			current->data = minRight->data;
			removeNode(current->right, minRight->data);
		}
	}
}

void proverka(int value, Branch* node, Branch*& mnozhC) {
	if (!node) return;
	if (node->data == value) {
		Add(mnozhC, value);
		return;
	}
	proverka(value, node->left, mnozhC);
	proverka(value, node->right, mnozhC);
}



void Peresechenie(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC) {
	if (!mnozhA) return;
	proverka(mnozhA->data, mnozhB, mnozhC);

	Peresechenie(mnozhA->left, mnozhB, mnozhC);
	Peresechenie(mnozhA->right, mnozhB, mnozhC);
}


void add1(Branch*& current, Branch*& mnozhC) {
	if (!current) return;
	Add(mnozhC, current->data);
	add1(current->right, mnozhC);
	add1(current->left, mnozhC);
}

void Objedinenie(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC) {
	add1(mnozhA, mnozhC);
	add1(mnozhB, mnozhC);
}

Branch* FindElem(Branch* node, int value) {
	if (!node){
		std::cout << "Элемент не найден";
		return NULL;
}
	if (node->data == value) {
		std::cout << "Элемент найден";
		return node;
	}
	if (node->data<value)
		FindElem(node->right, value);
	else 
		FindElem(node->left, value);
}

void print(Branch* node) {
	if (!node) return;

	print(node->left);
	std::cout << node->data << " ";
	print(node->right);
}
