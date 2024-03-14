# Лабораторная работа 1, 2 семестр, 12 вариант

## Цель работы

  Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных. Составить библиотеку для таблицы Юнга.

## Задача

  Создать очередь с приоритетом и реализовать следующий функционал:

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
```

## Вывод

Всякая такого рода структура обладает одним противоречивым свойством: каждая подструктура помещается в отдельные ячейки памяти, причем совсем необязательно, что эти ячейки будут находится
не в хаотичном порядке, поэтому сложно работать с данной структурой без указателей на последующие подструктуры, потому что если мы хотим напрямую в хипе определить их расположение(ведь объекты хранятся
в стеке, если не учитывать вопрос с инстансами объектов), то получим ошибку `C2001`. Плюс ее, на мой взгляд, заключается в динамичности.
