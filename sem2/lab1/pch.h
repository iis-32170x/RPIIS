//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <vector>
using namespace std;
struct OMassive {
    vector<int> arr;

    void dsort(vector<int>& arr);
    void add(int a);
    vector<int> objedinenie(const vector<int>& arr2);
    vector<int> perese4enie(const vector<int>& arr2);
    int poisk(int left, int right, int index_k);
};