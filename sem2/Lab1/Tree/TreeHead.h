#pragma once 
#include<vector> 
#include <iostream> 
struct FenwickTree
{
private:
	std::vector<int>PrefixSum;

public:
	std::vector<int>array;
	int size;
	FenwickTree(int);

	void CreateTree();

	int Sum(int, int);

	void Update(int, int);



private:
	int f(int);

	int g(int);
};
