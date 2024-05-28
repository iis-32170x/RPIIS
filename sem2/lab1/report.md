# Лабораторная работа №1
## Цель работы

Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных.

## Задача
Создать дек. Реализовать функции добавления элемента в начало или конец дека, удаления
элемента из начала или конца дека.

## Список ключевых понятий
`Дек`—структура данных, представляющая из себя список элементов, в которой добавление новых элементов и удаление существующих производится с обоих концов. Эта структура поддерживает как FIFO, так и LIFO, поэтому на ней можно реализовать как стек, так и очередь.

## Реализация
### Структура
```c++
	struct Deck {
	public:
		 Deck* addfront(Deck*& begin);
		 Deck* addback(Deck*& end);
		 void output();
		 Deck* delfront(Deck*& begin);
		 Deck* delback(Deck*& end,Deck*& begin);
		 Deck* crtdeck();
		 bool check();
		 Deck* file();
		 Deck* end();
		 int val=0;
		 Deck* next = nullptr;
		 Deck* prev = nullptr;
	};
```
### Функционал
`Функция создания дека при вводе с клавиатуры`
```c++
Deck* Deck :: crtdeck() {
	int n; Deck* node1 = new Deck; Deck* node2 = new Deck;
	cout << "Введите количество элементов в деке:";
	cin >> n;
	while (cin.fail()|| n<1) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите количество элементов в деке:";
		cin >> n;
	}
	cout << "Введите элемент:";
	cin >> this->val;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите элемент:";
		cin >> this->val;
	}
	this->prev = nullptr;
	this->next = node1;
	node1->prev = this;
	for (int i = 1; i < n; i++) {
		cout << "Введите элемент:";
		cin >> node1->val;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Введите элемент:";
			cin >> node1->val;
		}
		node2 = new Deck;
		node2->prev = node1;
		node1->next = node2;
		node1 = node2;
	}
	node2 = node1->prev;
	node2->next = nullptr;
	delete node1;
	return this;
}
```
`Функция вывода`
```c++
void Deck::output() {
	Deck* node = this;
	if (this != nullptr&&this->val) {
		node = this;
		while (node != nullptr) {
			cout << node->val << " ";
			node = node->next;
		}
	}
	else {
		cout << "Дек пуст";
	}
	delete node;
	return;
}
```
`Функция удаления с конца`
```c++
Deck* Deck::delback(Deck*& end,Deck*& begin) {
	Deck* buff = end;
	if (end == begin) {
		delete end;
		end = nullptr;
		return nullptr;
	}
	else {
		end = end->prev;
		end->next = nullptr;
		delete buff;
		return begin;
	}
}
```
`Функция удаления с начала`
```c++
Deck* Deck::delfront(Deck*& begin) {
	Deck* buff = nullptr; 
	if(begin->next!=nullptr)
	buff = begin->next;
	else {
		delete begin; begin = nullptr;
		return nullptr;
	}
	if ( buff!=nullptr) {
		if (buff->next != nullptr) {
			begin->val = buff->val;
			begin->next = begin->next->next;
			if (begin->next != nullptr) {
				begin->next->prev = begin;
			}
		}
		else {
			begin = buff;
			buff = begin->prev;
		}
		delete buff;

	}
	return begin;
}
```
`Функция добавления в начало`
```c++
Deck* Deck::addfront(Deck*& begin) {
	Deck* node = new Deck;
		node->next = begin->next;
		node->prev = begin;
		begin->next = node;
		if (node->next != nullptr) {
			node->next->prev = node;
		}
		node->val = begin->val;
		cout << "Введите значение:";
		cin >> begin->val;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Введите значение:";
			cin >> begin->val;
		}
	return begin;
}
```
`Функция добавления в конец`
```c++
Deck* Deck::addback(Deck*& end) {
	Deck* node = new Deck; 
	node->prev = end;
	end->next = node; 
	cout << "Введите значение:";
	cin >> node->val;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите значение:";
		cin >> node->val;
	}
	node->next = nullptr;
	end = node;
	return this;
}
```
`Функция чтения из файла`
```c++
Deck* Y::Deck::file()
{
	std::ifstream file("tests.txt");
	if (!file) {
		std::cerr << "Файл не найден." << std::endl;
		exit(0);
	}
	std::string line;
	std::getline(file, line);
	std::istringstream iss(line);
	Y::Deck* deck = this; Deck* buff = nullptr;
	int number;
	deck->next = nullptr;
	deck->prev = nullptr;
	while (iss >> number) {
		deck->val = number;
		buff = new Deck;
		buff->prev = deck;
		deck->next = buff;
		deck = buff;
	}
	if (deck->prev != nullptr) {
		deck = deck->prev; delete buff;
		deck->next = nullptr;
	}
	return this;
}
```

## Вывод
Был реализован функционал работы с деком.
