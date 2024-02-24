#include "../lab/tree.h"

int main() 
{
	treenode* root = buildTreeFromInput();
	printTree(root);
	cout << "vvedite element to add into tree: ";
		cout << endl;
	int add;
	cin >> add;
	addchild(root, add);
	printTree(root);
	deleteTree(root);
}
