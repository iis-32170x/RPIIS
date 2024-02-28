//
// pch.cpp
//

#include "pch.h"
#include <algorithm>
#include <iostream>

void OMassive::dsort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minind = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minind]) {
                minind = j;
            }
        }
         swap(arr[i], arr[minind]);
    }
}

void OMassive::add(int a) {
    arr.push_back(a);
    dsort(arr);
}

vector<int> OMassive::objedinenie(const vector<int>& arr2) {
     vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        answer.push_back(arr[i]);
    }
    for (int i = 0; i < arr2.size(); i++) {
        answer.push_back(arr2[i]);
    }
    dsort(answer);
    return answer;
}

 vector<int> OMassive::perese4enie(const vector<int>& arr2) {
     vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr[i] == arr2[j]) {
                bool status_of_unic = true;
                for (int k = 0; k < answer.size(); k++) {
                    if (arr[i] == answer[k]) {
                        status_of_unic = false;
                        break;
                    }
                }
                if (status_of_unic) {
                    answer.push_back(arr[i]);
                }
            }
        }
    }

    dsort(answer);
    return answer;
}

int OMassive::poisk(int left, int right, int index_k) {
    if (left >= right) {
        return arr[left];
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[index_k] == arr[mid]) {
            return arr[mid];
        }
        if (arr[index_k] < arr[mid]) {
            return poisk(left, mid - 1, index_k);
        }
        else {
            return poisk(mid + 1, right, index_k);
        }
    }
    return -1;
}