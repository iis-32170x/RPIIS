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

Создаем функцию которая проверяет есть ли в нашем множестве пустоты(пробелы)

```C++
void spacetest(string first_set, string second_set) {
	for (int i = 0; i < first_set.length(); i++) {
		if (first_set[i] == ' ') {
			cout << "Incorrect input" << endl;
			cout << "Extra space in set 1";
			exit(0);
		}
	}
	for (int i = 0; i < second_set.length(); i++) {
		if (second_set[i] == ' ') {
			cout << "Incorrect input" << endl;
			cout << "Extra space in set 2";
			exit(0);
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

Проводим операцию пересечения по следующему алгоритму:
<br> 1. Записываем каждый элемент двух множеств в разные векторы.
<br> 2. Сравниваем элементы этих векторов для дальнейшего записи в новое множество.

```C++
string intersection(string first_set, string second_set) {
	string result = "{";
	int temp = 0; //временная переменная для подсчета скобок
	string element = ""; // элемент который бы будем пушить в векторы (временная переменная)
	vector<string> first_set_element; 
	vector<string> second_set_element;
	for (int i = 1; i < first_set.length() - 1; i++) {
		if (first_set[i] == '{' || first_set[i] == '<') {
			temp++;
		}  //если встречаем скобку прибовляем счетчик и пока счетчик не опустится до 0 все это будет считатся одной переменной
		if (temp > 0) {
			element += first_set[i];
		}
		if (first_set[i] == '}' || first_set[i] == '>') {
			temp--;
			if (temp == 0) {
				first_set_element.push_back(element);
				element = ""; //когда счетчик опускается пушим элемент в вектор
			}
		}
		if (temp == 0 && first_set[i] != ',' && first_set[i] != '}' && first_set[i] != '>') {
			element += first_set[i];
		} //записываем эллементы в переменную пока не встретим запятую, потом пушим и очищаем
		if (temp == 0 && (first_set[i] == ',' || first_set[i] == '}' || first_set[i] == '>')) {
			if (!element.empty()) {
				first_set_element.push_back(element);
				element = "";
			}
		}
		if (temp < 0) { //проверка на лишнюю закрывающуюся скобку
			cout << "First set is incorrect, extra closing parenthesis" << endl;
			cout << "Crossing is impossible" << endl;
			exit(0);
		}
		if (i == first_set.length() - 1 && temp > 0) { //проверка на лишнюю открывающуюся скобку
			cout << "First set is incorrect, extra opening parenthesis" << endl;
			cout << "Crossing is impossible";
			exit;
		}
	}

	element = ""; //проделываем тоже самое для второго множества
	for (int i = 1; i < second_set.length() - 1; i++) {
		if (second_set[i] == '{' || second_set[i] == '<') {
			temp++;
		}
		if (temp > 0) {
			element += second_set[i];
		}
		if (second_set[i] == '}' || second_set[i] == '>') {
			temp--;
			if (temp == 0) {
				second_set_element.push_back(element);
				element = "";
			}
		}
		if (temp == 0 && second_set[i] != ',' && second_set[i] != '}' && second_set[i] != '>') {
			element += second_set[i];
		}
		if (temp == 0 && (second_set[i] == ',' || second_set[i] == '}' || second_set[i] == '>')) {
			if (!element.empty()) {
				second_set_element.push_back(element);
				element = "";
			}
		}
		if (temp < 0) {
			cout << "Second set is incorrect, extra closing parenthesis" << endl;
			cout << "Crossing is impossible" << endl;
			exit(0);
		}
		if (i == second_set.length() - 1 && temp > 0) {
			cout << "Second set is incorrect, extra opening parenthesis" << endl;
			cout << "Crossing is impossible";
		}
	}
	for (int i = 0; i < first_set_element.size(); i++) { //обычное прямое сравнивание эллемнтов и если раны то записываем в результирующую переменную
		for (int j = 0; j < second_set_element.size(); j++) {
			if (first_set_element[i] == second_set_element[j]) {
				result = result + first_set_element[i] + ',';
			}
		}
	}
	result.pop_back();
	result += '}';
	return result; // возвращаем результирующее множество
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
