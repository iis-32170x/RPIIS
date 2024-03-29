# Лабораторная работа №2

## Задача:
$\textcolor{#4b0082}{\textit{Вариант 12}}$ Реализовать программу, формирующую множество равное симметрической разности произвольного количества исходных множеств (с учётом кратных вхождений элементов).
## Цель:
* Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных (для нахождения симм разности мультимножеств, считанных из файла).
* Разработать Гугл Тесты, которые проверяют успешное выполнение всех функций

## Список ключевых понятий:
* $\textcolor{#4b0082}{\textbf{Множество}}$ — простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.
* $\textcolor{#4b0082}{\textbf{Мультимножество (множество с учётом кратных вхождений элементов}}$ модификация понятия множества, допускающая включение одного и того же элемента в совокупность по нескольку раз. Число элементов в мультимножестве, с учётом повторяющихся элементов, называется его размером или мощностью.различаются не более, чем на единицу.
* $\textcolor{#4b0082}{\textbf{Симметрической разностью}}$ неориентированных множеств ***A*** и ***B*** *с учётом кратных
вхождений* элементов будем называть неориентированное множество S тогда и только тогда,
когда для любого x истинно ***S|x| = max{A|x|-B|x|, B|x|-A|x|}***.

![png-transparent-symmetric-difference-number-set-complement-rożnica-zbiorow-circle-purple-angle-text](https://github.com/iis-32170x/RPIIS/assets/145003765/dc7ad5f2-f5ed-4c44-89a2-8f2200f2b8f4)

## Алгоритмы операций над мультимножествами

### Считывание мультимножеств из файла

1. Если файл указан некорректно или  его не существует, вылетает сообщение "Ошибка открытия файла!" и выполнение программы завершается
2. Иначе посимвольно считываем файл, записывая в MultiSet[0] первое мультимножество, в MultiSet[1] второе..
  * в зависимости от того, какой символ считался (цифра, фигурная скобка, запятая, пробел, переменная...), он записывается в соответствующее поле мультимножества (элемент, кратность или просто счетчик скобок, который помогает определить начало и конец другого мультимножества или подмножество внутри него)

``` c++
void GetSets(Set MultiSet[], string path) {
    ifstream file;
    file.open(path);

    if (!file.is_open()) {
        throw runtime_error("Ошибка открытия файла!");
    }

    int curr_brackets_count = 0;

    char ch;
    int m = -1;
    MultiSet[0].set_count = m + 1;
    int elem_in_set = 0;
    while (file.get(ch)) {
        if (ch == '{') {
            if (curr_brackets_count > 0) {
                MultiSet[m].Elem[elem_in_set].element.push_back(ch);
                MultiSet[m].Elem[elem_in_set].code_num += ch;
                curr_brackets_count++;
            }
            else {
                m++;
                MultiSet[0].set_count = m + 1;
                elem_in_set = 0;
                curr_brackets_count++;
            }
        }
        else if (ch == ',') {
            if (curr_brackets_count == 1) {
                elem_in_set++;
            }
            else {
                MultiSet[m].Elem[elem_in_set].element.push_back(ch);
                MultiSet[m].Elem[elem_in_set].code_num += ch;
            }
        }
        else if (isdigit(ch)) {
            if (curr_brackets_count == 1) {
                if (MultiSet[m].Elem[elem_in_set].multiplicity == 1 && !MultiSet[m].Elem[elem_in_set].IsAlone) {
                    MultiSet[m].Elem[elem_in_set].multiplicity = (ch - '0');
                    MultiSet[m].Elem[elem_in_set].IsAlone = true;
                }
                else {
                    MultiSet[m].Elem[elem_in_set].multiplicity = MultiSet[m].Elem[elem_in_set].multiplicity * 10 + (ch - '0');
                }
            }
            else {
                MultiSet[m].Elem[elem_in_set].element.push_back(ch);
                MultiSet[m].Elem[elem_in_set].code_num += ch;
            }
        }
        else if (ch == '}') {
            if (curr_brackets_count > 1) {
                MultiSet[m].Elem[elem_in_set].element.push_back(ch);
                MultiSet[m].Elem[elem_in_set].code_num += ch;
                curr_brackets_count--;
            }
            else {
                MultiSet[m].elem_count = elem_in_set + 1;
                curr_brackets_count--;
            }
        }
        else if (ch == ' ' || ch == '\n') {}
        else {
            MultiSet[m].Elem[elem_in_set].element.push_back(ch);
            MultiSet[m].Elem[elem_in_set].code_num += ch;
        }
    }
    MultiSet[0].brackets_count = curr_brackets_count;
    file.close();
}
```
