#include "RMQ_tree.h"
#include <ctime>

int main()
{
	srand(time(NULL));

	tree* root = new tree;

	int amount_of_leaves, swit4 = 1, left_lim, right_lim, modif;

	int for_max_n_sum, * ptr_sum = &for_max_n_sum;

	cout << "Input amount of leaves: ";

	do
	{
		cin >> amount_of_leaves;
	} while (amount_of_leaves < 1);

	int* leaves = new int[amount_of_leaves];

	for (int i = 0; i < amount_of_leaves; i++)
	{
		leaves[i] = /*rand() % 41 - 2*/0;
	}

	create_tree(root, leaves, amount_of_leaves, 0, 1);

	show_tree(root, amount_of_leaves);

	while (swit4)
	{
		cout << endl << endl << "1) Modify tree - 1\n2) Find max - 2\n3) Find sum - 3" << endl;

		do
		{
			cin >> swit4;
		} while (swit4 < 0 || swit4 > 3);

		cout << endl;

		switch (swit4)
		{
		case(1):
		{
			cout << "Define the section, where max value will be changed: [a, b] ([1, " << amount_of_leaves << "])" << endl;

			cout << "a: ";
			do
			{
				cin >> left_lim;
			} while (left_lim < 1 || left_lim > amount_of_leaves);

			cout << "b: ";
			do
			{
				cin >> right_lim;
			} while (right_lim < left_lim || right_lim > amount_of_leaves);

			cout << "Input modification: ";
			cin >> modif;

			modify_tree(root, left_lim - 1, right_lim - 1, modif);
			show_tree(root, amount_of_leaves);

			break;
		}

		case(2):
		{

			cout << "Define the section, where max value will be found: [a, b] ([1, " << amount_of_leaves << "])" << endl;

			cout << "a: ";
			do
			{
				cin >> left_lim;
			} while (left_lim < 1 || left_lim > amount_of_leaves);

			cout << "b: ";
			do
			{
				cin >> right_lim;
			} while (right_lim < left_lim || right_lim > amount_of_leaves);

			for_max_n_sum = find_max(root, left_lim - 1, right_lim - 1, root->modification);

			cout << "Max value on [" << left_lim << ", " << right_lim << "]: " << for_max_n_sum << endl;

			break;
		}
		case(3):
		{
			for_max_n_sum = 0;

			cout << "Define the section, where sum will be found: [a, b] ([1, " << amount_of_leaves << "])" << endl;

			cout << "a: ";
			do
			{
				cin >> left_lim;
			} while (left_lim < 1 || left_lim > amount_of_leaves);

			cout << "b: ";
			do
			{
				cin >> right_lim;
			} while (right_lim < left_lim || right_lim > amount_of_leaves);

			sum_tree(root, left_lim - 1, right_lim - 1, ptr_sum);

			cout << "Sum on [" << left_lim << ", " << right_lim << "]: " << for_max_n_sum << endl;

			break;
		}
		}
	}

	root = delete_tree(root);
	show_tree(root, amount_of_leaves);
}