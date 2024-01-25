#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace Algorithm {
	class SegmentTree
	{
	protected:
		vector<int> arr;
		vector<int> tree;

		void update() {
			int n = arr.size();

			for (int i = 0; i < n; i++) tree[i + n] = arr[i];
			for (int i = n - 1; i > 0; i--) tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
		}

		void update(int index, int value) {
			int n = arr.size();
			tree[index + n] = value;
			for (index += n; index > 1; index /= 2)
				tree[index / 2] = min(tree[index], tree[index ^ 1]);
		}

	public:
		SegmentTree()
		{
			this->arr = vector<int>(0);
			this->tree = vector<int>(0);
		}
		
		SegmentTree(vector<int> value) {
			this->arr = value;
			this->tree = vector<int>(value.size() * 2, 0);
			update();
		}

		vector<int> getArray() {
			return this->arr;
		}

		vector<int> getTree() {
			return this->tree;
		}

		void setArray(vector<int> value) {
			this->arr = value;
			update();
		}

		void update_tree(int update_index, int value) {
			this->arr[update_index] = value;
			update(update_index, value);
		}

		int smallest_on_range(int left_input, int right_input){
			int n = arr.size();

			int left = left_input + n;
			int right = right_input + n;

			int res = tree[right];

			while (left <= right) {
				cout << "left index = " << left << ", value = " << tree[left] << '\n';
				cout << "right index = " << right << ", value = " << tree[right] << '\n';

				if (left % 2 == 1) res = min(res, tree[left++]);
				if (right % 2 == 0) res = min(res, tree[right--]);

				left /= 2; 
				right /= 2;
			}
			return res;
		}
	};

	ostream& operator << (ostream& os, SegmentTree& tree) {
		vector<int> treeArray = tree.getArray();
		vector<int> treeTree = tree.getTree();

		os << "Исходный массив: ";
		for (int i = 0; i < treeArray.size(); i++) {
			os << treeArray[i] << ' ';
		}
		cout << '\n';

		os << "Полученное дерево: ";
		for (int i = 1; i < treeTree.size(); i++) {
			os << treeTree[i] << ' ';
		}
		cout << "\n\n";

		return os;
	}
}

