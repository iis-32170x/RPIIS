#include <iostream>
#include "MyQueue.h"
#include <fstream>
using namespace std;


int main()
{
	
	MyQueueWithPriority qu;
	int justVar;
	ifstream testFile;

	testFile.open("example.txt");
	for (int i = 0; i < 5; i++)
	{
		testFile >> justVar;
		qu.AddToQueue(justVar);
	}
	testFile.close();

	qu.ViewQueue();


	justVar = qu.GetFromQueue();
	cout << endl << justVar << endl;
	qu.ViewQueue();
	
	qu.DeleteQueue();

	cout << endl;

	if (qu.empty == false)
	{
		qu.ViewQueue();
	}
	else
		cout << "Queue is empty";
	

	return 0;
}
