<h1 align = "center">Лабораторная работа №2</h1>
<h3>Вариант 2. Реализовать программу, формирующую множество равное пересечению произвольного
количества исходных множеств (без учёта кратных вхождений элементов).</h3>
<h2 align = "center">Цель лабораторной работы:</h2>
1.Разрабатываю среду для работы на выбранном императивном языке программирования (например, C++, Java, Python).
<br>2.Создать тестовую программу для обработки операции пересечения над множествами без кратных вхождений.
<br>3.Разработайте системные тесты для проверки работоспособности программы.
<br>4.Обеспечить обработку некорректированных данных, предусмотрев правильное завершение программы при устранении ошибок.
<br>5.Составить отчет по выполнению лабораторной работы.
<h2 align = "center">Список используемых понятий</h2>
<B>Множество</B> — это набор каких-либо объектов. Объекты, из которых состоит множество, называются элементами этого множества.
<br><B>Элментом множества</B> может представлять собой буквольный символ, число, кортеж, отдельное множество, пустое множество, сочетание цифр и чисел.
<br><B>Пересече́ние мно́жеств</B> в теории множеств — это множество, которому принадлежат те и только те элементы, которые одновременно принадлежат всем данным множествам.
<h2>Алгоритм:</h2>
 Создаем функцию для считывания множеств из файла
 
 ```C++
 string fromFile(string filename) {
	string text;
	ifstream file(filename);
	while (file) {
		getline(file, text);
	}

	return text;
}
```

Создаем функцию которая проверяет есть ли в нашем множестве пустоты(пробелы) и удаляем их

```C++
void spacetest(string first_set, string second_set) {
	for (int i = 0; i < first_set.length(); i++) {
		if (first_set[i] == ' ') {
			first_set.erase(i, 1);
		}
	}
	for (int i = 0; i < second_set.length(); i++) {
		if (second_set[i] == ' ') {
			second_set.erase(i, 1);
		}
	}
}
```

А также создаем функцию, которая проверяет является ли наш входящий файл впринципе множеством

```C++
void setСhecking(string first_set, string second_set) {
	if (first_set[0] != '{' || first_set[first_set.length()-1] != '}') {
		cout << "Set 1 is not one";
		exit(0);
	}
	if (second_set[0] != '{' || second_set[second_set.length()-1] != '}') {
		cout << "Set 2 is not one";
		exit(0);
	}
}
```
Создаем функцию которая будет записывать элементы мноэества из строки в вектор
```C++
vector<string> elementpush(string set) {
	vector<string>vecSet;
	int temp = 0;
	string element = "";
	for (int i = 1; i < set.length() - 1; i++) {
		if (set[i] == '{' || set[i] == '<') {
			temp++;
		}
		if (temp > 0) {
			element += set[i];
		}
		if (set[i] == '}' || set[i] == '>') {
			temp--;
			if (temp == 0) {
				vecSet.push_back(element);
				element = "";
			}
		}
		if (temp == 0 && set[i] != ',' && set[i] != '}' && set[i] != '>') {
			element += set[i];
		}
		if (temp == 0 && (set[i] == ',' || set[i] == '}' || set[i] == '>')||(temp == 0 && i == set.length()-2)) {
			if (!element.empty()) {																		
				vecSet.push_back(element);                                              
				element = "";
			}
		}
		if (temp < 0) {
			cout << "First set is incorrect, extra closing parenthesis" << endl;
			cout << "Intersection is impossible" << endl;
			exit(0);
		}
		if (i == set.length() - 1 && temp > 0) {
			cout << "First set is incorrect, extra opening parenthesis" << endl;
			cout << "Intersection is impossible";
			exit(0);
		}
		if ((set[i] == ',' && set[i + 1] == ',') || (set[i] == ',' && set[i + 1] == '}')) {
			cout << "Incorrect set, extra ','";
			exit(0);
		}
	}
	
	return vecSet;
}

```

Создаем функцию которая будет считывать множества внутри наших множеств, проверять их на кратность и сортировать для удобства дальнейшего сравнения
```C++
vector<string> multiple_occurrences(vector<string> set) {
	string el;
	string text_temp = "";
	vector<string> current;
	for (int i = 0; i < set.size(); i++) {
		el = set[i];
		if (el[0] == '{' && el[el.length()-1] == '}') { 
			current = elementpush(el);
			sort(current.begin(), current.end());
			current.erase(unique(current.begin(), current.end()), current.end());
			text_temp = "{";
			for (int k = 0; k < current.size(); k++) {
				text_temp += current[k];
				if (k != current.size() - 1) {
					text_temp += ",";
				}
			}
			text_temp += "}";
			set[i] = text_temp;
		}
	}
	cout << "R: ";
	for (int i = 0; i < set.size(); i++) {
		cout << set[i] << endl;
	}
	return set;
}

```
Проводим операцию пересечения поэтапно сравнивая элементы вектора созданого двумя нашими функциями

```C++
string intersection(string first_set, string second_set) {
	string result = "{";
	vector<string> first_set_element;
	vector<string> second_set_element;
	vector<string> first_set_el_rework;
	vector<string> second_set_el_rework;
	first_set_element = elementpush(first_set);
	first_set_element.erase(unique(first_set_element.begin(), first_set_element.end()), first_set_element.end());
	second_set_element = elementpush(second_set);
	second_set_element.erase(unique(second_set_element.begin(), second_set_element.end()), second_set_element.end());
	first_set_el_rework = multiple_occurrences(first_set_element);
	second_set_el_rework = multiple_occurrences(second_set_element);
	cout << endl;
	for (int i = 0; i < first_set_el_rework.size(); i++) {
		for (int j = 0; j < second_set_el_rework.size(); j++) {
				if (first_set_el_rework[i] == second_set_el_rework[j]) {
					result = result + first_set_el_rework[i] + ',';
				}
			}   
		} 
		result.pop_back();
		if (!result.empty()) {
			result += '}';
		}
		return result;
	}

```

<h2>Тесты:</h2>
Тест 1:
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/sem2/lab2/img/image.png?raw=true"></image>
Tecn 2:
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/sem2/lab2/img/image%20(1).png?raw=true"></image>
Tecт 3:
<br> Set 1: {{1,a,b}{}}} (лишняя закрывающая скобка)
<br> Set 2: {<a,b,c>,{a,b,c}}
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/sem2/lab2/img/image%20(2).png?raw=true"></image>
Tecт 4: 
<br> Set 1: {<a,b>, } (лишний пробел)
<br> Set 2: <a,b>,a,0}
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/sem2/lab2/img/image%20(3).png?raw=true"></image>
<h2>Вывод:</h2>
<h4>Реализовали программу для выполнения пересечения множеств на языке С++</h4>
