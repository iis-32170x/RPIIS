#pragma once
struct MyQueue 
{
	int info;
	MyQueue* next, *prev;
};


void InQueue(MyQueue**, MyQueue**, int in);
int OutQueue(MyQueue**);
void Del_All(MyQueue**);
void View(MyQueue*);
void Sort_info(MyQueue*);
bool EmptinessCheck(MyQueue*);
int Random(int);


class MyQueueWithPriority
{
	MyQueue* beginQ, * endQ;

public:
	MyQueueWithPriority();
	~MyQueueWithPriority();

	void AddToQueue(int);
	int GetFromQueue();
	void ViewQueue();
	void DeleteQueue();
	bool empty = EmptinessCheck(endQ);
};

