# Лабораторная работа №2
- `Цель` - найти всевозможные ориентированные множества.
- `Задача` - сформировать без повторений всевозможные ориентированные множества из элементов исходного неориентированного множества.
## Список ключевых понятий:
- `Неориентированное множество` - представляет собой совокупность уникальных элементов, где порядок элементов не имеет значения и отсутствуют направленные связи между элементами.
- `Элментом множества` может являться буквольный символ, число, кортеж, отдельное множество, пустое множество, сочетание буквы и числа.
## Алгоритм:
###Рекурсивная функция generatePermutations.
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
###Функция generateAllPermutations.
```cpp
void generateAllPermutations(int n) {
    int* nums = new int[n];
    bool* used = new bool[n];
    int* current = new int[n];

    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
        used[i] = false;
    }

    generatePermutations(nums, used, current, 0, n);

    delete[] nums;
    delete[] used;
    delete[] current;
}
```
- void generateAllPermutations(int n) { - принимает один аргумент n, который представляет общее количество чисел для генерации перестановок.
-  int* nums = new int[n]; - создает динамический массив nums типа int размером n.
- bool* used = new bool[n]; - создает динамический массив used типа bool размером n.
- int* current = new int[n]; - создает динамический массив current типа int размером n.
- generatePermutations(nums, used, current, 0, n); - является вызовом функции generatePermutations с передачей аргументов.
- delete[] nums; - используется для освобождения памяти, выделенной для динамического массива nums.
- delete[] used; - используется для освобождения памяти, выделенной для динамического массива used.
- delete[] current; - используется для освобождения памяти, выделенной для динамического массива current.
## Вывод 
Реализовал программу поиска всевозможных ориентированных множеств без повторений.
