#pragma once

#ifdef QUEUE_EXPORTS
#define QUEUE_API __declspec(dllexport)
#else
#define QUEUE_API __declspec(dllimport)
#endif


#include <iostream>
#include <cmath>
#include <fstream>
#include <string>


struct queue
{
	int qh, qt;
	int val[];
} ;


extern "C" QUEUE_API void enq (queue * q, int x, int MAXN);
extern "C" QUEUE_API int deq (queue * q, int MAXN);