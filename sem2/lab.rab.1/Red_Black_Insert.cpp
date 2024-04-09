#include "RBtree.h"

using namespace std;

void InsertNode(Node*& root, int value) {

	Node* nodetmp = root;

	//Поиск места для вставки нового узла на основе его значения
	while (true) {						
		if (value < nodetmp->value) {

			if (nodetmp->left == nullptr) {
				nodetmp->left = new Node{ value, nodetmp, nullptr, nullptr, 1 };
				InsertFix(nodetmp->left, root);
				return;
			}
			nodetmp = nodetmp->left;
		}

		else if (value > nodetmp->value) {

			if (nodetmp->right == nullptr) {
				nodetmp->right = new Node{ value, nodetmp, nullptr, nullptr, 1 };
				InsertFix(nodetmp->right, root);
				return;
			}
			nodetmp = nodetmp->right;
		}
		else {
			cout << "Узел с таким значением уже существует!";
			return;
		}
	}
}

void InsertFix(Node* node, Node*& root) {
	while (node->parent->Red) {
		//Если родитель - левый потомок
		if (node->parent == node->parent->parent->left) {
			//Проверяем существует ли правый потомок
			if (node->parent->parent->right != nullptr) {
				//Если правый потомок существует, то проверяем: красный ли он?
				if (node->parent->parent->right->Red) {
					node->parent->Red = 0;
					node->parent->parent->right->Red = 0;
					node->parent->parent->Red = 1;
					node = node->parent->parent;
				}
				else
					//Если правый потомок чёрный, необходимо выполнить поворот или даже два
					goto p1;
			}
			else {
			p1:
				//Если узел находится СПРАВА от отца то выполняется поворот
				if (node == node->parent->right) {
					LeftRotate(root, node->parent->value);
					node = node->left;
				}
				RightRotate(root, node->parent->parent->value);
				node->parent->right->Red = 1;
				node->parent->Red = 0;
				node = node->parent;
			}
		}

		/*Если отец - правый потомок*/
		else {

			//Проверяем существует ли левый потомок
			if (node->parent->parent->left != nullptr) {
				if (node->parent->parent->left->Red) {
					node->parent->Red = 0;
					node->parent->parent->left->Red = 0;
					node->parent->parent->Red = 1;
					node = node->parent->parent;
				}
				else
					//Если левый потомок чёрный, необходимо выполнить поворот или даже два
					goto p2;
			}
			else {

			p2:
				//Если узел находится СЛЕВА от отца то выполняется поворот
				if (node == node->parent->left) {
					RightRotate(root, node->parent->value);
					node = node->right;
				}
				LeftRotate(root, node->parent->parent->value);
				node->parent->left->Red = 1;
				node->parent->Red = 0;
				node = node->parent;
			}
		}
		//Оставляем корень чёрным в любом случае
		root->Red = 0;

		//Прерываем цикл если его значение станет nullptr
		if (node->parent == nullptr)
			break;
	}
}

void DeleteNode(Node*& root, int value) {
	Node* node = root;

	while (node != nullptr)
		if (value < node->value)
			node = node->left;
		else if (value > node->value)
			node = node->right;
		else
			break;

	if (node == nullptr) {
		cout << "Нет вершины с таким значением!";
		return;
	}

	Delete(root, node);
}

