#include "include.h"

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
		cout << "Node with index " << valueToSearch << " found." << endl;
	}
	else {
		cout << "Node with index " << valueToSearch << " didn't find." << endl;
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



