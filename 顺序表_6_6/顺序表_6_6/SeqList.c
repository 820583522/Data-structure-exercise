#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->size = 0;
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	} 
	ps->capacity = 4;
}

//尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	//assert(ps);
	//SeqListCheckCapacity(ps);
	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size+1, x);
}
//打印
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//尾删
void SeqListPopBack(struct SeqList* ps)
{
	//assert(ps);
	//ps->size--;
	//ps->a[ps->size] = 0;
	SeqListErase(ps, ps->size);
}
//首插
void SeqListPushFront(struct SeqList* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);
	//int count = ps->size;
	//while (count--)
	//{
	//	ps->a[count+1] = ps->a[count];
	//}
	//ps->a[0] = x;
	//ps->size++;
	SeqListInsert(ps, 1, x);
}
//首删
void SeqListPopFront(struct SeqList* ps)
{
	//assert(ps);
	//int start = 0;
	//while (start<ps->size-1)
	//{
	//	ps->a[start] = ps->a[start+1];
	//	start++;
	//}
	//ps->size--;
	SeqListErase(ps, 1);
}

//中间插入
void SeqListInsert(struct SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size+1&&pos > 0);
	SeqListCheckCapacity(ps);
	int count = ps->size - pos + 1;
	while (count--)
	{
		ps->a[count + pos] = ps->a[count + pos-1];
	}
	ps->a[pos - 1] = x;
	ps->size++;
}
//任意位置删除
void SeqListErase(struct SeqList* ps, int pos)
{
	assert(ps);
	assert(pos <= ps->size&&pos > 0);
	while (pos<ps->size)
	{
		ps->a[pos - 1] = ps->a[pos];
		pos++;
	}
	ps->size--;
}

//检查容量
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);

	}
}
//查找
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i+1;
		}
	}
	return -1;
}
//销毁
void SeqListDestory(SL* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}