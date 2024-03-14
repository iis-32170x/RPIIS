#include <iostream>
#pragma once

struct JungTable {

	struct cell {
		int val;
		cell* nextCell;
	};

	struct tableRow {
		cell* row;
		tableRow* nextRow;
	};

	tableRow* createTable() {
		tableRow* t = new tableRow;
		return t;
	}

	tableRow* addRow(tableRow* r) {
		tableRow* t = new tableRow;
		r->nextRow = t;
		return t;
	}

	cell* createCell(int val, tableRow* r) {
		cell* t = new cell;
		r->row = t;
		t->val = val;
		return t;
	}

	cell* addCell(cell* c, int val) {
		cell* t = new cell;
		c->nextCell = t;
		t->val = val;
		return t;
	}

	cell* createCellWithoutValue(tableRow* r) {
		cell* t = new cell;
		r->row = t;
		return t;
	}

	cell* addCellWithoutValue(cell* c) {
		cell* t = new cell;
		c->nextCell = t;
		return t;
	}

	void viewTable(tableRow* r) {
		tableRow* t = r;
		while (t != NULL) {
			cell* p = t->row;
			while (p != NULL) {
				cell* b = p;
				if (b->val != NULL) {
					std::cout << b->val << " ";
				}
				else {
					std::cout << "  ";
				}
				b = b->nextCell;
			}
			std::cout << std::endl;
			t = t->nextRow;
		}
	}

	void deleteTable(tableRow* r) {
		tableRow* b = r;
		while (b != NULL) {
			cell* t = b->row;
			while (t != NULL) {
				cell* p = t;
				p = p->nextCell;
				delete t;
			}
			b = b->nextRow;
			delete r;
		}
	}
};