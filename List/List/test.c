#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void TestList1()
{
	LTNode* pList = ListInit();
	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPushBack(pList, 4);
	ListPrint(pList);
	ListPopBack(pList);
	ListPrint(pList);
	ListPopBack(pList);
	ListPrint(pList);	
	ListPushFront(pList, 10);
	ListPushFront(pList, 20);
	ListPushFront(pList, 30);
	ListPrint(pList);
	ListPopFront(pList);
	ListPrint(pList);
	ListPopFront(pList);
	ListPrint(pList);
	LTNode* pos = ListFind(pList, 10);
	ListInsert(pos, 20);
	ListPrint(pList);
	ListErase(pos);
	ListPrint(pList);
}


int main()
{
	TestList1();

	return 0;
}