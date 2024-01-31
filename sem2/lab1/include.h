#include <iostream>

using namespace std;

struct node
{
	int info; 
	node* left; 
	node* right; 
	int balance; 
};


int Height(node* root) 
{
	if (root == NULL)
		return 0; 
	else {
		int hLeft = Height(root->left),
			hRight = Height(root->right); 
		if (hLeft > hRight) 
			return hLeft + 1;
		else
			return hRight + 1; 
	}
}

void SetBalance(node* (&root)) 
{
	if (root != NULL)
		root->balance = Height(root->right) - Height(root->left);
}

void TurnLeft(node* (&root))
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

void TurnRight(node* (&root)) 
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

void insert(node* (&root), int d) 
{
	if (root == NULL) 
	{ 
		root = new node;
		root->info = d;
		root->balance = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else 
	{
		if (d > root->info) 
		{
			insert(root->right, d); 
			if (Height(root->right) - Height(root->left) > 1) 
			{
				if (Height(root->right->right) < Height(root->right->left)) 
					TurnRight(root->right); 
				TurnLeft(root); 
			}
		}
		else
			if (d < root->info)
			{
				insert(root->left, d); 
				if (Height(root->left) - Height(root->right) > 1) 
				{
					if (Height(root->left->left) < Height(root->left->right)) 
						TurnLeft(root->left); 
					TurnRight(root);
				}
			}
		SetBalance(root); 
	}
}

void output(node* p)  
{
	if (p != NULL)
	{
		output(p->left);
		cout << p->info << " ";
		output(p->right);
	}
}

void print_n(const node* p, int n, int level, int prob) 
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

void print(node* p) 
{
	int h = Height(p);
	int prob = 3;
	if (p)
	{
		for (int i = 0; i <= h; i++) 
		{
			print_n(p, i, 0, prob * (h - i));
			cout << endl;
		}
	}
}

void clear(node** p) // 
{
	if ((*p) != NULL) {
		clear(&(*p)->left);
		clear(&(*p)->right);

		delete* p;
		*p = NULL;
	}
}

node* minValueNode(node* root)  
{
	node* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
node* maxValueNode(node* root)
{
	node* current = root;
	while (current->right != NULL) {
		current = current->right;
	}
	return current;
}

node* deleteNode(node* root, int key) 
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

node* findClosestMin(node* root, int value)
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

node* findClosestMax(node* root, int value) 
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

node* search(node* root, int value) 
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
