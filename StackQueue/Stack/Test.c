#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

#include"Queue.h"

void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st))
	{
		printf("%d  ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
	StackDestroy(&st);
}


TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q))
	{
		printf("%d  ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}


int main()
{
	TestStack();
	TestQueue();
	return 0;
}
typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	if (!QueueEmpty(&obj->q1))
	{
		while (QueueSize(&obj->q1) >1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}
		int ret = QueueFront(&obj->q1);
		QueuePop(&obj->q1);
		return ret;
	}
	else
	{
		while (QueueSize(&obj->q2) > 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		int ret = QueueFront(&obj->q2);
		QueuePop(&obj->q2);
		return ret;
	}
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		while (QueueSize(&obj->q1) != 1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}
		int ret = QueueFront(&obj->q1);
		QueuePush(&obj->q2, QueueFront(&obj->q1));
		QueuePop(&obj->q1);
		return ret;
	}
	else
	{
		while (QueueSize(&obj->q2) != 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		int ret = QueueFront(&obj->q2);
		QueuePush(&obj->q1, QueueFront(&obj->q2));
		QueuePop(&obj->q2);
		return ret;
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && (QueueEmpty(&obj->q2));
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}