#include "rbtree.h"

using namespace std;

void insertNode(Node*& root, int key) {

	Node* nodetmp = root;

	while (true) {							//Поиск места для вставки нового узла на основе его ключа
		if (key < nodetmp->key) {		
			
			if (nodetmp -> left == nullptr) {
				nodetmp->left = new Node{ key, nodetmp, nullptr, nullptr, 1 };
				insert_fix(nodetmp->left, root);
				return;
			}
			nodetmp = nodetmp->left;
		}

		else if (key > nodetmp->key) {

			if (nodetmp -> right == nullptr) {
				nodetmp->right = new Node{ key, nodetmp, nullptr, nullptr, 1 };
				insert_fix(nodetmp->right, root);
				return;
			}
			nodetmp = nodetmp->right;
		}
		else {
			cout << "Узел с таким ключом уже существует!";
			return;
		}
	}
}

void insert_fix(Node* node, Node*& root) {
		while (node->parent->IsRed) {
			//Цикл выполняется и поднимается вверх по дереву пока родитель узла остаётся красным или его не станет :(

			/*Дальнейшее выполнение программы зависит от расположения отца узла по отношению к дедушке узла*/

			/*Если отец - ЛЕВЫЙ потомок*/
			if (node->parent == node->parent->parent->left) {	 
																	
				/*Чтобы не вызывать из nullptr значения (ибо это приводит к ошибке) проверяем существует ли дядя у нашего узла */
				if (node->parent->parent->right != nullptr) {

					/*Если дядя сущесвует, то проверяем: красный ли он?*/
					if (node->parent->parent->right->IsRed) {

						/*Если дядя красный, то достаточно просто перекрасить некоторые вершины*/
						node->parent->IsRed = 0;
						node->parent->parent->right->IsRed = 0;
						node->parent->parent->IsRed = 1;

						node = node->parent->parent;
					}
					else
						/*Если дядя чёрный, необходимо выполнить поворот или даже два
						(дядя становится неважным если он не красный)*/
						goto p1;
				}
				else {
				p1:
					/*Если узел находится СПРАВА от отца то выполняется поворот,
					чтобы привести это поддерево к "базоваму случаю"*/
					if (node == node->parent->right) {
						left_rotate(root, node->parent->key);
						node = node->left;
					}

					/*"Базовый случай"*/
					right_rotate(root, node->parent->parent->key);

					node->parent->right->IsRed = 1;
					node->parent->IsRed = 0;

					node = node->parent;
				}
			}

			/*Если отец - ПРАВЫЙ потомок*/
			else {

				/*Чтобы не вызывать из nullptr значения (ибо это приводит к ошибке) проверяем существует ли дядя у нашего узла */
				if (node->parent->parent->left != nullptr) {

					/*Если дядя сущесвует, то проверяем: красный ли он?*/
					if (node->parent->parent->left->IsRed) {

						/*Если дядя красный, то достаточно просто перекрасить некоторые вершины*/
						node->parent->IsRed = 0;

						node->parent->parent->left->IsRed = 0;

						node->parent->parent->IsRed = 1;

						node = node->parent->parent;
					}
					else 
						/*Если дядя чёрный, необходимо выполнить поворот или даже два
						(дядя становится неважным если он не красный)*/
						goto p2;
				}
				else {

					p2:
					/*Если узел находится СЛЕВА от отца то выполняется поворот,
					чтобы привести это поддерево к "базоваму случаю"*/
					if (node == node->parent->left) {
						right_rotate(root, node->parent->key);
						node = node->right;
					}

					/*"Базовый случай"*/
					left_rotate(root, node->parent->parent->key);

					node->parent->left->IsRed = 1;
					node->parent->IsRed = 0;

					node = node->parent;
				}

			}
			/*Обеспечиваем выполнение условия о чёрном узле, оставляем его чёрным в любом случае*/
			root->IsRed = 0;

			/*Снова чтобы не вызвать ошибку о чтении данных из nullptr, прерываем цикл если его значание станет таковым*/
			if (node->parent == nullptr)
				break;
		}
}

void deleteNode(Node*& root, int key) {
	Node* node = root;

	while (node != nullptr)
		if (key < node->key)
			node = node->left;
		else if (key > node->key)
			node = node->right;
		else
			break;

	if (node == nullptr) {
		cout << "Нет вершины с таким ключом!";
		return;
	}

	del(root, node);
}

