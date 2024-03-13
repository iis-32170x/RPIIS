#pragma once
#include <iostream>
using namespace std;
int parent[100]{};

void make_set(int v)
{
	if (v < 100)
		parent[v] = v;
	else
		cout << "\nЧисло:" << v <<" слишком большое";
}

int find_set(int v) {
	if (v == parent[v])
		return v;
	return find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != 0 && b != 0)
	{
		if (a != b)
			parent[b] = a;
	}
	else cout << "Один из элементов отсутствует(не создано множество с ним)\n";
	
}