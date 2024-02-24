#include "../lab/tree.h"
using namespace std;
int main() {
	treenode* root = buildTreeFromInput();
	printTree(root);
	cout << "vvedite element to delete from tree: ";
	cout << endl;
	int todelete;
	cin >> todelete;
		root = deletenode(root, todelete);
	printTree(root);
	deleteTree(root);
} 
