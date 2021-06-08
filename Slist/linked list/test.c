#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
int main()
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
	SListPushFront(&pList,0);
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPrint(pList); 
	SListNode* pos= SListFind(pList, 1);
	pos->date =3;
	SListPrint(pList);

	return 0;
}