void Delete(Node*& root, Node* node) {

	//Удаление красной вершины без потомков
	if (node->Red && node->left == nullptr && node->right == nullptr) {
		ClearNode(node);
	}
	//Удаление вершины с правым потомком
	else if (node->right != nullptr) {
		Node* nodetmp = node->right;

		while (nodetmp->left != nullptr)
			nodetmp = nodetmp->left;

		int tmp = nodetmp->value;
		nodetmp->value = node->value;
		node->value = tmp;

		Delete(root, nodetmp);
	}
	//Удаление вершины с левым потомком
	else if (node->left != nullptr) {
		Node* nodetmp = node->left;

		while (nodetmp->right != nullptr)
			nodetmp = nodetmp->right;

		int tmp = nodetmp->value;
		nodetmp->value = node->value;
		node->value = tmp;

		Delete(root, nodetmp);
	}

	//Удаление чёрной вершины без потомков
	else if (!node->Red && node->left == nullptr && node->right == nullptr) {

		//Если родитель вершины - КРАСНЫЙ
		if (node->parent->Red) {
			//Если узел - ПРАВЫЙ потомок
			if (node == node->parent->right) {
				//Если у "брата" узла есть хотя бы один КРАСНЫЙ потомок слева или справа
				if (node->parent->left->right != nullptr && node->parent->left->right->Red) {
					LeftRotate(root, node->parent->left->value);
					RightRotate(root, node->parent->value);

					node->parent->Red = 0;

					ClearNode(node);
				}
				else if (node->parent->left->left != nullptr && node->parent->left->left->Red) {
					RightRotate(root, node->parent->value);

					node->parent->Red = 0;
					node->parent->parent->Red = 1;
					node->parent->parent->left->Red = 0;

					ClearNode(node);
				}
				//Если у "брата" узла НЕТ красных потомков
				else {
					node->parent->left->Red = 1;
					node->parent->Red = 0;

					ClearNode(node);
				}
			}
			//Если узел - ЛЕВЫЙ потомок
			else {
				//Если у "брата" узла есть хотя бы один КРАСНЫЙ потомок слева или справа
				if (node->parent->right->left != nullptr && node->parent->right->left->Red) {
					RightRotate(root, node->parent->right->value);
					LeftRotate(root, node->parent->value);

					node->parent->Red = 0;

					ClearNode(node);
				}
				//Если у "брата" есть только один красный потомок справа
				else if (node->parent->right->right != nullptr && node->parent->right->right->Red) {
					LeftRotate(root, node->parent->value);

					node->parent->Red = 0;
					node->parent->parent->Red = 1;
					node->parent->parent->right->Red = 0;

					ClearNode(node);
				}
				//Если у брата узла НЕТ красных потомков
				else {
					node->parent->right->Red = 1;
					node->parent->Red = 0;

					ClearNode(node);
				}
			}
		}
		//Если родитель узла - ЧЁРНЫЙ
		else {
			//Если узел - ПРАВЫЙ потомок
			if (node == node->parent->right) {
				//Если "брат" узла - КРАСНЫЙ
				if (node->parent->left->Red) {
					//Если у ПРАВОГО племянника вершины есть хотя бы один красный потомок*/
					if ((node->parent->left->right->left != nullptr && node->parent->left->right->left->Red) ||
						(node->parent->left->right->right != nullptr && node->parent->left->right->right->Red)) {
						LeftRotate(root, node->parent->left->value);
						RightRotate(root, node->parent->value);

						if (node->parent->parent->left->right != nullptr && node->parent->parent->left->right->Red)
							node->parent->parent->left->right->Red = 0;
						else
							node->parent->parent->left->Red = 0;

						ClearNode(node);
					}
					/*Если у племянника вершины нет красных потомков*/
					else {
						RightRotate(root, node->parent->value);
						node->parent->parent->Red = 0;
						node->parent->left->Red = 1;

						ClearNode(node);
					}
				}
				/*Если брат вершины - ЧЁРНЫЙ*/
				else {
					/*Если у брата есть ПРАВЫЙ КРАСНЫЙ потомок*/
					if (node->parent->left->right != nullptr && node->parent->left->right->Red) {
						LeftRotate(root, node->parent->left->value);
						RightRotate(root, node->parent->value);

						node->parent->parent->Red = 0;

						ClearNode(node);
					}
					/*Если у брата есть ЛЕВЫЙ КРАСНЫЙ потомок*/
					else if (node->parent->left->left != nullptr && node->parent->left->left->Red) {
						RightRotate(root, node->parent->value);

						node->parent->parent->left->Red = 0;

						ClearNode(node);
					}
					/*Если у брата нет красных потомоков*/
					else {
						node->parent->left->Red = 1;
						ClearNode(node);
					}
				}
			}
			/*Если узел - ЛЕВЫЙ потомок*/
			else {
				/*Если брат вершины - КРАСНЫЙ*/
				if (node->parent->right->Red) {
					/*Если у левого племянника вершины есть хотя бы один красный потомок*/
					if ((node->parent->right->left->right != nullptr && node->parent->right->left->right->Red) ||
						(node->parent->right->left->left != nullptr && node->parent->right->left->left->Red)) {
						RightRotate(root, node->parent->right->value);
						LeftRotate(root, node->parent->value);

						if (node->parent->parent->right->left != nullptr && node->parent->parent->right->left->Red)
							node->parent->parent->right->left->Red = 0;
						else
							node->parent->parent->right->Red = 0;

						ClearNode(node);
					}
					/*Если у племянника вершины нет красных потомков*/
					else {
						LeftRotate(root, node->parent->value);
						node->parent->parent->Red = 0;
						node->parent->right->Red = 1;

						ClearNode(node);
					}
				}
				/*Если брат вершины - ЧЁРНЫЙ*/
				else {
					/*Если у брата есть ЛЕВЫЙ КРАСНЫЙ потомок*/
					if (node->parent->right->left != nullptr && node->parent->right->left->Red) {
						RightRotate(root, node->parent->right->value);
						LeftRotate(root, node->parent->value);

						node->parent->parent->Red = 0;

						ClearNode(node);
					}
					/*Если у брата есть ПРАВЫЙ КРАСНЫЙ потомок*/
					else if (node->parent->right->right != nullptr && node->parent->right->right->Red) {
						RightRotate(root, node->parent->value);

						node->parent->parent->right->Red = 0;

						ClearNode(node);
					}
					/*Если у брата нет красных потомков*/
					else {
						node->parent->right->Red = 1;
						ClearNode(node);
					}
				}
			}
		}
	}
}

