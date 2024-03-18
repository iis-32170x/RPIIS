#include <iostream>
#include <iomanip>
using namespace std;

struct tree
{
	tree* left_child = NULL;
	tree* right_child = NULL;

	int l_border = 0;
	int r_border = 0;

	int max_value = 0;
	int modification = 0;

	int value = 0;
	int nomer = 0;
};

void create_tree(tree* node, int section[], int length_of_section, int l_limit, int numeral)
{
	int max = section[0], sum = 0;

	for (int i = 0; i < length_of_section; i++)
	{
		sum += section[i];
		if (section[i] > max)
		{
			max = section[i];
		}
	}

	node->nomer = numeral;
	node->value = sum;
	node->max_value = max;
	node->l_border = l_limit;
	node->r_border = l_limit + length_of_section - 1;

	if (length_of_section != 1)
	{
		int temp = log2(length_of_section);
		int razbienie;

		if (length_of_section != pow(2, temp))
		{
			razbienie = pow(2, temp);
		}
		else
		{
			razbienie = length_of_section / 2;
		}

		if (node->left_child == NULL)
		{
			int* tempmassiv = new int[razbienie];
			for (int i = 0; i < razbienie; i++)
			{
				tempmassiv[i] = section[i];
			}

			node->left_child = new tree;

			create_tree(node->left_child, tempmassiv, razbienie, l_limit, 2 * numeral);

			delete[] tempmassiv;
		}

		if (node->right_child == NULL)
		{
			int* tempmassiv2 = new int[length_of_section - razbienie];
			for (int i = razbienie; i < length_of_section; i++)
			{
				tempmassiv2[i - razbienie] = section[i];
			}

			node->right_child = new tree;

			create_tree(node->right_child, tempmassiv2, length_of_section - razbienie, l_limit + razbienie, 2 * numeral + 1);

			delete[] tempmassiv2;
		}
	}
}

void show_tree(tree* root, int length)
{
	if (!root)
	{
		cout << "Error!" << endl;
		exit(-1);
	}
	tree* buffroot = root;
	int logN = log2(length);
	int left_dir;
	int right_dir;
	int full_length;

	if (pow(2, logN) != length)
	{
		full_length = pow(2, int(log2(length)) + 1);
	}
	else
	{
		full_length = length;
	}

	int for_setw = 4 * full_length;

	for (int i = 1; i < full_length * 2; i++)
	{
		logN = int(log2(i));

		for (int k = logN; k > 0; k--)
		{
			if (buffroot != NULL)
			{
				left_dir = (buffroot->nomer) * pow(2, k);

				right_dir = (buffroot->nomer) * pow(2, k) + pow(2, k) - 1;


				if (i - left_dir > right_dir - i)
				{
					buffroot = buffroot->right_child;
				}
				if (i - left_dir < right_dir - i)
				{
					buffroot = buffroot->left_child;
				}
			}
		}


		if (pow(2, logN) == i)
		{
			for_setw = for_setw / 2;
			cout << endl;
			cout << setw(for_setw + full_length - 2 * pow(2, logN) / 3);
		}
		else
		{
			cout << setw(2 * for_setw);
		}

		if (buffroot != NULL)
		{
			cout << buffroot->modification << " ";
		}

		buffroot = root;
	}
}

void modify_tree(tree* node, int left_limit, int right_limit, int change)
{
	if (left_limit <= node->l_border && right_limit >= node->r_border)
	{
		node->modification += change;

	}
	else
	{
		if (node->left_child != NULL)
		{
			modify_tree(node->left_child, left_limit, right_limit, change);
		}

		if (node->right_child != NULL)
		{
			modify_tree(node->right_child, left_limit, right_limit, change);
		}
	}

	if ((node->right_child != NULL) && (node->left_child != NULL))
	{
		if (node->left_child->max_value + node->left_child->modification >= node->right_child->max_value + node->right_child->modification)
		{
			node->max_value = node->left_child->max_value + node->left_child->modification;
		}
		else
		{
			node->max_value = node->right_child->max_value + node->right_child->modification;
		}
	}
}

int find_max(tree* node, int left_limit, int right_limit, int sumadd)
{
	if (node->l_border == left_limit && node->r_border == right_limit)
	{
		return sumadd + node->max_value;
	}
	else
	{
		int res = -INFINITY;
		if (left_limit <= node->left_child->r_border)
		{
			res = max(find_max(node->left_child, left_limit, min(right_limit, node->left_child->r_border), sumadd + node->left_child->modification), res);
		}
		if (right_limit >= node->right_child->l_border)
		{
			res = max(find_max(node->right_child, max(left_limit, node->right_child->l_border), right_limit, sumadd + node->right_child->modification), res);
		}
		return res;
	}
}

void sum_tree(tree* node, int left_limit, int right_limit, int* sum)
{
	*sum += (node->modification) * (right_limit - left_limit + 1);

	if (node->left_child && (left_limit <= node->left_child->r_border))
	{
		sum_tree(node->left_child, left_limit, min(right_limit, node->left_child->r_border), sum);
	}
	if (node->right_child && (right_limit >= node->right_child->l_border))
	{
		sum_tree(node->right_child, max(left_limit, node->right_child->l_border), right_limit, sum);
	}
}

tree* delete_tree(tree* node)
{
	tree* temp_node_l = NULL, * temp_node_r = NULL;
	if (node->left_child != NULL && node->right_child != NULL)
	{
		temp_node_l = node->left_child;
		temp_node_r = node->right_child;
	}
	delete node;
	if (temp_node_l && temp_node_r)
	{
		delete_tree(temp_node_l);
		delete_tree(temp_node_r);
	}
	return NULL;
}

