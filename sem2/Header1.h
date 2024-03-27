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

	tableRow* JungTable_ = new tableRow;

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

	tableRow* createRow() {
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

	void viewTable() {
		tableRow* t = JungTable_;
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

		cell* n = t->row;
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

		if (prev) {
			prev->nextCell = next;
		}
		else {
			t->row = n->nextCell;
		}

		if (!t->row) {
			tableRow* s = JungTable_;
			tableRow* m = JungTable_;

			while (s != t) {
				if (s->nextRow == t) {
					break;
				}
				else {
					s = s->nextRow;
				}
			}

			while (m) {
				if (m->nextRow == t->nextRow) {
					m = m->nextRow;
					break;
				}
				else {
					m = m->nextRow;
				}
			}

			s->nextRow = m;
		}
	}

	void popCell_new(int row, int col) {
		tableRow* t = JungTable_;
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

		popCell(row, col, JungTable_);
		for (int i = row; i > 1; --i) {
			tableRow* q = JungTable_;
			int j = 1;
			while (j<i-1) {
				q = q->nextRow;
				++j;
			}
			cell* k = q->row;
			while (k) {
				if (k->nextCell) {
					if (k->val < p->val && p->val < k->nextCell->val) {
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
		int max = t->val;
		while (t->nextCell) {
			if (t->nextCell && t->nextCell->val > t->val) {
				max = t->nextCell->val;
				t = t->nextCell;
			}
			else if(t->nextCell) {
				t = t->nextCell;
			}
		}
		return max;
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
		while (p->nextCell) {
			p = p->nextCell;
			++size;
		}
		return size;
	}

	void addCell_New(int val, int row = 1, tableRow* r = NULL) {
		tableRow* m = JungTable_;
		if (JungTable_->nextRow == NULL && JungTable_->row == NULL) {
			JungTable_->row = createCell(val, JungTable_);
		}
		else {
			tableRow* t = m;
			int i = 1;
			while (i < row) {
				if (t->nextRow) {
					t = t->nextRow;
					++i;
				}
				else {
					break;
				}
			}

			int k = 1;
			int prev = 0;
			tableRow* s = m;
			while (k < row - 1) {
				s = s->nextRow;
				++k;
			}
			if (row - 1 <= 0) {
				prev = 9999;
			}
			else {
				prev = lengthOfRow(s);
			}

			if (val >= maximum(t->row)) {
				cell* p = t->row;
				while (p) {
					if (p->nextCell == NULL && lengthOfRow(t) < prev) {
						p->nextCell = addCell(p, val);
						break;
					}
					else if (p->nextCell == NULL && lengthOfRow(t) == prev) {
						if (t->nextRow == NULL) {
							t->nextRow = addRow(t);
							t->nextRow->row = createCell(val, t->nextRow);
							break;
						}
						else {
							addCell_New(val, row + 1,JungTable_);
							break;
						}
					}
					else {
						p = p->nextCell;
					}
				}
			}
			else {
				cell* p = t->row;
				while (p) {
					if (p->nextCell == NULL) {
						int temp = p->val;
						p->val = val;
						if (t->nextRow == NULL) {
							t->nextRow = addRow(t);
							t->nextRow->row = createCell(temp, t->nextRow);
							break;
						}
						else {
							addCell_New(temp, row + 1, JungTable_);
							break;
						}
					}
					if (p->val == val) {
						break;
					}
					if (p->nextCell && p->val < val && val < p->nextCell->val) {
						int temp = p->nextCell->val;
						p->nextCell->val = val;
						if (t->nextRow == NULL) {
							t->nextRow = addRow(t);
							t->nextRow->row = createCell(temp, t->nextRow);
							break;
						}
						else {
							addCell_New(temp, row + 1, JungTable_);
							break;
						}
					}
					else {
						p = p->nextCell;
					}
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
