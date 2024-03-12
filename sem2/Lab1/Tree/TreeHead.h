#pragma once 
#include<vector> 
#include <iostream> 
struct FenwickTree
{
private:

	std::vector<int>PrefixSum;

	int size;

public:
	std::vector<int>array;

	FenwickTree(int);

	void CreateTree();

	int Sum(int, int);

	void Update(int, int);



private:

	int f(int);

	int g(int);
};

