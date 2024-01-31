#include <iostream>

using namespace std;

struct node 
{
	int info; // значения
	node* left; // указатель на левое поддерево
	node* right; // указатель на правое поддерево
	int balance; // баланс: высота правого поддерева минус высота левого поддерева
};

int Height(node* root); // вычисление высоты дерева

void SetBalance(node* (&root)); //нахождение значение баланса для текущего узла
void TurnLeft(node* (&root)); // левый поворот дерева
void TurnRight(node* (&root)); // правый поворот дерева
void insert(node* (&root), int d); // добавление узла в дерево поиска
void output(node* p);  // распечатка дерева в симметрическом порядке
void print_n(const node* p, int n, int level, int prob); // печать n-ого уровня дерева
void print(node* p); // распечатка дерева по уровням
void clear(node** p); // очистка

node* minValueNode(node* root); // поиск минимума
node* maxValueNode(node* root); // поиск максимума
node* deleteNode(node* root, int key); // удаление узла дерева
node* findClosestMin(node* root, int value); // поиск ближайшего меньшего
node* findClosestMax(node* root, int value); // поиск ближайшего большего
node* search(node* root, int value); // поиск нужной ячейки 

int main() 
{
	int d;
	char ch1, ch2;
	int keyToDelete;
	int valueToFindMin, valueToFindMax, valueToSearch;
	node* root;
	root = NULL;
	do {
		cout << "Enter the number: ";
		cin >> d;
		insert(root, d);
		cout << "Enter another number?(y/n) Answer: ";
		cin >> ch1;
	} while (ch1 != 'n');

	cout << "Print out the tree in symmetrical order: ";
	output(root);
	cout << endl;
	cout << "Print out the tree." << endl;
	print(root);
	node* maxNode = maxValueNode(root);
	cout << "Maximum value in the tree: " << maxNode->info << endl;
	node* minNode = minValueNode(root);
	cout << "Minimum value in the tree: " << minNode->info << endl;
	cout << "Enter the node relative to which you want to find the nearest smaller node: ";
	cin >> valueToFindMin;
	node* closestMinNode = findClosestMin(root, valueToFindMin);
	if (closestMinNode != nullptr) {
		cout << "The nearest smaller to " << valueToFindMin << " : " << closestMinNode->info << endl;
	}
	else {
		cout << "The nearest smaller isn't exist " << valueToFindMin << endl;
	}
	cout << "Enter the node relative to which you want to find the nearest larger node: ";
	cin >> valueToFindMax;
	node* closestMaxNode = findClosestMax(root, valueToFindMax);
	if (closestMaxNode != nullptr) {
		cout << "The nearest larger to " << valueToFindMax << " : " << closestMaxNode->info << endl;
	}
	else {
		cout << "The nearest larger isn't exist " << valueToFindMax << endl;
	}
	cout << "Enter the node that you prefer to find: ";
	cin >> valueToSearch;
	node* resultNode = search(root, valueToSearch);
	if (resultNode != nullptr) {
		cout << "Node with pointer " << valueToSearch << " found." << endl;
	}
	else {
		cout << "Node with pointer " << valueToSearch << " didn't find." << endl;
	}
	do {
		cout << "Choose the node you prefer to delete: ";
		cin >> keyToDelete;
		cout << "Tree with deleted node:\n";
		root = deleteNode(root, keyToDelete);
		print(root);
		cout << "Delete another number?(y/n) Answer: ";
		cin >> ch2;
	} while (ch2 != 'n');
	clear(&root);
	if (!root)
	{
		cout << "The tree has been successfully cleared!" << endl;
	}
	else
	{
		cout << "The error of clearing!!!" << endl;
	}
	return 0;
}

int Height(node* root) // вычисление высоты дерева
{
	if (root == NULL)
		return 0; // если дерево пусто возвращаем 0
	else {
		int hLeft = Height(root->left), // считаем высоту левого поддерева
			hRight = Height(root->right); // считаем высоту правого поддерева
		if (hLeft > hRight) // если высота слева больше то возвращаем ее + 1(т.е. добавили еще наш узел)
			return hLeft + 1;
		else
			return hRight + 1; // иначе возвращаем высоту правого поддерева + 1
	}
}

void SetBalance(node* (&root)) //нахождение значение баланса для текущего узла
{
	if (root != NULL)
		root->balance = Height(root->right) - Height(root->left);
}

void TurnLeft(node* (&root)) // левый поворот дерева
{
	node* rightSubtree, * rightSubtreeLeftSubtree;
	rightSubtree = root->right;
	rightSubtreeLeftSubtree = rightSubtree->left;

	rightSubtree->left = root;
	root->right = rightSubtreeLeftSubtree;
	root = rightSubtree;
	SetBalance(root->left);
	SetBalance(root);
}

