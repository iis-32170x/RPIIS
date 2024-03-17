#include <iostream>
#include "library.hpp"

using namespace std;

void BTree_try_catch() {
	int m;
	cout << "Введите параметр m: ";
	cin >> m;

	try {
		if (m <= 1) {
			throw "Этот параметр не может быть использован, т.к. он меньше 2!!! ";
		}
		BTree a(m);
		PrettyPrint printer_1;
		srand(29324);
		cout << "\n \t----------ВСТАВКА----------\n";
		for (unsigned i = 0; i < 15; ++i)
		{
			int p = rand() % 100;
			cout << "\n## Вставка " << p << "...\n\n";
			a.insert_key(p);
			printer_1.print(a);
		}
		cout << "\n\n\t----------УДАЛЕНИЕ----------\n";
		cout << "Дерево после удаления 8: \n";
		a.delete_key(8);
		printer_1.print(a);
		cout << "\nДерево после удаления 26: \n";
		a.delete_key(26);
		printer_1.print(a);
		cout << "\n\n \t----------ПОИСК----------\n";
		(a.search_key(7)) ? cout << "Ключ 7 есть в дереве" : cout << "Ключ 7 не найден";
		cout << endl;
		cout << endl;
		(a.search_key(17)) ? cout << "Ключ 17 есть в дереве" : cout << "Ключ 17 не найден";
		cout << endl;
	}
	catch (const char* exception)
	{
		cerr << "Error: " << exception << '\n';
	}
}

void PrettyPrint::visit(BTreeNode const* node, unsigned level, unsigned child_index)
{
	if (level >= levels.size())
		levels.resize(level + 1);

	LevelInfo& level_info = levels[level];
	NodeInfo info;

	info.text_pos = 0;
	if (!level_info.empty())  
		info.text_pos = level_info.back().text_end + (child_index == 0 ? 2 : 1);

	info.text = node_text(node->keys, unsigned(node->n));

	if (node->leaf)
	{
		info.text_end = info.text_pos + unsigned(info.text.length());
	}
	else 
		 
	{
		for (unsigned i = 0, e = unsigned(node->n); i <= e; ++i)  
			visit(node->C[i], level + 1, i);

		info.text_end = levels[level + 1].back().text_end;
	}

	levels[level].push_back(info);
}

string PrettyPrint::node_text(int const keys[], unsigned key_count)
{
	ostringstream os;
	string sep = "";

	os << "[";
	for (unsigned i = 0; i < key_count; ++i) {
		os << sep << keys[i];
		sep = " ";
	}
	os << "]";

	return os.str();
}

void print_blanks(unsigned n)
{
	while (n--)
		cout << ' ';
}

void PrettyPrint::after_traversal()
{
	for (size_t l = 0, level_count = levels.size(); ; )
	{
		auto const& level = levels[l];
		unsigned prev_end = 0;

		for (auto const& node : level)
		{
			unsigned total = node.text_end - node.text_pos;
			unsigned slack = total - unsigned(node.text.length());
			unsigned blanks_before = node.text_pos - prev_end;

			print_blanks(blanks_before + slack / 2);
			cout << node.text;

			if (&node == &level.back())
				break;

			print_blanks(slack - slack / 2);

			prev_end += blanks_before + total;
		}

		if (++l == level_count)
			break;

		cout << "\n\n";
	}

	cout << "\n";
}

BTreeNode::BTreeNode(int t1, bool leaf1)
{
	t = t1;
	leaf = leaf1;

	keys = new int[2 * t - 1];
	C = new BTreeNode * [2 * t];

	n = 0;
}

int BTreeNode::findKey(int k)
{
	int idx = 0;
	while (idx < n && keys[idx] < k)
		++idx;
	return idx;
}

void BTreeNode::delete_key(int k)
{
	int idx = findKey(k);

	if (idx < n && keys[idx] == k)
	{

		if (leaf)
			delete_from_leaf(idx);
		else
			delete_from_nonleaf(idx);
	}
	else
	{

		if (leaf)
		{
			cout << "Ключа " << k << " нет в дереве!\n";
			return;
		}

		bool flag = ((idx == n) ? true : false);

		if (C[idx]->n < t)
			fill(idx);

		if (flag && idx > n)
			C[idx - 1]->delete_key(k);
		else
			C[idx]->delete_key(k);
	}
	return;
}

void BTreeNode::delete_from_leaf(int idx)
{

	for (int i = idx + 1; i < n; ++i)
		keys[i - 1] = keys[i];

	n--;

	return;
}

void BTreeNode::delete_from_nonleaf(int idx)
{

	int k = keys[idx];

	if (C[idx]->n >= t)
	{
		int pred = getPred(idx);
		keys[idx] = pred;
		C[idx]->delete_key(pred);
	}

	else if (C[idx + 1]->n >= t)
	{
		int succ = getSucc(idx);
		keys[idx] = succ;
		C[idx + 1]->delete_key(succ);
	}

	else
	{
		merge(idx);
		C[idx]->delete_key(k);
	}
	return;
}

int BTreeNode::getPred(int idx)
{
	BTreeNode* cur = C[idx];
	while (!cur->leaf)
		cur = cur->C[cur->n];

	return cur->keys[cur->n - 1];
}

