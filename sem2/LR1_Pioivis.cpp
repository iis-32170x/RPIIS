#include "Header1.h"

using namespace std;

bool isCreated() {
	int count = 0;
	JungTable s;
	JungTable::tableRow* t;
	t = s.createRow();
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
		t = s.createRow();
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
		t = s.createRow();
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
	int array[5] = { 1, 3, 8, 4, 5 };
	JungTable::tableRow* t;
	t = s.createRow();	
	t->row = s.createCell(array[0], t);
	JungTable::cell* p = t->row;
	for (int i = 1; i < 5; ++i) {
		p->nextCell = s.addCell(p, array[i]);
		if (t->row->nextCell->val == array[i]) {
			++count;
		}
		p = p->nextCell;
	}
	s.Sort_p(&t->row);

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

bool popped_and_filled() {
	JungTable s;
	JungTable::tableRow* t = new JungTable::tableRow;
	int arr[6] = { 2, 4, 3, 5, 9, 8};
	s.addCell_New(t, 1); // сначала неважно, что затолкать в третий аргумент, да и вообще его деволтным в единицу переделал
	for (int i = 0; i < 6; ++i) {
		s.addCell_New(t, arr[i]);
	}
	s.viewTable(t);
	s.popCell_new(t, 1, 2);
	s.viewTable(t);

	return true;
}

int main() {
	cout << "isCreated: " << std::boolalpha << isCreated() << endl;
	cout << "isCreastedCell: " << isCreated_c() << endl;
	cout << "isAdded_row: " << isAdded_r() << endl;
	cout << "isCreated_cell_withoutValue: " <<isCreated_c_w() << endl;
	cout << "isAdded_cell_and_Sorted: " << isAdded_c() << endl;
	cout << "isAdded_cell_withoutValue: " << isAdded_c_w() << endl;
	cout << "popped_and_filled: " << popped_and_filled() << endl;
	return 0;
}
