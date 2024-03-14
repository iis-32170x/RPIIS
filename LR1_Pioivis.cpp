﻿#include "Header1.h"

using namespace std;

bool isCreated() {
	int count = 0;
	JungTable s;
	JungTable::tableRow* t;
	t = s.createTable();
	if (t != NULL) {
		++count;
	}
	return count;
}

bool isAdded_r() {
	JungTable::tableRow* r = new JungTable::tableRow;
	int count = 0;
	JungTable s;
	JungTable::tableRow* t;
	t = s.addRow(r);
	if (r->nextRow != NULL) {
		++count;
	}
	return count;
}

bool isCreated_c() {
	int count = 0;
	JungTable s;
	int array[5] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; ++i) {
		JungTable::tableRow* t;
		t = s.createTable();
		t->row = s.createCell(array[i], t);
		if (t->row->val == array[i]) {
			++count;
		}
	}
	return count;
}

bool isCreated_c_w() {
	int count = 0;
	JungTable s;
	for (int i = 0; i < 5; ++i) {
		JungTable::tableRow* t = new JungTable::tableRow;
		t = s.createTable();
		t->row = s.createCellWithoutValue(t);
		if (t->row != NULL) {
			++count;
		}
	}
	return count;
}

bool isAdded_c() {
	int count = 0;
	JungTable s;
	int array[5] = { 1, 2, 3, 4, 5 };
	JungTable::tableRow* t;
	t = s.createTable();
	t->row = s.createCell(array[0], t);
	for (int i = 1; i < 5; ++i) {
		s.addCell(t->row, array[i]);
		if (t->row->nextCell->val == array[i]) {
			++count;
		}
	}
	return count;
}

bool isAdded_c_w() {
	int count = 0;
	JungTable s;
	JungTable::tableRow* t = new JungTable::tableRow;
	for (int i = 0; i < 5; ++i) {
		t->row = s.createCellWithoutValue(t);
		t->row->nextCell = s.addCellWithoutValue(t->row);
		if (t->row->nextCell != NULL) {
			++count;
		}
	}
	return count;
}

int main() {
	cout << "isCreated: " << std::boolalpha << isCreated() << endl;
	cout << "isCreastedCell: " << isCreated_c() << endl;
	cout << "isAdded_row: " << isAdded_r() << endl;
	cout << "isCreated_cell_withoutValue: " <<isCreated_c_w() << endl;
	cout << "isAdded_cell: " << isAdded_c() << endl;
	cout << "isAdded_cell_withoutValue: " << isAdded_c_w() << endl;
}