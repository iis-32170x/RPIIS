#include <iostream>
#include "Mnozhestva.h"

using namespace std;

int main() {

	bool el = false;
	Branch* root4 = nullptr;
	Branch* root3 = nullptr;
	Branch* root = nullptr;
	Branch* root2 = nullptr;
	root4 = root;
	Add(root, 5);
	Add(root, 15);
	Add(root, rand() % 100);
	cout << "Вывод бинарного дерева: " << endl;
	
	print(root);

	cout << endl;
	Add(root2, 52);
	Add(root2, 15);
	Add(root2, rand() % 100);
	cout << endl << "Вывод бинарного дерева: " << endl;
	print(root2);
	
	Peresechenie(root, root2, root3);
	cout << endl << endl << "Пересечение" << endl;
	print(root3);

	Objedinenie(root, root2, root4);
	cout << endl << endl << "Объединение" << endl;
	print(root4);
	cout << endl;

	FindElem(root4, 697);

	cout << endl << endl << "Удаление" << endl;
	removeNode(root4, 41);
	print(root4);

	
	return 0;
}