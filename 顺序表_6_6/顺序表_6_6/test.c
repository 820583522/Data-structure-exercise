
#include "SeqList.h"

void TestSeqList1()
{
	struct SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPushFront(&s, 11);
	SeqListPushFront(&s, 12);
	SeqListPushFront(&s, 13);
	SeqListPushFront(&s, 14);
	SeqListPushFront(&s, 15);
	SeqListPushFront(&s, 16);
	SeqListPushFront(&s, 17);
	SeqListPushFront(&s, 18);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 20);
	SeqListPrint(&s);
	SeqListErase(&s, 2);
	SeqListPrint(&s);
	int pos = SeqListFind(&s, 30);
	printf("%d\n", pos);
	
	SeqListDestory(&s);
}

int main()
{
	TestSeqList1();
	return 0;
}