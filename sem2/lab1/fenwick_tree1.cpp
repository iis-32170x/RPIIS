#include <iostream>
#include <vector>
#include "fenwick_tree1.h"



    vector<int> tree;
    vector<int> arr;

    FenwickTree::FenwickTree(int size)                   
        tree.resize(size + 1);
        arr.resize(size + 1);
    }

    void FenwickTree:: update(int idx, int value)         
    {
        while (idx < tree.size())
        {
            tree[idx] += value;
            idx += idx & -idx;
        }
    }


    void FenwickTree:: updateArr(int idx, int newValue) {
        int diff = newValue - (arr[idx - 1]); 
        arr[idx - 1] = newValue; 

        update(idx, diff); 
    }



    int FenwickTree:: sum(int x) {                     
        int result = 0;

        while (x > 0) {
            result += tree[x];
            x -= x & -x;
        }

        return result;
    }

    int  FenwickTree:: sum(int l, int r) {                 
        if (l > 0) {
            return sum(r) - sum(l - 1);
        }
        else {
            return sum(r);
        }
    }

