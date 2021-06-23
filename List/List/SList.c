#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//�����±�
SListNode* BuySListNode(SListDataType x)
{
	SListNode* pList = (SListNode*)malloc(sizeof(SListNode));
	if (pList == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	pList->date = x;
	pList->next = NULL;
	return pList;
}

//β��
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
			printf("�����ڴ�ʧ��\n");
			exit(-1);
		}
		newNode->date = x;
		newNode->next = NULL;
		tail->next = newNode;
	}

}

//βɾ
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
//�ײ�
void SListPushFront(SListNode** ppList, SListDataType x)

//��ʦ�ķ���
{
	SListNode* NewNode = BuySListNode(x);
	NewNode->next = *ppList;
	*ppList = NewNode;
}

//�ҵķ���
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
//��ɾ
void SListPopFront(SListNode** ppList)
{
	if (*ppList == NULL)
	{
		return;
	}
	else if ((*ppList)->next == NULL)   //ֻ��һ���ڵ�����������������Ͻڵ���Ժ�Ϊһֱ���
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
//����
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
		printf("������Ϊ��\n");
	}
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d  ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}