# Лабораторная работа №2
- `Цель` - найти всевозможные ориентированные множества.
- `Задача` - сформировать без повторений всевозможные ориентированные множества из элементов исходного неориентированного множества.
## Список ключевых понятий:
- `Неориентированное множество` - представляет собой совокупность уникальных элементов, где порядок элементов не имеет значения и отсутствуют направленные связи между элементами.
- `Элментом множества` может являться буквольный символ, число, кортеж, отдельное множество, пустое множество, сочетание буквы и числа.
## Алгоритм:
### Рекурсивная функция generatePermutations.
```cpp
void generatePermutations(int* nums, bool* used, int* current, int currentIndex, int n) {
    if (currentIndex == n) {
        for (int i = 0; i < n; i++) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            current[currentIndex] = nums[i];
            generatePermutations(nums, used, current, currentIndex + 1, n);
            used[i] = false;
        }
    }
}
```
- void generatePermutations(int* nums, bool* used, int* current, int currentIndex, int n) { - nums: указатель на массив чисел, которые будут переставляться; used: указатель на массив логических значений, который отслеживает, какие числа уже были использованы в текущей перестановке; current: указатель на массив, который хранит текущую перестановку чисел; currentIndex: индекс текущего элемента в перестановке; n: общее количество элементов в перестановке.
- if (currentIndex == n) { - проверяет, достигнута ли длина текущей перестановки, равной общему количеству элементов.
- for (int i = 0; i < n; i++) { - цикл, который выполняет итерации от 0 до n-1.
- cout << current[i] << " "; - вывод значения current[i].
- current[currentIndex] = nums[i]; - присваивает значение nums[i] элементу current[currentIndex].
- generatePermutations(nums, used, current, currentIndex + 1, n); - является рекурсивным вызовом функции generatePermutations.
### Функция generateAllPermutations.
```cpp
void generateAllPermutations(vector<char>& symbols) {
    int n = symbols.size();
    vector<bool> used(n, false);
    vector<char> current(n);

    generatePermutations(symbols, used, current, 0, n);
}
```
- void generateAllPermutations(vector<char>& symbols): Функция принимает вектор символов symbols. Это значит, что функция будет работать напрямую с исходным вектором.
- int n = symbols.size();: Эта строка получает размер вектора symbols и сохраняет его в переменную n. Переменная n будет использоваться в дальнейшем для отслеживания количества элементов в множестве.
- vector<bool> used(n, false);: Создает вектор булевых значений used размером n (количество символов).
- vector<char> current(n);: Создает вектор символов current размером n.
- generatePermutations(symbols, used, current, 0, n);: Вызывает рекурсивную функцию generatePermutations.
## Вывод 
Реализовал программу поиска всевозможных ориентированных множеств без повторений.
