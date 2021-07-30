#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void test1()
{
	//测Init、Destory、PushBack、PopBack、PushFront、PopFront和Print

	SList s;
	SList* phead = &s;
	SListIint(&phead);
	SListPushBack(&phead, 0);
	SListPrint(&phead);

	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3); 
	SListPrint(&phead);

	SListPopBack(&phead);
	SListPrint(&phead);

	SListPushFront(&phead, -1);
	SListPushFront(&phead, -2);
	SListPushFront(&phead, -3);
	SListPushFront(&phead, -4);
	SListPrint(&phead);

	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPrint(&phead);
	
	SListDestory(&phead);
	
}

void test2()
{
	//测Empty、Size、
	SList s;
	SList* phead;
	SListIint(&phead);
	printf("SListEmpty: %d\n", SListEmpty(&phead));
	SListPushBack(&phead, 0);
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	printf("SListEmpty: %d\n", SListEmpty(&phead));
	printf("SListSize: %d\n", SListSize(&phead));
}

void test3()
{
	//测Find、EraseAfter、InsertAfter
	SList s;
	SList* phead;
	SListIint(&phead);
	SListPushBack(&phead, 0);
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);

	SList* pos = SListFind(&phead, -1);
	if (pos)
	{
		printf("-1的地址：%p\n", pos);
	}

	pos = SListFind(&phead, 0);
	if (pos)
	{
		printf("0的地址：%p\n", pos);
	}
	SListInsertAfter(pos, 10);
	SListPrint(&phead);
	SListEraseAfter(pos);
	SListPrint(&phead);

	SListInsertAfter(pos, 5);
	SListPrint(&phead);
	pos = SListFind(&phead, 2);
	if (pos)
	{
		printf("2的地址：%p\n", pos);
	}
	SListEraseAfter(pos);
	SListPrint(&phead);
	
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}