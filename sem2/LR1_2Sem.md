# Лабораторная работа 1, 2 семестр, 12 вариант

## Цель работы

  Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных.

## Задача

  Создать таблицу Юнга и реализовать следующий функционал:

- Добавление элемента в стек
- Извлечение элемента из стека

## Реализация

## Header1.h

  Нужно создать стек стеков, но пользователь может в ячейки не вставлять значения. Для централизации методов и структур все помещено в структуру `JungTable`,
`tableRow` является структурой для создания строки таблицы, `сell` является ячейкой строки.

  Метод `createTable` используется для создания первой строки таблицы. `addRow` метод нужен для добавления строки в таблицу. `createCell` метод нужен для создания ячейки в строке.
По аналогии с `addRow` был введен метод `addCell`(причем если использовать этот метод, то в ячейку помезается значение) и `addCellWithoutValue`(соответственно, чтобы добавлять ячейку без значения).

  Наконец, `viewTable` используется для просмотра всей таблицы, а `deleteTable` для удаления.

## C++

```


#include <iostream>
#pragma once

struct JungTable {
	int s = 3;

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
				else if (lengthOfRow(t) == 5) {
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
			cell* p = t->row;
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

```
## LR1_Pioivis.cpp

### `isCreated()`

Используется для проверки создания таблицы.

### `isAdded_r()`

Используется для проверки добавления строки к таблице.

### `isCreated_c()`

Используется для проверки создания ячейки в таблице и добавления туда же значения.

### `isAdded_c_w()`

Используется для проверки создания ячейки в таблице, но в этот раз значение может и не помещаться.

### `main()`

Нужен для оркестрирования всех методов-тестов.

## C++

```

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
	int array[5] = { 1, 3, 8, 4, 5 };
	JungTable::tableRow* t;
	t = s.createTable();	
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
	JungTable::tableRow* t = s.createTable();
	int arr[5] = { 1, 2, 3, 4, 5 };
	t->row = s.createCell(8, t);
	for (int i = 0; i < 5; ++i) {
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
```

## Вывод

Всякая такого рода структура обладает одним противоречивым свойством: каждая подструктура помещается в отдельные ячейки памяти, причем совсем необязательно, что эти ячейки будут находится
не в хаотичном порядке, поэтому сложно работать с данной структурой без указателей на последующие подструктуры, потому что если мы хотим напрямую в хипе определить их расположение(ведь объекты хранятся
в стеке, если не учитывать вопрос с инстансами объектов), то получим ошибку `C2010`. Плюс ее, на мой взгляд, заключается в динамичности.
