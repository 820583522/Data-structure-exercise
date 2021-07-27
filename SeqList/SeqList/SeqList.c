#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = (SLDateType*)malloc(CapaticyDef*sizeof(SLDateType));
	ps->size = 0;
	ps->capacity = 2;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d  ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->capacity = ps->size = 0;
}

void SeqListCapacityCheck(SeqList* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		//若顺序表满了，则让容量翻倍
		ps->a = (SLDateType*)realloc(ps->a,ps->capacity * 2 * sizeof(SLDateType));
		ps->capacity *= 2;
	}
}
//pos是插入的下标
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	SeqListCapacityCheck(ps);
	int end;
	for (end = ps->size - 1; end >= pos; end--)
	{
		ps->a[end + 1] = ps->a[end];
	}
	ps->a[end+1] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	for (int i = pos; i < ps->size; i++)
	{
		ps->a[i]=ps->a[i + 1];
	}
	ps->size--;
}


void SeqListPushBack(SeqList* ps, SLDateType x)
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SeqList* ps)
{
	SeqListErase(ps, 0);
}
void SeqListPopBack(SeqList* ps)
{
	SeqListErase(ps, ps->size - 1);
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	int pos = 0;
	while (pos < ps->size)
	{
		if (ps->a[pos] == x)
			return pos;
		else
			pos++;
	}
	return -1;
}