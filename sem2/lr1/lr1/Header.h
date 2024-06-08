#pragma once
#include <iostream>

using namespace std;

struct Stack
{
	int info;
	Stack* next;
} *Vertex;


/*int Random(int num)
{
	int multiplier;

	srand(time(nullptr) + num);

	if (rand() % 2 == 0)
		multiplier = 1;
	else
		multiplier = -1;

	return (rand() % 100) * multiplier;
}*/

void InStack(Stack** p, int in)
{
	Stack* t = new Stack;
	t->info = in;
	t->next = *p;
	*p = t;
}

void View(Stack* p)
{
	Stack* t = p;
	while (t != NULL)
	{
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}
int OutStack(Stack** p)
{
	Stack* t = *p;
	int out;
	out = (*p)->info;
	*p = (*p)->next;
	delete t;
	return out;
}
