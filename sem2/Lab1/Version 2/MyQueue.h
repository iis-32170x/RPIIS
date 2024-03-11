#pragma once
template<typename T>
struct MyQueue
{
	int prio;
	T info;
	MyQueue* next, *prev;
};



template<typename T> void InQueue(MyQueue<T>**, MyQueue<T>**, T, int);
template<typename T> T OutQueue(MyQueue<T>**);
template<typename T> void Del_All(MyQueue<T>**);
template<typename T> void View(MyQueue<T>*);
template<typename T> void Sort(MyQueue<T>*);
template<typename T> bool EmptinessCheck(MyQueue<T>*);
int Random(int);



template<typename T> void InQueue(MyQueue<T>** b, MyQueue<T>** e, T in, int prio)
{
	MyQueue<T>* t = new MyQueue<T>;
	t->info = in;
	t->prio = prio;
	t->next = t->prev = NULL;
	if (*b == NULL)
		*b = *e = t;
	else {
		t->prev = NULL;
		t->next = *b;
		(*b)->prev = t;
		*b = t;
	}
}

template<typename T> T OutQueue(MyQueue<T>** p)
{
	MyQueue<T>* t = *p;
	T out;
	out = (*p)->info;
	*p = (*p)->prev;
	delete t;
	return out;
}


template<typename T> void Del_All(MyQueue<T>** p)
{
	MyQueue<T>* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->prev;
		delete t;
	}
}
template<typename T> void View(MyQueue<T>* p)
{
	MyQueue<T>* t = p;
	while (t != NULL) {
		std::cout << t->info << " ";
		t = t->prev;
	}
}

template<typename T> void Sort(MyQueue<T>* p)
{
	MyQueue<T>* t = NULL, * t1;
	T buf_info;
	int buf_prio;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
		{
			if (t1->prio > t1->next->prio) 
			{
				buf_info = t1->info;
				buf_prio = t1->prio;
				t1->info = t1->next->info;
				t1->prio = t1->next->prio;
				t1->next->info = buf_info;
				t1->next->prio = buf_prio;
			}
		}
		t = t1;
	} while (p->next != t);
}

template<typename T> bool EmptinessCheck(MyQueue<T>* endQ)
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

template<typename T>
class MyQueueWithPriority
{
	MyQueue<T>* beginQ, * endQ;

public:
	MyQueueWithPriority()
	{
		beginQ = NULL;
		endQ = NULL;
	}
	~MyQueueWithPriority()
	{
		Del_All(&endQ);
	}

	void AddToQueue(T in, int prio)
	{
		InQueue(&beginQ, &endQ, in, prio);
		if (beginQ->next != NULL)
			Sort(beginQ);
	}
	T  GetFromQueue()
	{
		return OutQueue(&endQ);
	}
	void ViewQueue()
	{
		View(endQ);
	}
	void DeleteQueue()
	{
		Del_All(&endQ);
	}
	bool empty = EmptinessCheck(endQ);
};