void del(Node*& root, Node*node) {

	/*Удаление красной вершины без потомков*/
	if (node->IsRed && node->left == nullptr && node->right == nullptr) {
		clearNode(node);
	}
	/*Удаление вершины с правым потомком*/
	else if (node -> right != nullptr) {
		Node* nodetmp = node->right;

		while (nodetmp->left != nullptr)
			nodetmp = nodetmp->left;

			int tmp = nodetmp->key;
			nodetmp->key = node->key;
			node->key = tmp;

			del(root, nodetmp);
	}
	/*Удаление вершины с левым потомком*/
	else if (node->left != nullptr) {
		Node* nodetmp = node->left;

		while (nodetmp->right != nullptr)
			nodetmp = nodetmp->right;

		int tmp = nodetmp->key;
		nodetmp->key = node->key;
		node->key = tmp;

		del(root, nodetmp);
	}

	/*Удаление чёрной вершины без потомков*/
	else if (!node->IsRed && node->left == nullptr && node->right == nullptr) {

		/*Если родитель вершины - КРАСНЫЙ*/
		if (node->parent->IsRed) {
			/*Если узел - ПРАВЫЙ потомок*/
			if (node == node->parent->right) {
				/*Если у брата есть хотя бы один КРАСНЫЙ потомок слева или справа*/
				if (node->parent->left->right != nullptr && node->parent->left->right->IsRed) {
					left_rotate(root, node->parent->left->key);
					right_rotate(root, node->parent->key);

					node->parent->IsRed = 0;

					clearNode(node);
				}
				else if (node->parent->left->left != nullptr && node->parent->left->left->IsRed) {
					right_rotate(root, node->parent->key);

					node->parent->IsRed = 0;
					node->parent->parent->IsRed = 1;
					node->parent->parent->left->IsRed = 0;

					clearNode(node);
				}
				/*Если у брата узла НЕТ красных потомков*/
				else {
					node->parent->left->IsRed = 1;
					node->parent->IsRed = 0;

					clearNode(node);
				}
			}
			/*Если узел - ЛЕВЫЙ потомок*/
			else {
				/*Если у брата есть хотя бы один красный потомок слева или справа*/
				if (node->parent->right->left != nullptr && node->parent->right->left->IsRed) {
					right_rotate(root, node->parent->right->key);
					left_rotate(root, node->parent->key);

					node->parent->IsRed = 0;

					clearNode(node);
				}
				/*Если у брата есть только один красный потомок справа*/
				else if (node->parent->right->right != nullptr && node->parent->right->right->IsRed) {
					left_rotate(root, node->parent->key);

					node->parent->IsRed = 0;
					node->parent->parent->IsRed = 1;
					node->parent->parent->right->IsRed = 0;

					clearNode(node);
				}
				/*Если у брата узла НЕТ красных потомков*/
				else {
					node->parent->right->IsRed = 1;
					node->parent->IsRed = 0;

					clearNode(node);
				}
			}
		}
		/*Если родитель вершины - ЧЁРНЫЙ*/
		else {
			/*Если узел - ПРАВЫЙ потомок*/
			if (node == node->parent->right) {
				/*Если брат вершины - КРАСНЫЙ*/
				if (node->parent->left->IsRed) {
					/*Если у ПРАВОГО племянника вершины есть хотя бы один красный потомок*/
					if ((node->parent->left->right->left != nullptr && node->parent->left->right->left->IsRed) ||
						(node->parent->left->right->right != nullptr && node->parent->left->right->right->IsRed)) {
						left_rotate(root, node->parent->left->key);
						right_rotate(root, node->parent->key);

						if (node->parent->parent->left->right != nullptr && node->parent->parent->left->right->IsRed)
							node->parent->parent->left->right->IsRed = 0;
						else
							node->parent->parent->left->IsRed = 0;

						clearNode(node);
					}
					/*Если у племянника вершины нет красных потомков*/
					else {
						right_rotate(root, node->parent->key);
						node->parent->parent->IsRed = 0;
						node->parent->left->IsRed = 1;

						clearNode(node);
					}
				}
				/*Если брат вершины - ЧЁРНЫЙ*/
				else{
					/*Если у брата есть ПРАВЫЙ КРАСНЫЙ потомок*/
					if (node->parent->left->right != nullptr && node->parent->left->right->IsRed) {
						left_rotate(root, node->parent->left->key);
						right_rotate(root, node->parent->key);

						node->parent->parent->IsRed = 0;

						clearNode(node);
					}
					/*Если у брата есть ЛЕВЫЙ КРАСНЫЙ потомок*/
					else if (node->parent->left->left != nullptr && node->parent->left->left->IsRed) {
						right_rotate(root, node->parent->key);

						node->parent->parent->left->IsRed = 0;

						clearNode(node);
					}
					/*Если у брата нет красных потомоков*/
					else {
						node->parent->left->IsRed = 1;
						clearNode(node);
					}
				}
			}
			/*Если узел - ЛЕВЫЙ потомок*/
			else {
				/*Если брат вершины - КРАСНЫЙ*/
				if (node->parent->right->IsRed) {
					/*Если у левого племянника вершины есть хотя бы один красный потомок*/
					if ((node->parent->right->left->right != nullptr && node->parent->right->left->right->IsRed) ||
						(node->parent->right->left->left != nullptr && node->parent->right->left->left->IsRed)) {
						right_rotate(root, node->parent->right->key);
						left_rotate(root, node->parent->key);

						if (node->parent->parent->right->left != nullptr && node->parent->parent->right->left->IsRed)
							node->parent->parent->right->left->IsRed = 0;
						else
							node->parent->parent->right->IsRed = 0;

						clearNode(node);
					}
					/*Если у племянника вершины нет красных потомков*/
					else {
						left_rotate(root, node->parent->key);
						node->parent->parent->IsRed = 0;
						node->parent->right->IsRed = 1;

						clearNode(node);
					}
				}
				/*Если брат вершины - ЧЁРНЫЙ*/
				else {		
					/*Если у брата есть ЛЕВЫЙ КРАСНЫЙ потомок*/
					if (node->parent->right->left != nullptr && node->parent->right->left->IsRed) {
						right_rotate(root, node->parent->right->key);
						left_rotate(root, node->parent->key);

						node->parent->parent->IsRed = 0;

						clearNode(node);
					}
					/*Если у брата есть ПРАВЫЙ КРАСНЫЙ потомок*/
					else if (node->parent->right->right != nullptr && node->parent->right->right->IsRed) {
						right_rotate(root, node->parent->key);

						node->parent->parent->right->IsRed = 0;

						clearNode(node);
					}
					/*Если у брата нет красных потомков*/
					else {
						node->parent->right->IsRed = 1;
						clearNode(node);
					}
				}
			}
		}
	}
}

