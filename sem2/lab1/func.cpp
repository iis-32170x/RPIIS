#include "func.h"

node* create()
{
	int value;
	cout << "Введите значение корня дерева: " << endl;
	cin >> value;
	node* root = new node;
	root->key = value;

	return root;
}

void add(node*& parent, int n)
{
	int o;int depth;
	cout << "Введите уровень дерева: " << endl;
	cin >> depth;
	node* g = parent;
	for (int i = 0;i < depth - 1; i++)
	{
		for (int j = 0;j < g->children.size();j++)
		{
			cout << g->children[j]->key << " ";
		}
		cout << "Выберете номер узла: " << endl;
		cin >> o;
		g = g->children[o - 1];

	}
	for (int j = 0;j < g->children.size();j++)
	{
		cout << g->children[j]->key << " ";
	}
	int value;
	cout << "Введите значение: " << endl;
	cin >> value;
	if (g->children.size() < n)
	{
		node* k = new node;
		k->key = value;
		g->children.push_back(k);
		return;
	}


}

void deleteNode(node* parent, node* nodeToDelete)
{
	if (!parent || !nodeToDelete) return;

	auto it = find(parent->children.begin(), parent->children.end(), nodeToDelete);

	if (it != parent->children.end()) {

		parent->children.erase(it);


		for (node* child : nodeToDelete->children)
			deleteNode(nodeToDelete, child);


		delete nodeToDelete;
	}
}

void find4del(node* parent)
{
	int o;int depth;
	cout << "Введите уровень дерева: " << endl;
	cin >> depth;
	node* g = parent;
	for (int i = 0;i < depth; i++)
	{
		for (int j = 0;j < g->children.size();j++)
		{
			cout << g->children[j]->key << " ";
		}
		cout << "Выберете номер узла: " << endl;
		cin >> o;
		parent = g;
		g = g->children[o - 1];

	}
	deleteNode(parent, g);


}

void deleteTree(node*& parent)
{
	for (node* child : parent->children)
	{
		deleteNode(parent, child);
	}
	delete parent;
	parent = NULL;

}

void print(node* root, int depth)
{
	if (!root) return;

	for (int i = 0; i < depth; ++i)
		cout << "  ";
	cout << root->key << endl;

	for (node* child : root->children)
	{
		print(child, depth + 1);
	}
}

void text(int n)
{
	cout << "арность дерева " << n << endl;
	cout << "\nНажмите 1 чтобы создать дерево" << endl;
	cout << "Нажмите 2 чтобы добавить узел" << endl;
	cout << "Нажмите 3 чтобы удалить узел" << endl;
	cout << "Нажмите 4 для просмора дерева" << endl;
	cout << "Нажмите 5 для удаления дерева" << endl;
	cout << "Нажмите 6 для выхода" << endl;

}

void work()
{
	setlocale(LC_ALL, "RU");
	cout << "Ведите арность дерева" << endl;
	int n;
	cin >> n;
	system("cls");
	node* root = NULL;
	while (true)
	{
		text(n);
		switch (_getch())
		{
		case '1':
			root = create();

			break;

		case '2':

			add(root, n);

			break;

		case '3':
			find4del(root);

			break;
		case '4':
			print(root, 0);

			break;
		case '5':
			deleteTree(root);

			break;
		case '6':
			exit(0);
			break;
		}
		system("pause");
		system("cls");

	}


	return;
}
