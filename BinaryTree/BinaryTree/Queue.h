#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDateType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDateType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDateType x);
void QueuePop(Queue* pq);
QDateType QueueFront(Queue* pq);
QDateType QueueBack(Queue* pq);
bool QueueEmpty(Queue*pq);
int QueueSize(Queue* pq);