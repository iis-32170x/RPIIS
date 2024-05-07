#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace Y;
using namespace std;

Deck* Deck :: crtdeck() {
	int n; Deck* node1 = new Deck; Deck* node2 = new Deck;
	cout << "Введите количество элементов в деке:";
	cin >> n;
	while (cin.fail()|| n<1) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите количество элементов в деке:";
		cin >> n;
	}
	cout << "Введите элемент:";
	cin >> this->val;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите элемент:";
		cin >> this->val;
	}
	this->prev = nullptr;
	this->next = node1;
	node1->prev = this;
	for (int i = 1; i < n; i++) {
		cout << "Введите элемент:";
		cin >> node1->val;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Введите элемент:";
			cin >> node1->val;
		}
		node2 = new Deck;
		node2->prev = node1;
		node1->next = node2;
		node1 = node2;
	}
	node1 = node1->prev;
	node1->next = nullptr;
	delete node2;
	return this;
}
void Deck::output() {
	Deck* node = new Deck;
	if (this != nullptr&&this->val) {
		node = this;
		while (node != nullptr) {
			cout << node->val << " ";
			node = node->next;
		}
	}
	else {
		cout << "Дек пуст";
	}
	delete node;
	return;
}
Deck* Deck::delfront() {
	Deck* buff = new Deck; 
	this->prev = nullptr;
	buff = this->next;
	if ( buff!=nullptr) {
		this->val = buff->val;
		this->next = this->next->next;
		if (this->next != nullptr) {
			this->next->prev = this;
		}
	}

	return this;
}
Deck* Deck::delback() {
	Deck* buff = new Deck;
	if (this->next != nullptr) {
		this->prev = nullptr;
		buff = this;
		while (buff->next != nullptr) {
			buff = buff->next;
		}
		if (buff->prev != nullptr)
			buff->prev->next = nullptr;
	}
	return this;
}
Deck* Deck::addfront() {
	Deck* node = new Deck;
		node->next = this->next;
		node->prev = this;
		this->next = node;
		if (node->next != nullptr) {
			node->next->prev = node;
		}
		node->val = this->val;
		cout << "Введите значение:";
		cin >> this->val;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Введите значение:";
			cin >> this->val;
		}
	return this;
}
Deck* Deck::addback() {
	Deck* node = new Deck; Deck* runner=this;
	while (runner->next != nullptr) {
		runner = runner->next;
	}
	node->prev = runner;
	runner->next = node;
	cout << "Введите значение:";
	cin >> node->val;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите значение:";
		cin >> node->val;
	}
	node->next = nullptr;
	return this;
}
bool Deck::check() {
	if (this->next == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

Deck* Y::Deck::file()
{
	std::ifstream file("tests.txt");
	if (!file) {
		std::cerr << "Файл не найден." << std::endl;
		exit(0);
	}
	std::string line;
	std::getline(file, line);
	std::istringstream iss(line);
	Y::Deck* deck = this; Deck* buff = nullptr;
	int number;
	deck->prev = nullptr;
	while (iss >> number) {
		deck->val = number;
		buff = new Deck;
		buff->prev = deck;
		deck->next = buff;
		deck = buff;
	}
	deck = deck->prev; deck->next = nullptr;
	return deck;


}
