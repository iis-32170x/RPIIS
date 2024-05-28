# Лабораторная работа 2
***
## Цель
Цель работы - разработать программу для работы с множествами.
***
## Задание
### Вариант 10
Реализовать программу, формирующую множество равное объединению произвольного
количества исходных множеств (с учётом кратных вхождений элементов).
***
## Ключевые понятия
`Множество` — простейшая информационная конструкция и математическая структура, позволяющая рассматривать какие-то объекты как целое, связывая их.
***
## Структура
```c++
namespace Y {
	struct element {
		element* next = nullptr;
		element* prev = nullptr;
		element* side = nullptr;
		element* prevside = nullptr;
		std::string field ;
		int mult = 1;
	};
	class set {
	private:
		element* Insert(element* el, std::string a);
		bool subset(element* A, element* B);
		void Insert(std::string a);
		void output(element* mnvo);
		std::string check(std::string mnvo);
	public:
		void input();
		void output(set* mnvo);
		set** Obed(set** mnvo, int n);
		element* multiplicity(element* mnvo);
		set** file(set**& mnvo,int& countr);
		element* root = nullptr;
	};
}
```
***
## Реализация на C++
`Функция проверки на корректность ввода`
```c++
std::string set::check(std::string mnvo) {
	bool inword = false;  int ind1 = 0; int ind2 = 0; int skb = 0; 
	for (size_t i = 0; i < mnvo.length(); ++i) {
		if ((mnvo[i] == '{' || mnvo[i] == ',') && inword == true) {
			inword = false;
		}
		else {
			if (mnvo[i] != ' ' && mnvo[i] != ',' && mnvo[i] != '{' && mnvo[i] != '}') {
				inword = true;
			}
		}
		if (inword == false && mnvo[i] == ' ') {
			for (ind1 = 0; mnvo[i] == ' '; i++ && ind1++);
			mnvo.erase(i - ind1, ind1);
			i = i - ind1;
		}
		else if (mnvo[i] == ' ' && inword == true) {
			for (ind1 = 0; mnvo[i + 1] == ' '; i++ && ind1++);
			mnvo.erase(i - ind1, ind1);
			i = i - ind1;
		}
		if (mnvo[i] == ' ' && (mnvo[i + 1] == ',' || mnvo[i + 1] == '}')) {
			mnvo.erase(i, 1);
			i += -2;
		}
	}
	if (mnvo[mnvo.length() - 1] == ' ')
		mnvo.erase(mnvo.length() - 1, 1);
	if (mnvo[0] == ' ')
		mnvo.erase(0, 1);
	if (mnvo[0] != '{') {
		return "";
	}
	if (mnvo[mnvo.length()-1] != '}')
		return "";
	skb++;
	for (int i = 1; i < mnvo.length(); i++) {
		if (mnvo[i] == '}') {
			skb--;
			if (skb == 0 && i != mnvo.length() - 1) {
				return "";
			}
		}
		else if (mnvo[i] == '{') {
			skb++;
		}
		if (mnvo[i - 1] == '}' && mnvo[i] == '{')
			return "";
		else if (mnvo[i - 1] == '{' && mnvo[i] == ',')
			return "";
		else if (mnvo[i - 1] == ',' && mnvo[i] == '}')
			return "";
		else if (mnvo[i - 1] == ',' && mnvo[i] == ',')
			return "";
		else if ((mnvo[i - 1] != ',' && mnvo[i - 1] != '{') && mnvo[i] == '{')
			return "";
		else if ((mnvo[i] != ',' && mnvo[i] != '{' && mnvo[i] != '}') && mnvo[i - 1] == '}')
			return "";
		else if (mnvo[i] != '{' && mnvo[i] != '}' && mnvo[i] != ',' && i + 2 < mnvo.length()) {
			if (mnvo[i + 2] == '{' && mnvo[i + 1] == ' ')
				return "";
		}else
			if (mnvo[i] == '}' && i + 2 < mnvo.length()) {
				if (mnvo[i + 1] == ' ' && mnvo[i + 2] != ',' && mnvo[i + 2] != '{' && mnvo[i + 2] != '}'&&mnvo[i+2]!=' ')
					return "";
			}
	}
	if (skb != 0)
		return"";
	return mnvo;
}
```
`Функция вставки нового элемента в структуру`
```c++
element* set::Insert(element* node,std::string a) {
	element* buff; int ind = 1;
	again:
	buff = new element;

	if (node==nullptr&&a[0]!='{') {
		node = new element;
		node->field = a;
		buff = node;
	}
	else if (a[0] == '{' && node == nullptr && a[1] != '}') {
		node = new element;
		node->field = "";
		buff = new element;
		buff->prevside = node;
		node->side = buff;
		node = buff;
		for (int i = 1; a[i] == '{'; i++) {
			if (a[i + 1] == '}') {
				buff->field = "";
				ind += 2;
				if (i + 1 == a.length() - 1) {
					return buff;
				}
				break;
			}
			buff->field = "";
			ind++;
			buff = new element;
			buff->prevside = node;
			node->side = buff;
			node = buff;
		}
		a = a.substr(ind, a.length() - ind);
		if (a[0] == '}') {
			goto cycle;
		}
		buff->field = a;
		node = buff;
	}
	else if (a[0] != '{' && node != nullptr) {
		buff->prev = node;
		node->next = buff;
		buff->field = a;
		node = buff;
	}else 
		if(a[0] == '{' &&a[1]!='}' && node != nullptr) {
		buff->prev = node;
		node->next = buff;
		buff->field = "";
		node = buff;
		buff = new element;
		buff->prevside = node;
		node->side = buff;
		node = buff;
		for (int i = 1; a[i] == '{';i++) {
			if (a[i + 1] == '}') {
				buff->field = "";
				ind += 2;
				if (i + 1 == a.length() - 1) {
					return buff;
				}
				break;
			}
			ind++;
			buff->field = "";
			buff = new element;
			buff->prevside = node;
			node->side = buff;
			node = buff;
		}
		a = a.substr(ind, a.length() - ind);
		if (a[0] == '}') {
			goto cycle;
		}
		buff->field = a;
		node = buff;
		}
		else
			if (a[0] == '{' && a[1] == '}' && node != nullptr) {
				buff->prev = node;
				node->next = buff;
				buff->field = "";
				node = buff;
				if (a.length() == 2) {
					return buff;
				}
				a = a.substr(1, a.length() - 2);
			}
			else
				if (a[0] == '{' && node == nullptr && a[1] == '}') {
					node = new element;
					node->field = "";
					return node;
				}
cycle:
	for (int i = 1;i<a.length()+1; i++) {
		if (a[a.length() - i] == '}') {
			while (buff->prevside == nullptr && buff->prev != nullptr) {
				buff = buff->prev;
			}
			if (buff->prevside != nullptr)
				buff = buff->prevside;
			node->field = node->field.substr(0, node->field.length() - 1);
		}
		else {
			break;
		}
	}
	return buff;
}
```
`Функция ввода и парсинга с клавиатуры`
```c++
void set:: input() {
	std::string mnvo; int ind1 = 0; int ind2 = 0;
	std::cin.ignore();
agn:
		std::cout << "Введите множество:";
		std::getline(std::cin, mnvo);
		if (mnvo.empty()) {
			goto agn;
		}
		mnvo = check(mnvo);
		if (mnvo == "") {
			goto agn;
		}
		if (mnvo == "{}") {
			root = nullptr;
		}
		else {
			for (int i = 1; i < mnvo.length(); i++) {
				if (mnvo[i] != '}' && mnvo[i] != ',') {
					ind1 = i; ind2 = 1;
					for (; mnvo[i] != ',' && mnvo[i] != '}'; i++ && ind2++);
					if (mnvo[i] == ',') {
						i--; ind2--;
					}
					for (; mnvo[i] == '}' && i < mnvo.length() - 1; i++ && ind2++);
					if (mnvo[i] == '\0') {
						ind2 += -2;
					}
					else
						if (mnvo[i - 1] == '}') {
							ind2--;
						}
					root = Insert(root, mnvo.substr(ind1, ind2));
				}
			}
			while (root->prev != nullptr)
				root =root->prev;
		}
		return;
}
```
`Функция вывода`
```c++
void Y::set::output(element* mnvo)
{
	element* buff = new element;
	if (mnvo == nullptr) {
		std::cout << "{}";
		return;
	}
	while (mnvo->prev != nullptr) {
		mnvo = mnvo->prev;
	}
	std::cout << "{";
	while (mnvo->next != nullptr) {
		if(mnvo->side==nullptr){
			if (mnvo->field == "") {
				if (mnvo->mult != 1)
				std::cout <<mnvo->mult<<" {},";
				else
					std::cout  << "{},";
			}
			else
			if (mnvo->mult != 1) 
				std::cout << mnvo->mult << " " << mnvo->field << ",";
			else
				std::cout << mnvo->field << ",";
			}
		else {
			if (mnvo->mult != 1)
			std::cout << mnvo->mult << " ";
			buff = mnvo;
			output(mnvo->side);
			mnvo = buff;
			std::cout << ",";
		}
		mnvo = mnvo->next;
	}
	if (mnvo->side == nullptr) {
		if (mnvo->field == "") {
			if (mnvo->mult != 1)
				std::cout << mnvo->mult << " {}";
			else
				std::cout << "{}";
		}
		else
			if (mnvo->mult != 1)
				std::cout << mnvo->mult << " " << mnvo->field;
			else
				std::cout << mnvo->field ;
	}
	else {
		if (mnvo->mult != 1)
			std::cout << mnvo->mult << " ";
		buff = mnvo;
		output(mnvo->side);
		mnvo = buff;
	}
	std::cout << "}";
	return;
}
```
`Функция подсчета кратных вхождений`
```c++
element* Y::set::multiplicity(element* mnvo){
	element* buff = new element; element* buff1 = new element;
		if (mnvo == nullptr) {
			return mnvo;
		}
		while (mnvo->prev != nullptr) {
			mnvo = mnvo->prev;
			while (mnvo->prevside != nullptr) {
				mnvo = mnvo->prevside;
			}
		}
		buff = mnvo; 
		while (mnvo != nullptr) {
			buff1 = mnvo;
			if (mnvo->side!=nullptr) {
				mnvo = multiplicity(mnvo->side);
				mnvo = buff1;
			}
			mnvo=mnvo->next;
		}
		mnvo = buff;
		while (buff->next != nullptr) {
			mnvo = buff;
			while (mnvo->next != nullptr) {
				buff1 = new element;
				mnvo = mnvo->next;
				if ((mnvo->field == buff->field && buff->side==nullptr&&mnvo->side==nullptr) || (mnvo->field == buff->field && buff->side != nullptr && mnvo->side != nullptr && subset(buff, mnvo) == true )) {
					buff->mult++;
					buff1 = mnvo;
					mnvo = mnvo->prev;
					mnvo->next = mnvo->next->next;
					if (buff1->next != nullptr)
						buff1->next->prev = mnvo;
					delete buff1;
				}
			}
			if(buff->next!=nullptr)
			buff = buff->next;
		}
	return mnvo;
}
```
`Функция чтения и парсинга из файла`
```c++
set** Y::set::file(set**& mnvo,int& countr)
{
	std::string mnv; 
	 int ind = 0; int ind1 = 0; int ind2 = 0;
	std::ifstream file("sets6.txt");
	if (file.is_open()) {
		while (std::getline(file, mnv)) {
			if (!mnv.empty()) { 
				mnv = check(mnv);
				if (mnv != "") {
					countr++;
				}
			}
		}
		file.clear();
		file.seekg(0, std::ios::beg);
		if (countr < 2) {
			return nullptr;
		}
		mnvo= new set * [countr];
		while (std::getline(file, mnv)) {
			if (!mnv.empty()) { 
				mnv = check(mnv);
				if (mnv != "") {
					mnvo[ind] = new set;
					if (mnv == "{}") {
						mnvo[ind]->root = nullptr;
					}
					else {
						for (int i = 1; i < mnv.length(); i++) {
							if (mnv[i] != '}' && mnv[i] != ',') {
								ind1 = i; ind2 = 1;
								for (; mnv[i] != ',' && mnv[i] != '}'; i++ && ind2++);
								if (mnv[i] == ',') {
									i--; ind2--;
								}
								for (; mnv[i] == '}'&&i<mnv.length()-1; i++&&ind2++);
								if (mnv[i] == '\0') {
									ind2 += -2;
								}else
								if (mnv[i - 1] == '}') {
									ind2--;
								}

								mnvo[ind]->root = Insert(mnvo[ind]->root, mnv.substr(ind1, ind2));
							}
						}
						while (mnvo[ind]->root->prev != nullptr)
							mnvo[ind]->root = mnvo[ind]->root->prev;
					}
					ind++;
				}
			}
		}
		file.close();
		return mnvo;
	}
	else {
		std::cout << "Не удалось открыть файл." << std::endl;
	}
	return nullptr;

}
```
`Функция проверки равенства подмножества`
```c++
bool set::subset(element* A, element* B) {
	element* buff1 = new element; element* buff2 = new element; element* buff3 = new element;
	A = A->side;	B = B->side; buff3 = B; int amnta = 1; int amntb = 1; buff2 = A;
	while (A->next != nullptr) {
		A = A->next;
		amnta++;
	}
	amnta++;
	A = buff2;
	while (B->next != nullptr) {
		B = B->next;
		amntb++;
	}
	amntb++;
	if (amnta != amntb) {
		return false;
     }
	B = buff3;
	while (A->next != nullptr) {
		while (B->next != nullptr) {
			if (A->field == B->field && A->side==nullptr&&B->side==nullptr&&A->mult==B->mult) {
				goto next;
			}
			else if (A->field == B->field && A->side != nullptr && B->side != nullptr) {
				buff1 = A;
				buff2 = B;
				if (subset(A, B) == false) {
					A = buff1; B = buff2;
				}
				else {
					A = buff1; B = buff2;
					if (A->mult == B->mult)
						goto next;
					else
						return false;
				}
			}
			B = B->next;
		}
		if (A->field == B->field && A->side == nullptr && B->side == nullptr && A->mult == B->mult) {
			goto next;
		}
		else if (A->field == B->field && A->side != nullptr && B->side != nullptr ) {
			buff1 = A;
			buff2 = B;
			if (subset(A, B) == false) {
				A = buff1; B = buff2;
			}
			else {
				A = buff1; B = buff2;
				if (A->mult == B->mult)
					goto next;
				else
					return false;
			}
		}
		return false;
	next:
		A = A->next;
		B = buff3;
	}
		while (B->next != nullptr) {
			if (A->field == B->field && A->side == nullptr && B->side == nullptr && A->mult == B->mult) {
				return true;
			}
			else if (A->field == B->field && A->side != nullptr && B->side != nullptr ) {
				buff1 = A;
				buff2 = B;
				if (subset(A, B) == false) {
					A = buff1; B = buff2;
				}
				else {
					A = buff1; B = buff2;
					if (A->mult == B->mult)
						return true;
					else
						return false;
				}
			}
			B = B->next;
		}
		if (A->field == B->field && A->side == nullptr && B->side == nullptr && A->mult == B->mult) {
			return true;
		}
		else if (A->field == B->field && A->side != nullptr && B->side != nullptr && A->mult == B->mult) {
			buff1 = A;
			buff2 = B;
			if (subset(A, B) == false) {
				return false;
			}
			else {
				A = buff1; B = buff2;
				if (A->mult == B->mult)
					return true;
				else
					return false;
			}
		}
		else {
			return false;
		}

		return true;
}
```
`Функция объединения`
```c++
set** set::Obed(set** mnvo,int n) {
	element* buff = new element;
	while (mnvo[0]->root == nullptr) {
		if (n == 1) {
			return mnvo;
		}
		mnvo[0] = mnvo[n - 1];
		n--;
	}
	while (mnvo[0]->root->prev != nullptr)
		mnvo[0]->root = mnvo[0]->root->prev;
	buff = mnvo[0]->root;
	for (int i = 1; i < n; i++) {
		if (mnvo[i]->root == nullptr) {
			if (i + 1 < n) {
				i++;
			}
			else {
				break;
			}
		}
		while (mnvo[i]->root->prev != nullptr)
			mnvo[i]->root = mnvo[i]->root->prev;
		while (mnvo[i]->root->next != nullptr) {
			while (mnvo[0]->root->next != nullptr) {
				if (mnvo[0]->root->field == mnvo[i]->root->field && mnvo[0]->root->side == nullptr && mnvo[i]->root->side == nullptr) {
					goto next;
				}
				else if (mnvo[0]->root->side!=nullptr && mnvo[i]->root->side!=nullptr&&subset(mnvo[0]->root,mnvo[i]->root)==true) {
					goto next;
				}
				mnvo[0]->root = mnvo[0]->root->next;
			}
			if (mnvo[0]->root->field == mnvo[i]->root->field && mnvo[0]->root->side == nullptr && mnvo[i]->root->side == nullptr) {
				goto next;
			}
			else if (mnvo[0]->root->side != nullptr && mnvo[i]->root->side != nullptr && subset(mnvo[0]->root, mnvo[i]->root) == true) {
				goto next;
			}
			//insert in mnvo[0],remove in mnvo[i]
			if (mnvo[i]->root->prev != nullptr) 
			   mnvo[i]->root->prev->next = mnvo[i]->root->next;
			if(mnvo[i]->root->next!=nullptr)
			   mnvo[i]->root->next->prev = mnvo[i]->root->prev;
			mnvo[0]->root->next = mnvo[i]->root;
			if(mnvo[i]->root->prev!=nullptr)
			   mnvo[i]->root = mnvo[i]->root->prev;
			else {
				mnvo[i]->root = mnvo[i]->root->next;
				mnvo[0]->root->next->prev = mnvo[0]->root;
				mnvo[0]->root->next->next = nullptr;
				goto skip1;
			}
			mnvo[0]->root->next->prev = mnvo[0]->root;
			mnvo[0]->root->next->next = nullptr;
			goto skip;
		next:
			if (mnvo[0]->root->mult < mnvo[i]->root->mult) {
				mnvo[0]->root->mult = mnvo[i]->root->mult;
			}
			skip:
			if(mnvo[i]->root->next!=nullptr)
			mnvo[i]->root = mnvo[i]->root->next;
			skip1:
			mnvo[0]->root = buff;
		}
		while (mnvo[0]->root->next != nullptr) {
			if (mnvo[0]->root->field == mnvo[i]->root->field && mnvo[0]->root->side == nullptr&&mnvo[i]->root->side==nullptr) {
				goto next1;
			}
			else if (mnvo[0]->root->side != nullptr && mnvo[i]->root->side != nullptr && subset(mnvo[0]->root, mnvo[i]->root) == true) {
				goto next1;
			}
			mnvo[0]->root = mnvo[0]->root->next;
		}
		if (mnvo[0]->root->field == mnvo[i]->root->field && mnvo[0]->root->side == nullptr && mnvo[i]->root->side == nullptr) {
			goto next1;
		}
		else if (mnvo[0]->root->side != nullptr && mnvo[i]->root->side != nullptr && subset(mnvo[0]->root, mnvo[i]->root) == true) {
			goto next1;
		}
		if(mnvo[i]->root->prev!=nullptr)
		mnvo[i]->root->prev->next = mnvo[i]->root->next;
		mnvo[0]->root->next = mnvo[i]->root;
		mnvo[0]->root->next->prev = mnvo[0]->root;
	next1:
		if (mnvo[0]->root->mult < mnvo[i]->root->mult) {
			mnvo[0]->root->mult = mnvo[i]->root->mult;
		}
		mnvo[0]->root = buff;
	}
	return mnvo;
}
```
***
## Вывод

В ходе выполнения работы был реализован алгоритм объединения исходного количества множеств с учётом кратных вхождений элементов.
