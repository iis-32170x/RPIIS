#pragma once
#include<vector>
#include <iostream>
struct FenwickTree
{
	std::vector<int>array;
	int size;

	FenwickTree(int);

	int f(int);

	int g(int);

	int S(int);

	int Sum(int, int);

	void Update(int, int);

};