#define _CRT_SECURE_NO_WARNINGS 1

#include"DList.h"
ListNode* BuyListNode(LTDateType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->date = x;
	return node;
}

ListNode* ListInit(LTDateType x)
{
	ListNode* phead = BuyListNode(x);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListPushBack(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListInsert(phead->prev, x);
	//assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* newNode = BuyListNode(x);
	//tail->next = newNode;
	//newNode->prev = tail;
	//newNode->next = phead;
	//phead->prev = newNode;
	return;
}

void ListPushFront(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListInsert(phead, x);
	/*assert(phead);
	ListNode* newNode = BuyListNode(x);
	newNode->next = phead->next;
	phead->next = newNode;
	newNode->prev = phead;
	newNode->next->prev = newNode;*/
	
	return;
}

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	for (; cur != phead; cur = cur->next)
	{
		printf("%d  ", cur->date);
	}
	printf("\n");
	return;
}


void ListPopBack(ListNode* phead)
{
	assert(phead);
	if (phead->next == phead)
	{
		return;
	}
	//ListNode* tail = phead->prev;
	//tail->prev->next = phead;
	//phead->prev = tail->prev;
	//free(tail);
	Listerase(phead->prev);
	return;
}
void ListPopFront(ListNode* phead)
{
	assert(phead);
	if (phead->next == phead)
	{
		return;
	}
	Listerase(phead->next);
	/*ListNode* first = phead->next;
	phead->next = first->next;
	first->next->prev = phead;
	free(first);*/
	return;
}

ListNode* ListFind(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (phead != cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void ListInsert(ListNode* pos, LTDateType x)
{
	assert(pos);
	ListNode* newNode = BuyListNode(x);
	ListNode* next = pos->next;
	newNode->next = next;
	newNode->prev = pos;
	pos->next = newNode;
	next->prev = newNode;
	return;
}

void Listerase(ListNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	return;
}
