#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
typedef int SListDataType;
//½áµã
typedef struct SListNode
{
	SListDataType date;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** ppList, SListDataType x);
void SListPopBack(SListNode** ppList);
void SListPushFront(SListNode** ppList, SListDataType x);
void SListPopFront(SListNode** ppList);
void SListPrint(SListNode* pList);
SListNode* BuySListNode(SListDataType x);