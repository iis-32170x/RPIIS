#include "Header.h"
using namespace std;
int main()
{
	system("chcp 1251 > nul");
	Treap tree;
	//Tест 1:
	if (!tree.root) cout << "Тест 1 пройден\n";
	// Тест 2:
	vector <int> keys = {1,3, 2, 4 };
	tree.buildTree(keys);
	tree.outTree(tree.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	for (int key: keys)
	{
		if (tree.search(tree.root, key)-> key!= key)
		{
			cout << "Ошибка";
			return 0;
		}
	}
	cout << "Тест 2 пройден\n";
	// Тест 3:
	for (int key : keys)
	{
		tree.erase(tree.root, key);
	}
	if(tree.root == nullptr) cout << "Тест 3 пройден\n";
	//Тест 4:
	tree.insert(9, 5);
	if (tree.search(tree.root, 9)->key == 9) cout << "Тест 4 пройден\n";
	tree.erase(tree.root, 9);
	//Тест 5:
	vector <int> keys2 = { 3, 5, 7, 8};
	vector <int> prioritys = { 5, 11, 4, 2};
	Treap tree2;
	tree2.buildTree(keys2, prioritys);
	for (int key : keys2)
	{
		if (tree2.search(tree2.root, key)->key != key)
		{
			cout << "Ошибка";
			return 0;
		}
	}
	tree2.outTree(tree2.root, 0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "Тест 5 пройден\n";
	//Тест 6:
	Treap uniontree,tree1;
	tree1.buildTree(keys);
	uniontree.root = uniontree.unite(tree1.root, tree2.root);
	uniontree.outTree(uniontree.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "Тест 6 пройден\n";
	//Тест 7:
	Treap intersection,tree3;
	tree3.buildTree(keys);
	tree3.insert(5);
	tree3.insert(7);
	intersection.root = intersection.intersect(tree2.root, tree3.root);
	intersection.outTree(intersection.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "Тест 7 пройден\n";
}