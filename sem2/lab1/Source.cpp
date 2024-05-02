#include <iostream>
#include"Source.h"
using namespace std;


Drevo* build_tree(int* arr, int start, int end) { //start, end на всякий, если не захочу на всём массиве
    if (start == end) {
        Drevo* leaf = new Drevo{start, end, arr[start], nullptr, nullptr };
        //если у меня один элемент, я создаю единственный узел,
        //старту и энду даю их обычное значение, а в сумму передаю значение этого элемента
        //ну и соответственно от него не отходит ничего, поэтому в лево и право по нулям
        return leaf; // возвращаю указатель на этот узел(листик)
    }

    int mid = start + (end - start) / 2;
    Drevo* left_child = build_tree(arr, start, mid);
    Drevo* right_child = build_tree(arr, mid + 1, end);

    Drevo* yzel = new Drevo{ start, end, left_child->sum + right_child->sum, left_child, right_child };
    return yzel;
}

void update(Drevo* root, int start, int end, int value) {

    for (int index = start; index <= end; index++) {

        if (root->start == root->end) { //листочек
            root->sum = value;
            return;
        }

        int mid = root->start + (root->end - root->start) / 2;
        if (index <= mid) {
            update(root->left, start, end, value);
        }
        else {
            update(root->right, start, end, value);
        }

        root->sum = root->left->sum + root->right->sum;
    }
}

int sum_on_range(Drevo* root, int start, int end) {
    if (start > end) {
        return 0;
    }
    if (root->start == start && root->end == end) {
        return root->sum;
    }

    int mid = root->start + (root->end - root->start) / 2;
    if (end <= mid) {
        return sum_on_range(root->left, start, end);
    }
    else if (start > mid) {
        return sum_on_range(root->right, start, end);
    }
    else {
        return sum_on_range(root->left, start, mid) + sum_on_range(root->right, mid + 1, end);
    }
}