void clearNode(Node* node) {
	if (node->parent != nullptr)
		if (node == node->parent->left)
			node->parent->left = nullptr;
		else
			node->parent->right = nullptr;

	delete node;	
}

void printInorder(Node* root) {
	
	if (root == nullptr) return;

	printInorder(root->left);

	cout << "Key: " << root->key << ", Color: " << (root->IsRed ? "RED" : "BLACK")
		 << ", Parent: " << (root -> parent ? root -> parent -> key : 0) << endl;

	printInorder(root->right);
}

void left_rotate(Node*& root,int key) { //Левый поворот

	Node* node = root;

	while (true) {

		if (node == nullptr) {
			cout << "Нет узла с таким ключом!";
			return;
		}

		else if (key < node->key)
			node = node->left;

		else if (key > node->key)
			node = node->right;

		else
			break;
	}

	Node* nodetmp = node->right; //устанавливаем y

	node->right = nodetmp->left; //левое поддерево y становится правым поддеревом x

	if (nodetmp->left != nullptr)
		nodetmp->left->parent = node;

	nodetmp->parent = node->parent; //Смена родителя Y

	if (node -> parent == nullptr)    //Смена потомка у родителя узла
		root = nodetmp;
	else if (node == node->parent->left)
		node->parent->left = nodetmp;
	else
		node->parent->right = nodetmp;

	nodetmp->left = node; //Смена левого потомка Y

	node->parent = nodetmp;
}

void right_rotate(Node*& root, int key) {

	Node* node = root;

	while (true) {

		if (node == nullptr) {
			cout << "Нет узла с таким ключом!";
			return;
		}
		else if (key < node->key)
			node = node->left;
		else if (key > node->key)
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

/*Функция поиска вершины в заданном дереве, с заданным ключом*/
Node* find(Node* root, int key) {

	while (true) {
		if (root == nullptr) {
			cout << "Нет узла с таким ключом!\n";
			return nullptr;
		}
		else if (key < root->key)
			root = root->left;
		else if (key > root->key)
			root = root->right;
		else
			return root;
	}
}
/*Поиск узла с максимальным ключом в дереве*/
int find_max(Node* root) {
	while (root -> right != nullptr)
		root = root->right;
	
	return root->key;
}

/*Поиск узла с минимальным ключом в дереве*/
int find_min(Node* root) {
	while (root -> left != nullptr)
		root = root->left;

	return root->key;
}
/*Функция находит ближайшее большее и возвращает его ключ*/
int find_nearest_max(Node* root,int key) {

	while (true) {
		if (root == nullptr) {
			cout << "Нет узла с таким ключом!";
			return 0;
		}
		else if (key < root->key)
			root = root->left;
		else if (key > root->key)
			root = root->right;
		else
			break;
	}

	if (root->right != nullptr) {
		root = root->right;
		while (root->left != nullptr)
			root = root->left;
		return root->key;
	}
	else {
		cout << "Узел является максимальным";
		return key;
	}
}
/*Функция находит ближайшее меньшее и возвращает его ключ*/
int find_nearest_min(Node* root, int key) {

	while (true) {
		if (root == nullptr) {
			cout << "Нет узла с таким ключом!";
			return 0;
		}
		else if (key < root->key)
			root = root->left;
		else if (key > root->key)
			root = root->right;
		else
			break;
	}

	if (root->left != nullptr) {
		root = root->left;
		while (root->right != nullptr)
			root = root->right;
		return root->key;
	}
	else {
		cout << "Узел является минимальным";
		return key;
	}
}