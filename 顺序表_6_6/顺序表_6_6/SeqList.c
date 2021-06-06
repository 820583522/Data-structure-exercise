#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->size = 0;
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	if (ps->a == NULL)
	{
		printf("ÉêÇëÄÚ´æÊ§°Ü\n");
		exit(-1);
	} 
	ps->capacity = 4;
}

//Î²²å
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
//´òÓ¡
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//Î²É¾
void SeqListPopBack(struct SeqList* ps)
{
	assert(ps);
	ps->size--;
	ps->a[ps->size] = 0;
	
}
//Ê×²å
void SeqListPushFront(struct SeqList* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	int count = ps->size;
	while (count--)
	{
		ps->a[count+1] = ps->a[count];
	}
	ps->a[0] = x;
	ps->size++;
}
//Ê×É¾
void SeqListPopFront(struct SeqList* ps)
{
	assert(ps);
	int start = 0;
	while (start<ps->size-1)
	{
		ps->a[start] = ps->a[start+1];
		start++;
	}
	ps->size--;
}

//ÖÐ¼ä²åÈë
void SeqListInsert(struct SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int count = ps->size - pos + 1;
	while (count--)
	{
		ps->a[count + pos] = ps->a[count + pos-1];
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

void SeqListErase(struct SeqList* ps, int pos)
{
	assert(ps);
	while (pos<ps->size)
	{
		ps->a[pos - 1] = ps->a[pos];
		pos++;
	}
	ps->size--;
}
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);

	}
}