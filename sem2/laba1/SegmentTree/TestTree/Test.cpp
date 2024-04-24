#include <iostream>
#include "C:\Users\roma0\source\repos\SegmentTree\SegmentTree\TreeHead.h"  // Измените на правильный путь к файлу TreeHead.h

int main() {
    std::vector<int> arr = { 1, 2, 3, 2, 1, 3, 1, 1, 2, 3, 3, 3 };
    int N = arr.size();

    // Создаем дерево отрезков для каждого уникального числа
    std::vector<SegmentTree> trees(4, SegmentTree(N));
    for (int i = 0; i < N; ++i) {
        trees[arr[i]].build(arr, 1, 0, N - 1);
    }

    // Запрашиваем количество вхождений числа 2 в отрезке [1, 4]
    int l = 1, r = 4, x = 2;
    std::cout << "Число " << x << " встречается в отрезке [" << l << ", " << r << "] "
        << trees[x].query(1, 0, N - 1, l, r) << " раз.\n";

    return 0;
}