void ClearNode(Node* node) {
	if (node->parent != nullptr)
		if (node == node->parent->left)
			node->parent->left = nullptr;
		else
			node->parent->right = nullptr;

	delete node;
}

void Print(Node* root) {

	if (root == nullptr) return;

	Print(root->left);

	cout << "value: " << root->value << ", Color: " << (root->Red ? "RED" : "BLACK")
		<< ", Parent: " << (root->parent ? root->parent->value : 0) << endl;

	Print(root->right);
}

void LeftRotate(Node*& root, int value) { //Левый поворот

	Node* node = root;

	while (true) {
		if (node == nullptr) {
			cout << "Нет узла с таким ключом!";
			return;
		}
		else if (value < node->value)
			node = node->left;
		else if (value > node->value)
			node = node->right;
		else
			break;
	}

	Node* nodetmp = node->right; //устанавливаем y

	node->right = nodetmp->left; //левое поддерево y становится правым поддеревом x

	if (nodetmp->left != nullptr)
		nodetmp->left->parent = node;

	nodetmp->parent = node->parent; //Смена родителя Y

	if (node->parent == nullptr)    //Смена потомка у родителя узла
		root = nodetmp;
	else if (node == node->parent->left)
		node->parent->left = nodetmp;
	else
		node->parent->right = nodetmp;

	nodetmp->left = node; //Смена левого потомка Y

	node->parent = nodetmp;
}

void RightRotate(Node*& root, int value) {

	Node* node = root;

	while (true) {

		if (node == nullptr) {
			cout << "Нет узла с таким значением!";
			return;
		}
		else if (value < node->value)
			node = node->left;
		else if (value > node->value)
			node = node->right;
		else
			break;
	}

	Node* nodetmp = node->left; //устанавливаем Y

	node->left = nodetmp->right; //Правое поддерево Y становится левым поддеревом x

	if (nodetmp->right != nullptr)
		nodetmp->right->parent = node;

	nodetmp->parent = node->parent; //Смена родителя Y

	if (node->parent == nullptr)    //Смена потомка у родителя узла
		root = nodetmp;
	else if (node == node->parent->left)
		node->parent->left = nodetmp;
	else
		node->parent->right = nodetmp;

	nodetmp->right = node; //Смена левого потомка Y

	node->parent = nodetmp;
}

//Функция поиска вершины в заданном дереве, с заданным значением
Node* Find(Node* root, int value) {

	while (true) {
		if (root == nullptr) {
			cout << "Нет узла с таким значением!\n";
			return nullptr;
		}
		else if (value < root->value)
			root = root->left;
		else if (value > root->value)
			root = root->right;
		else
			return root;
	}
}
//Поиск узла с максимальным значением в дереве
int FindMax(Node* root) {
	while (root->right != nullptr)
		root = root->right;

	return root->value;
}

//Поиск узла с минимальным значением в дереве
int FindMin(Node* root) {
	while (root->left != nullptr)
		root = root->left;

	return root->value;
}

//Функция находит ближайшее большее и возвращает его значение
int FindNearestMax(Node* root, int value) {

	while (true) {
		if (root == nullptr) {
			cout << "Нет узла с таким значением!";
			return 0;
		}
		else if (value < root->value)
			root = root->left;
		else if (value > root->value)
			root = root->right;
		else
			break;
	}

	if (root->right != nullptr) {
		root = root->right;
		while (root->left != nullptr)
			root = root->left;
		return root->value;
	}
	else {
		cout << "Узел является максимальным";
		return value;
	}
}

//Функция находит ближайшее меньшее и возвращает его значение
int FindNearestMin(Node* root, int value) {

	while (true) {
		if (root == nullptr) {
			cout << "Нет узла с таким значением!";
			return 0;
		}
		else if (value < root->value)
			root = root->left;
		else if (value > root->value)
			root = root->right;
		else
			break;
	}

	if (root->left != nullptr) {
		root = root->left;
		while (root->right != nullptr)
			root = root->right;
		return root->value;
	}
	else {
		cout << "Узел является минимальным";
		return value;
	}
}