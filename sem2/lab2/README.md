# <p align="center">Лабораторная работа №2</p>
Вариант 12. Реализовать программу, формирующую множество равное симметрической разности
произвольного количества исходных множеств (с учётом кратных вхождений элементов).
## <p align="center"> Цели лабораторной работы</p>
1. Реализовать программу, формирующую множество равное симметрической разности
произвольного количества исходных множеств (с учётом кратных вхождений элементов).
2. Составить отчет по выполнению лабораторной работы.
## <p align="center"> Список ключевых понятий</p>
1. Множество - совокупность любых объектов(элементов) схожих между собой.
2. Симметрическая разность множеств – это множество, включающее все элементы исходных множеств, не принадлежащие одновременно обоим исходным множествам.
## <p align="center"> Описание алгоритма </p>
### Функция equal:
Эта функция проверят каждый элемент множества на уникальность. Если элемент уникален, то он записывается в множество, которое является симметрической разностью исходных множеств.
```cpp
void equal(char* str1, char* str2, int& z) {
    bool a = true;
    int h = 0;
    int left1, right1, left2, right2;
    left1 = right1 = left2 = right2 = 0;
    if (str1[0] == '{' && str1[strlen(str1) - 1] == '}' && str2[0] == '{' && str2[strlen(str2) - 1] == '}') {
        if (strlen(str1) == strlen(str2)) {
            for (int i = 1; i < strlen(str1) - 1; i++) {
                for (int j = 1; j < strlen(str2) - 1; j++) {
                    if (str1[i] == str2[j]) {
                        h++;
                        break;
                    }
                }
            }
        }
        equalK(str1, str2, left1, right1, left2, right2, a);

    }
    else {
        if (strcmp(str1, str2) == 0) {
            z++;
        }
    }

    if (h == (strlen(str1) - 2) && a == true) {
        z++;
    }
}
```
### Функция equalK:
Эта функция проверяет порядок следования элементов в кортежах.
```cpp
void equalK(char* str1, char* str2, int left1, int right1, int left2, int right2, bool& a) {
    while (left1 < right1 && str1[left1] != '<') {
        left1++;
    }
    while (right1 > left1 && str1[right1] != '>') {
        right1--;
    }
    while (left2 < right2 && str2[left2] != '<') {
        left2++;
    }
    while (right2 > left2 && str2[right2] != '>') {
        right2--;
    }
    if ((left1 == right1 && left2 != right2) || (left1 != right1 && left2 == right2)) {
        a = false;
        return;
    }
    if (left1 != right1 && left2 != right2) {
        int i = left1 + 1;
        int j = left2 + 1;

        while (i < right1 && j < right2) {
            if (str1[i] != str2[j]) {
                a = false;
                return;
            }
            equalK(str1, str2, i, right1, j, right2, a);
            while (i < right1 && str1[i] != '<') {
                i++;
            }
            while (right1 > i && str1[right1] != '>') {
                right1--;
            }
            while (j < right2 && str2[j] != '<') {
                j++;
            }
            while (right2 > j && str2[right2] != '>') {
                right2--;
            }

            i++;
            j++;
        }
    }
}
```
### Цикл ввода
Этот цикл получает от пользователя множество и разбивает это множество на элементы массива.
```cpp
   for (int i = 0; i < m1; i++) {

       cout << "Введите множество";
       b = 0;
       a = 0;
       int s, f;
       cin >> str;
       for (int j = 1; j < size(str) - 1; j++) {
           x = false;
           if (str[j] == '{') {
               for (int k = j; k < size(str) - 1; k++) {
                   if (str[k] == '}') {
                       j = k + 1;
                       x = true;
                       break;
                   }
               }
           }

           if (str[j] == '<') {
               for (int k = j; k < size(str) - 1; k++) {
                   if (str[k] == '>') {
                       j = k + 1;
                       x = true;
                       break;
                   }
               }
           }
           if (str[j] != ',' && str[j] != '}' && str[j] != '>') {
               for (int k = 0; k < size(str); k++) {
                   if (str[k] == ',' || str[k] == '}') {
                       j = k - 1;

                       break;
                   }

               }
           }
           if (str[j] == ',' && str[j + 1] != '<' && str[j + 1] != '{' && !x) {
               for (int k = j + 1; k < size(str); k++) {
                   if (str[k] == ',' || str[k] == '}') {
                       j = k - 1;

                       break;
                   }

               }

           }
           if (str[j] == ',' && str[j + 1] == '<' && !x) {
               for (int k = j; k < size(str) - 1; k++) {
                   if (str[k] == '>') {
                       j = k + 1;
                       x = true;
                       break;
                   }
               }
           }
           if (str[j] == ',' && str[j + 1] == '{' && !x) {
               for (int k = j; k < size(str) - 1; k++) {
                   if (str[k] == '}') {
                       j = k + 1;
                       x = true;
                       break;
                   }
               }
           }
           b++;
           if (x) {
               j--;
           }
       }
       C[i] = b;
       D[0] = new int[b];
       D[1] = new int[b];


       for (int j = 0; j < size(str) - 1; j++) {
           x = false;
           s = j + 1;
           if (str[j] == '{') {
               j++;
           }
           if (str[j] == '{') {
               for (int k = j; k < size(str) - 1; k++) {
                   if (str[k] == '}') {
                       j = k + 1;
                       x = true;
                       break;
                   }
               }
           }
           if (str[j] == '<') {
               for (int k = j; k < size(str) - 1; k++) {
                   if (str[k] == '>') {
                       j = k + 1;
                       x = true;
                       break;
                   }
               }
           }
           if (str[j] != ',' && str[j] != '}' && str[j] != '>') {
               for (int k = 0; k < size(str); k++) {
                   if (str[k] == ',' || str[k] == '}') {
                       j = k - 1;

                       break;
                   }

               }
           }
           if (str[j] == ',' && str[j + 1] != '<' && str[j + 1] != '{' && !x) {
               for (int k = j + 1; k < size(str); k++) {
                   if (str[k] == ',' || str[k] == '}') {
                       j = k - 1;
                       break;
                   }

               }

           }
           if (str[j] == ',' && str[j + 1] == '<' && !x) {
               for (int k = j; k < size(str) - 1; k++) {
                   if (str[k] == '>') {
                       j = k + 1;
                       x = true;
                       break;
                   }
               }
           }
           if (str[j] == ',' && str[j + 1] == '{' && !x) {
               for (int k = j; k < size(str) - 1; k++) {
                   if (str[k] == '}') {
                       j = k + 1;
                       x = true;
                       break;
                   }
               }
           }
           f = j - s;
           if (f == 0) {
               f = 1;
           }
           D[0][a] = s;
           D[1][a] = f;
           a++;
           if (x) {
               j--;
           }
       }
       A[i] = new char* [b];
       for (int j = 0; j < b; j++) {
           string substring = str.substr(D[0][j], D[1][j]);
           char* charArray = new char[D[1][j]];
           substring.copy(charArray, D[1][j]);
           charArray[D[1][j]] = '\0';
           A[i][j] = charArray;
       }
       delete[] D[0];
       delete[] D[1];
   }
```
## <p align="center"> Тестирование</p>
### Тест №1
Вход:
```
{a,b,{b,c}}
{b,{c,b}}
```
Выход:
```
Симметрическая разность множеств: {a}
```
### Тест №2
Вход:
```
{1,2,<g,d>,<2,6>}
{3,<d,g>}
```
Выход:
```
Симметрическая разность множеств: {1, 2, <g,d>, <2,6>, 3, <d,g>}
```
### Тест №3
Вход:
```
{a,b,{g},<a,v>}
{b,g}
{<a,v>,u}
```
Выход:
```
Симметрическая разность множеств: {a, {g}, g, u}
```
## <p align="center"> Вывод</p>
В ходе выполнения лабораторной работы была реализована программа для создания множества, равного симметрической разности вводимых множеств.
