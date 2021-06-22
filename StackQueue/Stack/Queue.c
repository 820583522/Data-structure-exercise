#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}


void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL; 
}

void QueuePush(Queue* pq, QDateType x)
{
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
QDateType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->head->data;
}
QDateType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->tail->data;
}
bool QueueEmpty(Queue*pq)
{
	assert(pq);
	return pq->head == NULL;
}
int QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}