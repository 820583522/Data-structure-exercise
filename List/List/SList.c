#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//创建新表
SListNode* BuySListNode(SListDataType x)
{
	SListNode* pList = (SListNode*)malloc(sizeof(SListNode));
	if (pList == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	pList->date = x;
	pList->next = NULL;
	return pList;
}

//尾插
void SListPushBack(SListNode** ppList, SListDataType x)

{
	if (*ppList == NULL)
	{
		*ppList = BuySListNode(x);
	}
	else
	{
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
		if (newNode == NULL)
		{
			printf("申请内存失败\n");
			exit(-1);
		}
		newNode->date = x;
		newNode->next = NULL;
		tail->next = newNode;
	}

}

//尾删
void SListPopBack(SListNode** ppList)
{
	if (*ppList == NULL)
	{
		return;
	}
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *ppList;
		while ((tail)->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
//首插
void SListPushFront(SListNode** ppList, SListDataType x)

//老师的方法
{
	SListNode* NewNode = BuySListNode(x);
	NewNode->next = *ppList;
	*ppList = NewNode;
}

//我的方法
//{
//	if(*ppList == NULL)
//	{
//		SListNode* newNode = BuySListNode(x);
//		*ppList = newNode;
//	}
//	else
//	{
//		SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
//		newNode->date = x;
//		newNode->next = *ppList;
//		*ppList = newNode;
//	}
//}
//首删
void SListPopFront(SListNode** ppList)
{
	if (*ppList == NULL)
	{
		return;
	}
	else if ((*ppList)->next == NULL)   //只有一个节点和有两个或两个以上节点可以合为一直情况
	{
		free(*ppList);
		*ppList = NULL;
	}
	else
	{
		
		SListNode* phead = *ppList;
		*ppList = (*ppList)->next;
		free(phead);
	}
}
//查找
SListNode* SListFind(SListNode* pList, SListDataType x)
{
	SListNode* cur = pList;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListPrint(SListNode* pList)
{
	if (!pList)
	{
		printf("该链表为空\n");
	}
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d  ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}