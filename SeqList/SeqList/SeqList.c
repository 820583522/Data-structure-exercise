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
	for (size_t i = 0; i < ps->size; i++)
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
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos <= ps->size);
	SeqListCapacityCheck(ps);
	size_t end;
	for (end = ps->size; end > pos; end--)
	{
		ps->a[end] = ps->a[end-1];
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos < ps->size);
	for (size_t begin = pos+1; begin < ps->size; begin++)
	{
		ps->a[begin-1]=ps->a[begin];
	}
	ps->size--;
}


void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size);
	SeqListErase(ps, 0);
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size);
	SeqListErase(ps, ps->size - 1);
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	size_t pos = 0;
	while (pos < ps->size)
	{
		if (ps->a[pos] == x)
			return pos;
		else
			pos++;
	}
	return -1;
}

int SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->size;
}

void SeqListAt(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos < ps->size);
	ps->a[pos] = x;
}