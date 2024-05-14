#pragma once
#include <iostream>
using namespace std;
struct node 
{
	int info;
	node* next;
};
void NodeSorting(node* begin)
{
	node* t = begin;  
	bool proof = false;
	while (!proof)
	{
		proof = true;
		while (t->next != nullptr)
		{
			if (t->info > t->next->info)
			{
				int buff;
				buff = t->info;
				t->info = t->next->info;
				t->next->info = buff;
				proof = false;
			}
			t = t->next;
		}
		t = begin;
	}
}
node* SearchNodeInfo(node* begin, int search)
{
	node* t = begin;
	while (t != nullptr)
	{
		if (t->info == search)
		{
			return t;
		}
		t = t->next;
	}
	return nullptr;
}
void DeleteNode(node** begin, node* del)
{
	if (del != nullptr)
	{
		if (del == *begin)
		{
			*begin = del->next;
			delete del;
		}
		else
		{
			node* t = *begin;
			while (t->next != del)
			{
				t = t->next;
			}
			t->next = del->next;
			delete del;
		}
	}
}
void AddNode(node* begin, int add)
{
	while (cin.fail() || SearchNodeInfo(begin, add) != nullptr)
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "ОШИБКА. Введите другое число" << endl;
		cin >> add;
	}
	node* a = new node;
	node* t = begin;
	while (t->next != nullptr)
	{
		t = t->next;
	}
	t->next = a;
	a->info = add;
	a->next = nullptr;
}
node* Unification(node* a, node* b)
{
	node* c = new node;
	node* ta = a;
	node* tc = c;
	while (ta->next != nullptr)
	{
		node* r = new node;
		tc->info = ta->info;
		tc->next = r;
		r->next = nullptr;
		ta = ta->next;
		tc = tc->next;
	}
	tc->info = ta->info;
	node* tb = b;
	while (tb != nullptr)
	{
		if (SearchNodeInfo(c, tb->info) != nullptr)
		{
			tb = tb->next;
		}
		else
		{
			AddNode(c, tb->info);
			tb = tb->next;
		}
	}
	return c;
}
node* Intersection(node* a, node* b) {
	node* ta = a;
	node* tb = b;
	node* HeadC = nullptr;
	node* TailC = nullptr;
	while (ta != nullptr) {
		while (tb != nullptr) {
			if (ta->info == tb->info) {
				node* c = new node;
				c->info = ta->info;
				c->next = nullptr;
				if (HeadC == nullptr) {
					HeadC = c;
					TailC = c;
				}
				else {
					TailC->next = c;
					TailC = c;
				}
				break;
			}
			tb = tb->next;
		}
		ta = ta->next;
		tb = b;
	}
	return HeadC;
}