void TurnRight(node* (&root)) //правый поворот АВЛ-дерева
{
	node* leftSubtree, * leftSubtreeRightSubtree;
	leftSubtree = root->left;
	leftSubtreeRightSubtree = leftSubtree->right;

	leftSubtree->right = root;
	root->left = leftSubtreeRightSubtree;
	root = leftSubtree;
	SetBalance(root->right);
	SetBalance(root);
}

void insert(node* (&root), int d) // добавление узла в дерево поиска
{
	if (root == NULL) // нашли пустой указатель(пустое место)
	{ // создаём новый узел дерева на найденном месте
		root = new node;
		root->info = d;
		root->balance = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else // если текущий узел не пусто, то...
	{
		if (d > root->info) // идём в правое поддерево
		{
			insert(root->right, d); // добавляем узел в правое поддерево
			if (Height(root->right) - Height(root->left) > 1) // если баланс АВЛ-дерева нарушен, то...
			{
				if (Height(root->right->right) < Height(root->right->left)) // а если были еще проблемы в поддеревьях у правого поддерева 
					TurnRight(root->right); // то предварительно поворачиваем правое поддерево
				TurnLeft(root); // поворот дерева влево
			}
		}
		else
			if (d < root->info) // идем в левое поддерево
			{
				insert(root->left, d); // добавляем узел в левое поддерево
				if (Height(root->left) - Height(root->right) > 1) //если баланс АВЛ - дерева нарушен, то...
				{
					if (Height(root->left->left) < Height(root->left->right)) //а если были еще проблемы в поддеревьях у левого поддерева 
						TurnLeft(root->left); // то предварительно поворачиваем левое  поддерево
					TurnRight(root); // поворот дерева вправо
				}
			}
		SetBalance(root); // пересчитываем значение баланса
	}
}

void output(node* p)   // распечатка дерева в симметрическом порядке
{
	if (p != NULL)
	{
		output(p->left);
		cout << p->info << " ";
		output(p->right);
	}
}

void print_n(const node* p, int n, int level, int prob) // печать n-ого уровня дерева
{
	if (p)
	{
		if (level == n)
		{
			for (int i = 0; i <= prob; i++)
				cout << " ";
			cout << p->info;
		}
		else
		{
			print_n(p->left, n, level + 1, prob);
			print_n(p->right, n, level + 1, prob);
		}
	}
}

void print(node* p) // распечатка дерева по уровням
{
	int h = Height(p);
	int prob = 3;
	if (p)
	{
		for (int i = 0; i <= h; i++) // задаём номера уровней
		{
			print_n(p, i, 0, prob * (h - i)); // вызывается функция печати n-ого уровня дерева
			cout << endl;
		}
	}
}

void clear(node** p) // очистка
{
	if ((*p) != NULL) {
		clear(&(*p)->left);
		clear(&(*p)->right);

		delete* p;
		*p = NULL;
	}
}

node* minValueNode(node* root)  // поиск минимума
{
	node* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
node* maxValueNode(node* root) // поиск максимума
{
	node* current = root;
	while (current->right != NULL) {
		current = current->right;
	}
	return current;
}

node* deleteNode(node* root, int key) // удаление узла дерева 
{
	if (root == NULL) {
		return root;
	}
	if (key < root->info) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->info) {
		root->right = deleteNode(root->right, key);
	}
	else {
		if ((root->left == NULL) || (root->right == NULL)) {
			node* temp = root->left ? root->left : root->right;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else {
				*root = *temp;
			}
			delete temp;
		}
		else {
			node* temp = minValueNode(root->right);
			root->info = temp->info;
			root->right = deleteNode(root->right, temp->info);
		}
	}
	if (root == NULL) {
		return root;
	}
	SetBalance(root);
	if (root->balance > 1) {
		if (root->right->balance < 0) {
			TurnRight(root->right);
		}
		TurnLeft(root);
	}
	else if (root->balance < -1) {
		if (root->left->balance > 0) {
			TurnLeft(root->left);
		}
		TurnRight(root);
	}
	return root;
}

node* findClosestMin(node* root, int value) // поиск ближайшего меньшего
{
	node* closest = nullptr;
	node* current = root;

	while (current != nullptr) {
		if (current->info < value) {
			closest = current;
			current = current->right;
		}
		else {
			current = current->left;
		}
	}

	return closest;
}

node* findClosestMax(node* root, int value) // поиск ближайшего большего
{
	node* closest = nullptr;
	node* current = root;

	while (current != nullptr) {
		if (current->info > value) {
			closest = current;
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	return closest;
} 

node* search(node* root, int value) // поиск нужной ячейки
{
	node* current = root;
	while (current != nullptr && current->info != value) {
		if (value < current->info) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return current;
}

