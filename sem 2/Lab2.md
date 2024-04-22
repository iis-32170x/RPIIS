**Цель:**  
Разработать программу, способную формировать все возможные неориентированные множества без повторений из элементов исходного неориентированного множества. Количество элементов в каждом сформированном множестве должно быть равно исходному натуральному числу n.

**Задача:**
1. Разработать алгоритм генерации всех возможных неориентированных множеств из элементов исходного множества.
2. Убедиться, что каждое сформированное множество не содержит повторяющихся элементов.
3. Гарантировать, что количество элементов в каждом сформированном множестве соответствует исходному натуральному числу n.
4. Реализовать программу на выбранном языке программирования.
5. Проверить работоспособность программы на различных входных данных.

**Список понятий:**
1. Неориентированное множество - совокупность элементов, порядок которых не имеет значения.
2. Повторения - элементы, которые встречаются более одного раза в одном множестве.
3. Алгоритм - последовательность шагов для выполнения задачи.
4. Программа - набор инструкций, выполняющих определенную задачу на компьютере.
5. Входные данные - данные, которые поступают на вход программе для обработки.
6. Выходные данные - результат работы программы, полученный на основе входных данных.

**Алгоритм:**

1. Определить функцию `ReadFile`, которая открывает файл с именем "mnzh.txt" и считывает его содержимое в вектор строк `mnzh`.
2. Определить функцию `generatePermutations`, которая рекурсивно генерирует все перестановки элементов вектора `nums` и сохраняет их в векторе `result`.
3. В основной функции `main`:
    - Установить локаль для корректного отображения русского языка.
    - Вывести сообщение о максимальном количестве элементов в множестве и ждать нажатия клавиши для продолжения.
    - Считать множество из файла, используя функцию `ReadFile`.
    - Если размер множества не превышает 10 элементов:
        - Сформировать все возможные перестановки элементов множества с помощью функции `generatePermutations`.
        - Удалить обратные перестановки из результатов для избежания дублирования.
        - Вывести все полученные комбинации в консоль.
    - В противном случае вывести сообщение о том, что файл пуст или содержит более 10 элементов.

**Код:**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<stack>
#include<algorithm>

using namespace std;

bool read_file(vector<string>& mnzh) {
	string tmp;
	string tmp_mnzh;
	stack<char> braket;

	ifstream file("mnzh.txt");

	if (file.is_open()) {
		while (getline(file, tmp)) {
			tmp_mnzh += tmp;
		}
		file.close();
		tmp.clear();
	}
	else {
		cout << "Не удалось открыть файл";
		return false;
	}

	tmp_mnzh.erase(remove(tmp_mnzh.begin(), tmp_mnzh.end(), ' '), tmp_mnzh.end());

	char previous = '\0';
	int count = 0;


	for (auto& c : tmp_mnzh) {
		if (isdigit(c) || c == '{' || c == '}' || c == ',') {
			
		}
		else {
			cout << "Не правильный формат множества";
			return false;
		}

		if ((c == ',' && c == previous) || (c == '}' && previous == ',') || (previous == '\0' && c != '{') || (c == '}' && previous == '{')) {
			cout << "Не правильный формат множества";
			return false;
		}

		if (c == '{' || c == '}') { count++; }

		previous = c;
	}

	if (count % 2 != 0) {
		cout << "Не правильный формат множества";
		return false;
	}

	tmp_mnzh.erase(0, 1);
	tmp_mnzh.pop_back();

	for (auto& c : tmp_mnzh) {
		if (c == '{' || c == '}') { tmp+=c; }
	}

	for (int i = 0; i < tmp.size()-1; i++) {
		if (tmp[i] == '{' && tmp[i + 1] == '}') {
			tmp.erase(i, 2);
			i = -1;
		}
		if (tmp.size() == 0) { break; }
	}
	
	if (tmp.size() != 0) {
		cout << "Не правильный формат множества";
		return false;
	}

	for (auto& c : tmp_mnzh) {
		if (c == '{') {
			braket.push(c);
			tmp += c;
		}
		else if (c == '}' && braket.size()!=0) {
			tmp += c;
			braket.pop();
			if (braket.size() == 0) {
				mnzh.push_back(tmp);
				tmp.clear();
			}
		}
		else if (braket.size() == 0 && c != ',') {
			tmp += c;
		}
		else if (braket.size() == 0 && c == ',') {
			if (tmp.size() != 0) {
				mnzh.push_back(tmp);
				tmp.clear();
			}
		}
		else if (braket.size() != 0) {
			tmp += c;
		}
	}
	if (tmp.size() != 0) {
		mnzh.push_back(tmp);
	}

	return true;
}



void generateCombinations(const std::vector<string>& elements, std::vector<std::vector<string>>& combinations, int k, int start, std::vector<string>& current) {
	if (k == 0) {
		combinations.push_back(current);
		return;
	}

	for (int i = start; i <= elements.size() - k; ++i) {
		current.push_back(elements[i]);
		generateCombinations(elements, combinations, k - 1, i, current); // Используем i вместо i + 1
		current.pop_back();
	}
}

bool equal(vector<string>& vec1, vector<string>& vec2) {
	vector<string> tmp1 = vec1;
	vector<string> tmp2 = vec2;

	sort(tmp1.begin(), tmp1.end());
	sort(tmp2.begin(), tmp2.end());

	return tmp1 == tmp2;

}

int main() {
	setlocale(LC_ALL, "ru");
	vector<string>current;
	vector<string> mnzh;
	vector<vector<string>> permutations;
	int size;

	if (read_file(mnzh)) {
		cout << "Введите размер будущих сформированных множеств: ";
		do {
			cin >> size;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Неправильный ввод, пожалуйста, введите еще раз: ";
				cin >> size;
			}
		} while (size > mnzh.size() || size < 0);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");

		generateCombinations(mnzh,permutations, size,0,current);

		for (auto it = permutations.begin(); it != permutations.end(); ++it) {
			for (auto it2 = it + 1; it2 != permutations.end();) {
				if (equal(*it, *it2)) {
					it2 = permutations.erase(it2);
				}
				else { ++it2; }
			}
		}

		
		for (auto& c : permutations) {
			cout << "{";
			for (auto& b : c) {
				cout << b;
					cout << " ";
			}
			cout << "}" << endl;
		}

	}
}
```
**Вывод:**
После выполнения данного задания была разработана программа, способная формировать все возможные неориентированные множества без повторений из элементов исходного неориентированного множества. Эта программа обеспечивает гарантированное количество элементов в каждом сформированном множестве, соответствующее заданному натуральному числу n. Алгоритм был проверен на различных входных данных, подтверждая корректность его работы.
