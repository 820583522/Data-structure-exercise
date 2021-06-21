#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
#include "DList.h"
void test1()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 7);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPushFront(&pList, 0);
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPrint(pList);
	SListNode* pos = SListFind(pList, 1);
	pos->date = 3;
	SListPrint(pList);
}
	
void test2()
{
	ListNode* phead = ListInit(0);
	ListPushBack(phead,1);
	ListPushBack(phead,2);
	ListPushBack(phead,3);
	ListPushBack(phead,4);	
	ListPushFront(phead, 0);
	ListPushFront(phead, -1);
	ListPushFront(phead, -2);
	ListPushFront(phead, -3);
	ListPopBack(phead);
	ListPopFront(phead);
	

	ListPrint(phead);
	
	return;
}
int main()
{
	//test1();
	test2();
	return 0;
}