#include <iostream>
#include "MyQueue.h"


void InQueue(MyQueue** b, MyQueue** e, int in)
{ 
	MyQueue* t = new MyQueue;
	t->info = in; 
	t->next =t->prev= NULL;
	if (*b == NULL) 
		*b = *e = t;
	else {
		t->prev = NULL; 
		t->next = *b; 
		(*b)->prev = t;
		*b = t; 
	}
}

int OutQueue(MyQueue** p)
{
	MyQueue* t = *p;
	int out;
	out = (*p)->info;
	*p = (*p)->prev; 
	delete t; 
	return out; 
}


void Del_All(MyQueue** p)
{
	MyQueue* t;
		while (*p != NULL) {
			t = *p;
			*p = (*p)->prev;
			delete t;
		}
}
void View(MyQueue* p) 
{
	MyQueue* t = p;
	while (t != NULL) {
		std::cout << t->info << " ";
		t = t->prev;
	}
}

void Sort_info(MyQueue* p) 
{
	MyQueue* t = NULL, * t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}


bool EmptinessCheck(MyQueue* endQ)
{
	if (endQ == NULL)
		return true;
	else
		return false;
}


int Random(int num)
{
	int multiplier;

	srand(time(nullptr) + num);

	if (rand() % 2 == 0)
		multiplier = 1;
	else
		multiplier = -1;

	return (rand() % 100) * multiplier;

}



MyQueueWithPriority::MyQueueWithPriority()
{
	beginQ = NULL;
	endQ = NULL;
}
MyQueueWithPriority::~MyQueueWithPriority()
{
	Del_All(&endQ);
}
void MyQueueWithPriority::AddToQueue(int in)
{
	InQueue(&beginQ, &endQ, in);
	if(beginQ->next != NULL)
		Sort_info(beginQ);
}
int MyQueueWithPriority::GetFromQueue()
{
	return OutQueue(&endQ);
}
void MyQueueWithPriority::ViewQueue()
{
	View(endQ);
}
void MyQueueWithPriority::DeleteQueue()
{
	Del_All(&endQ);
}
