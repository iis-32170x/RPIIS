#include <iostream>
#pragma once

struct JungTable {

	struct cell {
		int val = -999;
		cell* nextCell = NULL;
	};

	struct tableRow {
		cell* row = NULL;
		tableRow* nextRow = NULL;
	};

	void Sort_p(cell** p) {
		cell* t = NULL, * t1, * r;
		if ((*p)->nextCell->nextCell == NULL) return;
		do {
			for (t1 = *p; t1->nextCell->nextCell != t; t1 = t1->nextCell)
				if (t1->nextCell->val > t1->nextCell->nextCell->val) {
					r = t1->nextCell->nextCell;
					t1->nextCell->nextCell = r->nextCell;
					r->nextCell = t1->nextCell;
					t1->nextCell = r;
				}
			t = t1->nextCell;
		} while ((*p)->nextCell->nextCell != t);
	}

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
		srand(static_cast<int>(time(NULL)));
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
				if (p->val != NULL) {
					std::cout << p->val << " ";
				}
				else {
					std::cout << "  ";
				}
				p = p->nextCell;
			}
			std::cout << std::endl;
			t = t->nextRow;
		}
	}

	void popCell(int row, int col, tableRow* r) {
		tableRow* t = r;
		int i = 1;
		while (i < row) {
			if (t->nextRow != NULL) {
				t = t->nextRow; 
				++i;
			}
			else {
				return;
			}
		}
		cell* p = t->row;
		cell* prev = NULL;
		cell* next = NULL;
		int k = 1;
		while (k < col) {
			if (p->nextCell) {
				p = p->nextCell;
				++k;
			}
			else {
				return;
			}
		}

		cell* n = r->row;
		while (n != p) {
			if (n->nextCell == p) {
				prev = n;
				if (n->nextCell->nextCell != NULL) {
					next = n->nextCell->nextCell;
				}
				break;
			}
			else {
				n = n->nextCell;
			}
		}

		prev->nextCell = next;
	}

	void popCell_new(tableRow* r, int row, int col) {
		tableRow* t = r;
		cell* prev = NULL;

		for (int i = 1; i < row; ++i) {
			if (!t->nextRow) {
				return;
			}
			else {
				t = t->nextRow;
			}
		}

		cell* p = t->row;
		for (int k = 1; k < col; ++k) {
			if (!p->nextCell) {
				return;
			}
			else {
				p = p->nextCell;
			}
		}

		popCell(row, col, r);
		tableRow* q = r;
		for (int i = row; i >= 1; --i) {
			if (i == 1) {
				break;
			}
			while (q) {
				if (q->nextRow == t) {
					t = q;
					break;
				}
				else {
					q = q->nextRow;
				}
			}
			cell* k = q->row;
			while (k) {
				if (k->nextCell) {
					if (k->val < p->val < k->nextCell->val) {
						std::swap(k->val, p->val);
						break;
					}
					else {
						k = k->nextCell;
					}
				}
				else if(k->nextCell == NULL){
					std::swap(k->val, p->val);
					break;
				}
			}
		}
	}

	int maximum(cell* p) {
		cell* t = p;
		while (t) {
			if (t->nextCell == NULL) {
				return t->val;
			}
			else {
				t = t->nextCell;
			}
		}
		return -1;
	}

	int lengthOfRow(tableRow* t) {
		cell* p = t->row;
		int size = 0;
		if (p) {
			++size;
		}
		else {
			return 0;
		}
		while (p) {
			p = p->nextCell;
			++size;
		}
		return size;
	}

	void addCell_New(tableRow* r, int val) {
		tableRow* t = r;
		if (val >= maximum(t->row)) {
			cell* p = t->row;
			while (p) {
				if (p->nextCell == NULL && lengthOfRow(t) < 5) {
					p->nextCell = addCell(p, val);
					break;
				}
				else if (p->nextCell == NULL && lengthOfRow(t) == 5) {
					std::swap(p->val,val);
					if (t->nextRow == NULL) {
						t->nextRow = addRow(t);
						t->nextRow->row = createCell(val, t->nextRow);
					}
					else {
						addCell_New(t->nextRow, val);
						break;
					}
				}
				else {
					p = p->nextCell;
				}
			}
		}
		else {
			cell* &p = t->row;
			while (p) {
				if (p->nextCell) {
					if (p->val < val < p->nextCell->val && lengthOfRow(t) < 5) {
						std::swap(p->val, val);
						if (t->nextRow == NULL) {
							t->nextRow = addRow(t);
							t->nextRow->row = createCell(p->nextCell->val, t->nextRow);
						}
						else {
							addCell_New(t->nextRow, p->nextCell->val);
							break;
						}
					}
					else if (p->val < val < p->nextCell->val && lengthOfRow(t) == 5) {
						if (t->nextRow == NULL) {
							t->nextRow = addRow(t);
							t->nextRow->row = createCell(p->nextCell->val, t->nextRow);
						}
						else {
							addCell_New(t->nextRow, p->nextCell->val);
							break;
						}
					}
					else {
						p = p->nextCell;
					}
				}
				else {
					std::swap(p->val,val);
					if (t->nextRow == NULL) {
						t->nextRow = addRow(t);
						t->nextRow->row = createCell(val, t->nextRow);
					}
					else {
						addCell_New(t->nextRow, val);
						break;
					}
					break;
				}
			}
		}
	}

	void deleteTable(tableRow* r) {
		tableRow* b = r;
		while (b) {
			cell* t = b->row;
			while (t) {
				cell* p = t;
				p = p->nextCell;
				delete t;
			}
			b = b->nextRow;
			delete b;
		}
	}
};
