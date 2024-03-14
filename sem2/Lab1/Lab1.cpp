#include <iostream>
#include "MyQueue.h"
#include <fstream>
#include <string>
using namespace std;


int main()
{
	MyQueueWithPriority<string> qu;
	ifstream fl;
	fl.open("example.txt");
	
	for (int i = 0; i < 5; i++)
	{
		string name;
		int prio;
		fl >> name;
		fl >> prio;
		qu.AddToQueue(name, prio);

	}
	fl.close();


	qu.ViewQueue();
	cout << endl;


	string ab = qu.GetFromQueue();
	cout << ab << endl;

	qu.ViewQueue();
	cout << endl;

	qu.DeleteQueue();

	if (qu.isEmpty())
		cout << "Queue is empty";
	else
		qu.ViewQueue();

	return 0;
}
