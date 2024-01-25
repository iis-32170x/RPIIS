#include <iostream>
#include "SegmentTree.h"


using namespace std;
using namespace Algorithm;

int main()
{
	setlocale(LC_ALL, "russian");
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 0 };
	SegmentTree segmentTree(arr);

	cout << segmentTree;

	int i, left, right, update_index, value;
	cout << "Введите индекс элемента исходного массива, который хотите заменить: ";
	cin >> update_index;

	cout << "Введите значение, на которое хотите заменить предыдущее: ";
	cin >> value;
	segmentTree.update_tree(update_index, value);
	
	cout << segmentTree;

	cout << "Введите левый диапазон исходного массива, на котором будет искаться наименьший элемент: ";
	cin >> left;

	cout << "Введите правый диапазон исходного массива, на котором будет искаться наименьший элемент: ";
	cin >> right;

	cout << '\n';

	cout << "Минимальный элемент на диапазоне [" << left << ", " << right << "] = " << segmentTree.smallest_on_range(left, right) << '\n';;

	cout << segmentTree;
}
