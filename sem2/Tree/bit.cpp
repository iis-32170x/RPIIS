#include "HeaderOfTree.h"
	FenwickTree::FenwickTree(int n)
	{
		size = n;
		array = std::vector<int>(n, 0);
	}

	int FenwickTree::f(int i)
	{
		return i & (i + 1);
	}

	int FenwickTree::g(int i)
	{
		return i | (i + 1);
	}

	int FenwickTree::S(int i)
	{
		int sum = 0;
		for (int j = f(i); j <= i; j++)
		{
			sum += array[j];
		}
		return sum;
	}

	int FenwickTree::Sum(int start, int pos)
	{
		int sum_start = 0;
		for (int i = start - 1; i >= 0; i = f(i) - 1)
		{
			sum_start += S(i);
		}
		int sum_pos = 0;
		for (int i = pos; i >= 0; i = f(i) - 1)
		{
			sum_pos += S(i);
		}
		return sum_pos - sum_start;
	}

	void FenwickTree::Update(int pos, int value)
	{
		for (int i = pos; i < size; i = g(i))
		{
			array[i] += value;
		}
	}