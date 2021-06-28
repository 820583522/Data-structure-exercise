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

//用两个队列实现栈，先进后出；
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



//用两个栈实现队列，先进先出；
typedef struct
{
	Stack PushSt;
	Stack PopSt;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->PushSt);
	StackInit(&q->PopSt);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->PushSt, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->PopSt))
	{
		while (!StackEmpty(&obj->PushSt))
		{
			StackPush(&obj->PopSt, StackTop(&obj->PushSt));
			StackPop(&obj->PushSt);
		}
	}
	int top = StackTop(&obj->PopSt);
	StackPop(&obj->PopSt);
	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->PopSt))
	{
		while (!StackEmpty(&obj->PushSt))
		{
			StackPush(&obj->PopSt, StackTop(&obj->PushSt));
			StackPop(&obj->PushSt);
		}
	}
	return StackTop(&obj->PopSt);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->PopSt) && StackEmpty(&obj->PushSt);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->PopSt);
	StackDestroy(&obj->PushSt);
	free(obj);
}


//设计循环队列
typedef struct
{
	int* date;
	int k;
	int front;
	int tail;
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->date = (int*)malloc(sizeof(int)*(k + 1));
	cq->k = k;
	cq->front = 0;
	cq->tail = 0;
	return cq;
}
//插入
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	else
	{
		obj->date[obj->tail] = value;
		obj->tail++;
		if (obj->tail == obj->k + 1)
		{
			obj->tail = 0;
		}
		return true;
	}
}
//删除
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	else
	{
		obj->front++;
		if (obj->front == obj->k + 1)
		{
			obj->front = 0;
		}
		return true;
	}
}
//队首数据
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		return obj->date[obj->front];
	}
}
//队尾数据
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		int tailPrev = obj->tail - 1;
		if (obj->tail == 0)
		{
			tailPrev = obj->k;
			return obj->date[tailPrev];
		}
		return obj->date[tailPrev];
	}
}
//判空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->tail;
}
//判满
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	int tailNext = obj->tail + 1;
	if (tailNext == obj->k + 1)
	{
		tailNext = 0;
	}
	return tailNext == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->date);
	free(obj);
}