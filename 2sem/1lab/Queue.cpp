#include "pch.h" ﻿
#include "queue.h"
using namespace std;


void enq(queue * q, int x, int MAXN)
{
	q->val[(q->qt++) % MAXN] = x;
}

int deq(queue * q,int MAXN)
{
	return q->val[(q->qh++) % MAXN];
}