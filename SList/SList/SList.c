#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//链表初始化
void SListIint(SList** pphead)
{
	assert(pphead);
	(*pphead) = NULL;
}
//链表销毁
void SListDestory(SList** pphead)
{
	assert(pphead);
	SList* cur = *pphead;
	SList* prev = cur;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	*pphead = NULL;
}
//链表打印
void SListPrint(SList** pphead)
{
	assert(pphead);
	SList* cur = *pphead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

SList* BuySListNode(SLDateType x)
{
	SList* newNode = (SList*)malloc(sizeof(SList));
	if (newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newNode->next = NULL;
	newNode->data = x;
	return newNode;
}

//链表尾插
void SListPushBack(SList** pphead,SLDateType x)
{
	assert(pphead);
	if ((*pphead) == NULL)
	{
		SList* newNode = BuySListNode(x);
		*pphead = newNode;
	}
	else
	{
		SList* tail = *pphead;
		while (tail->next!=NULL)
		{
			tail = tail->next;
		}
		SList* newNode=BuySListNode(x);
		tail->next= newNode;
	}
}

void SListPushFront(SList** pphead, SLDateType x)
{
	assert(pphead);
	SList* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		newNode->next = *pphead;
		*pphead = newNode;
	}
}

void SListPopBack(SList** pphead)
{
	assert(pphead);
	assert(!SListEmpty(pphead));

	//只有一个结点时
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//有多个结点时
	else
	{
		SList* tail = *pphead;
		SList* prev= NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SListPopFront(SList** pphead)
{
	assert(pphead);
	assert(!SListEmpty(pphead));


	SList* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

void SListErase(SList** pphead,SList* pos)
{
	assert(pphead);
	assert(!SListEmpty(pphead));
	assert(pos);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SList* prev = *pphead;
		if (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void SListInsert(SList** pphead, SList* pos, SLDateType x)
{
	assert(pphead);
	//头插
	if (*pphead == pos)
		SListPushFront(pphead, x);
	//中间插入
	else
	{
		SList* prev = *pphead;
		while (prev&&prev->next != pos)
		{
			prev = prev->next;
		}
		SList* newNode = BuySListNode(x);
		newNode->next = pos;
		prev->next = newNode;
	}
}

void SListInsertAfter(SList* pos, SLDateType x)
{
	assert(pos);
	
	SList* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
	
}
void SListEraseAfter(SList* pos)
{
	assert(pos&&pos->next);
	SList* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

size_t SListSize(SList** pphead)
{
	assert(pphead);
	size_t size = 0;
	SList* cur = *pphead;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
SList* SListFind(SList** pphead, SLDateType x)
{
	assert(pphead);
	SList* pos = *pphead;
	while (pos)
	{
		if (pos->data == x)
			return pos;
		else
			pos = pos->next;
	}
	return NULL;
}

bool SListEmpty(SList** pphead)
{
	return *pphead == NULL;
}

