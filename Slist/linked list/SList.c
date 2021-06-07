#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//´´½¨ÐÂ±í
SListNode* BuySListNode(SListDataType x)
{
	SListNode* pList = (SListNode*)malloc(sizeof(SListNode));
	if (pList == NULL)
	{
		printf("ÉêÇëÄÚ´æÊ§°Ü\n");
		exit(-1);
	}
	pList->date = x;
	pList->next = NULL;
	return pList;
}

//Î²²å
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
			printf("ÉêÇëÄÚ´æÊ§°Ü\n");
			exit(-1);
		}
		newNode->date = x;
		newNode->next = NULL;
		tail->next = newNode;
	}

}

//Î²É¾
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
//Ê×²å
void SListPushFront(SListNode** ppList, SListDataType x)
{
	if(*ppList == NULL)
	{
		SListNode* newNode = BuySListNode(x);
		*ppList = newNode;
	}
	else
	{
		SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
		newNode->date = x;
		newNode->next = *ppList;
		*ppList = newNode;
	}
}
//Ê×É¾
void SListPopFront(SListNode** ppList)
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
		
		SListNode* phead = *ppList;
		*ppList = (*ppList)->next;
		free(phead);
		phead->next = NULL;
	}
}

void SListPrint(SListNode* pList)
{
	if (!pList)
	{
		printf("¸ÃÁ´±íÎª¿Õ\n");
	}
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d  ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}