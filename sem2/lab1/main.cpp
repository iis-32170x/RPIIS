#include <iostream>
#include <cstdlib>
#include <vector>

#include "BST.cpp"

using namespace std;

int main()
{
	// Пользователь созадет свое множесто ключей дерева
	int size;
	cout << "Number of elements in your tree:\t";
	cin >> size;

	vector <int> TreeKeys(size);
	for (int i = 0; i < size; i++)
	{
		int tempNum;
		cin >> tempNum;

		TreeKeys[i] = tempNum;
	}

	cout << "\n";



	BST clientTree;
	
	// Показываем пользователю, что пока дерево пусто
	cout << "Printing the tree in order (before adding number)\n";
	clientTree.PrintInOrder();


	// Создаем Бинарное Дерево Поиска из массива, созданного пользователем 
	for (int i = 0; i < size; i++)
	{
		clientTree.AddLeaf(TreeKeys[i]);
	}


	cout << "\n";


	// Выводим на экран созданное БДР симметричным обходом 
	cout << "Printing the tree in order (after adding number)\n";
	clientTree.PrintInOrder();
	
	cout << "\n" << "\n";
	

	// Выводим для каждого узла его детей
	for (int i = 0; i < size; i++)
	{
		clientTree.PrintChildren(TreeKeys[i]);
		cout << "\n";
	}

	
	// Предоставляем возможность пользователю удалить желанный узел
	cout << "Enter a key to delete. Enter \"-1\" to stop deleting.\n";

	int deleteKey = 0;
	while (deleteKey != -1)
	{
		cout << "Delete node:\t";
		cin >> deleteKey;
		{
			if (deleteKey != -1)
			{
				cout << endl;
				clientTree.RemoveNode(deleteKey);
				clientTree.PrintInOrder();
				cout << endl;

			}
		}
	}

	cout << endl;
	// Деструктор, который удаляет созданное БДР обратным обходом
}