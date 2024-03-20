#include "pch.h"
#include "Library.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int sorted(int a[], int n)
{
	if (n == 1 or n == 0)
		return 1;
	int p = 0; //массив не отсортирован
	for (int i = 0; i < n - 1; i++) 
		if (a[i] <= a[i + 1])
			p = 1; //возрастание
		else {
			p = 0;
			break;
		}
	return p;
}

void arr_sort_incr(int a[], int n) //сортировка по возрастанию
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		    if (a[i] > a[j]) {
			    int buff = a[i];
			    a[i] = a[j];
			    a[j] = buff;
		    }
}

void arr_push(int** a, int* n, int q) //добавление элемента в отсортированный массив
{
	int p = sorted(*a, *n);
	if (p == 0) {
		cout << "Массив не отсортирован" << endl;
		return;
	}
	int ind = -1;
	for (int i = 0; i < *n; i++) 
		if (*(*a + i) >= q) {
			ind = i;
			break;
		}
	if (ind == -1)
		ind = *n;
	*a = (int*)realloc(*a, sizeof(int)*(*n+1));
	*n = *n + 1;
	for (int i = *n; i > ind; i--)
		*(*a + i) = *(*a + i - 1);
	*(*a + ind) = q;	
}

int arr_find(int a[], int n, int q) //поиск элемента в отсортированном массиве
{
	int p = sorted(a, n);
	if (p == 0) {
		cout << "Массив не отсортирован" << endl;
		return -1;
	}
	for (int i = 0; i < n; i++)
		if (a[i] == q)
			return i;
	cout << "Элемент не найден" << endl;
	return -1;
}

void arr_union(int a1[], int n1, int a2[], int n2) //объединение двух отсортированных массивов
{
	int p = sorted(a1, n1);
	if (p == 0) {
		cout << "1-ый массив не отсортирован" << endl;
		return;
	}
	p = sorted(a2, n2);
	if (p == 0) {
		cout << "2-ой массив не отсортирован" << endl;
		return;
	}
	int* un = (int*)malloc(sizeof(int) * (n1+n2));
	int z = 0, flag = 0;
	for (int i = 0; i < n1; i++) {
		flag = 0;
		for (int m = 0; m < z; m++) {
			if (un[m] == a1[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			un[z] = a1[i];
			z++;
		}
	}
	for (int i = 0; i < n2; i++) {
		flag = 0;
		for (int j = 0; j < n1; j++)
			if (a2[i] == a1[j])
				flag++;
		if (flag == 0) {
			un[z] = a2[i];
			z++;
		}
	}
	cout << "Объединением двух массивов является массив: ";
	for (int i = 0; i < z; i++)
		cout << un[i] << " ";
	cout << endl;
	free(un);
}

void arr_intersection(int a1[], int n1, int a2[], int n2) //пересечение двух отсортированных массивов
{
	int p = sorted(a1, n1);
	if (p == 0) {
		cout << "1-ый массив не отсортирован" << endl;
		return;
	}
	p = sorted(a2, n2);
	if (p == 0) {
		cout << "2-ой массив не отсортирован" << endl;
		return;
	}
	int z = 0, flag = 0;
	int* intersect = (int*)malloc(sizeof(int)*n1);
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++) {
			flag = 0;
			if (a1[i] == a2[j]) {
				for (int m = 0; m < z; m++)
					if (intersect[m] == a2[j]) {
						flag = 1;
						break;
					}
				if (flag == 0) {
					intersect[z] = a1[i];
					z++;
				}
			}
		}
	cout << "Пересечением двух массивов является массив: ";
	for (int i = 0; i < z; i++)
		cout << intersect[i] << " ";
	cout << endl;
	free(intersect);
}