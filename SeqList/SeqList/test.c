#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void test()
{
	SeqList s;
	SeqListInit(&s);
	
	SeqListInsert(&s, 0, 0);
	SeqListInsert(&s, 1, 1);
	SeqListInsert(&s, 2, 2);
	SeqListInsert(&s, 3, 3);
	SeqListInsert(&s, 4, 4);
	SeqListPrint(&s);
	SeqListErase(&s, 4);
	SeqListPrint(&s);
	SeqListErase(&s, 1);
	SeqListErase(&s, 0);


	SeqListPrint(&s);

	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPrint(&s);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SLDateType x = 7;
	int pos = SeqListFind(&s, 7);
	if (pos >= 0)
		printf("找到了，%d的下标:%d\n",x, pos);
	else
		printf("顺序表中没有%d\n", x);
	x = 6;
	pos = SeqListFind(&s, 6);
	if (pos >= 0)
		printf("找到了，%d的下标:%d\n", x, pos);
	else
		printf("顺序表中没有%d\n", x);
	SeqListDestory(&s);
}
int main()
{
	test();
}