#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead->prev = phead;
	return phead;
}
void ListDestory(LTNode** pphead)
{

}

LTNode* BuyListNode(LTDateType x)
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;
	newNode->next = newNode->prev = NULL;
	return newNode;
}
void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* newNode = BuyListNode(x);

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	LTNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
}

bool ListEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}
size_t ListSize(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	int n = 0;
	while (cur != phead)
	{
		++n;
		cur = cur->next;
	}
	return n;
}

void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newNode = BuyListNode(x);
	newNode->next = phead->next;
	phead->next->prev = newNode;
	phead->next = newNode;
	newNode->prev = phead;
}
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	LTNode* FirstNode = phead->next;
	phead->next = FirstNode->next;
	FirstNode->next->prev = phead;
	free(FirstNode);
}
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* newNode = BuyListNode(x);
	LTNode* prev = pos->prev;
	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = pos;
	pos->prev = newNode;
}
void ListErase(LTNode* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}