int BTreeNode::getSucc(int idx)
{

	BTreeNode* cur = C[idx + 1];
	while (!cur->leaf)
		cur = cur->C[0];

	return cur->keys[0];
}

void BTreeNode::fill(int idx)
{

	if (idx != 0 && C[idx - 1]->n >= t)
		borrowFromPrev(idx);

	else if (idx != n && C[idx + 1]->n >= t)
		borrowFromNext(idx);

	else
	{
		if (idx != n)
			merge(idx);
		else
			merge(idx - 1);
	}
	return;
}

void BTreeNode::borrowFromPrev(int idx)
{

	BTreeNode* child = C[idx];
	BTreeNode* sibling = C[idx - 1];

	for (int i = child->n - 1; i >= 0; --i)
		child->keys[i + 1] = child->keys[i];

	if (!child->leaf)
	{
		for (int i = child->n; i >= 0; --i)
			child->C[i + 1] = child->C[i];
	}

	child->keys[0] = keys[idx - 1];

	if (!child->leaf)
		child->C[0] = sibling->C[sibling->n];

	keys[idx - 1] = sibling->keys[sibling->n - 1];

	child->n += 1;
	sibling->n -= 1;

	return;
}

void BTreeNode::borrowFromNext(int idx)
{

	BTreeNode* child = C[idx];
	BTreeNode* sibling = C[idx + 1];

	child->keys[(child->n)] = keys[idx];

	if (!(child->leaf))
		child->C[(child->n) + 1] = sibling->C[0];

	keys[idx] = sibling->keys[0];

	for (int i = 1; i < sibling->n; ++i)
		sibling->keys[i - 1] = sibling->keys[i];

	if (!sibling->leaf)
	{
		for (int i = 1; i <= sibling->n; ++i)
			sibling->C[i - 1] = sibling->C[i];
	}

	child->n += 1;
	sibling->n -= 1;

	return;
}
 
void BTreeNode::merge(int idx)
{
	BTreeNode* child = C[idx];
	BTreeNode* sibling = C[idx + 1];

	child->keys[t - 1] = keys[idx];

	for (int i = 0; i < sibling->n; ++i)
		child->keys[i + t] = sibling->keys[i];

	if (!child->leaf)
	{
		for (int i = 0; i <= sibling->n; ++i)
			child->C[i + t] = sibling->C[i];
	}

	for (int i = idx + 1; i < n; ++i)
		keys[i - 1] = keys[i];

	for (int i = idx + 2; i <= n; ++i)
		C[i - 1] = C[i];

	child->n += sibling->n + 1;
	n--;

	delete(sibling);
	return;
}

BTreeNode::~BTreeNode() 
{
	delete[] keys;
	delete[] C;
}


void BTree::insert_key(int k)
{
	if (root == NULL)
	{
		root = new BTreeNode(t, true);
		root->keys[0] = k; 
		root->n = 1; 
	}
	else 
	{
		if (root->n == 2 * t - 1)
		{
			BTreeNode* s = new BTreeNode(t, false);

			s->C[0] = root;

			s->splitChild(0, root);
 
			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->C[i]->insertNonFull(k);

			root = s;
		}
		else 
			root->insertNonFull(k);
	}
}

void BTreeNode::insertNonFull(int k)
{
	int i = n - 1;

	if (leaf == true)
	{

		while (i >= 0 && keys[i] > k)
		{
			keys[i + 1] = keys[i];
			i--;
		}

		keys[i + 1] = k;
		n = n + 1;
	}
	else 
	{
		while (i >= 0 && keys[i] > k)
			i--;

		if (C[i + 1]->n == 2 * t - 1)
		{
			splitChild(i + 1, C[i + 1]);

			if (keys[i + 1] < k)
				i++;
		}
		C[i + 1]->insertNonFull(k);
	}
}

void BTreeNode::splitChild(int i, BTreeNode* y)
{
	BTreeNode* z = new BTreeNode(y->t, y->leaf);
	z->n = t - 1;

	for (int j = 0; j < t - 1; j++)
		z->keys[j] = y->keys[j + t];

	if (y->leaf == false)
	{
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j + t];
	}

	y->n = t - 1;

	for (int j = n; j >= i + 1; j--)
		C[j + 1] = C[j];

	C[i + 1] = z;

	for (int j = n - 1; j >= i; j--)
		keys[j + 1] = keys[j];

	keys[i] = y->keys[t - 1];

	n = n + 1;
}

BTreeNode* BTreeNode::search_key(int k)
{
	int i = 0;
	while (i < n && k > keys[i])
		i++;

	if (keys[i] == k)
		return this;

	if (leaf == true)
		return NULL;

	return C[i]->search_key(k);
}

void BTree::delete_key(int k)
{
	if (!root)
	{
		cout << "Дерево пустое!\n";
		return;
	}

	root->delete_key(k);

	if (root->n == 0)
	{
		BTreeNode* tmp = root;
		if (root->leaf)
			root = NULL;
		else
			root = root->C[0];

		delete tmp;
	}
	return;
}

BTree:: ~BTree() 
{
	if (root != nullptr)
	{
		delete root;
		root = nullptr;
	}
}