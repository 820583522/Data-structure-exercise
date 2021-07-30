#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define SLDateType int

typedef struct SeqList
{
	SLDateType data;
	struct SeqList* next;
}SList;

//�����ʼ��
void SListIint(SList** pphead);
//��������
void SListDestory(SList** phead);
//�����ӡ
void SListPrint(SList** phead);


//����һ���½ڵ�
SList* BuySListNode(SLDateType x);
//����β��
void SListPushBack(SList** pphead,SLDateType x);
//����ͷ��
void SListPushFront(SList** pphead, SLDateType x);
//����βɾ
void SListPopBack(SList** pphead);
//����ͷɾ
void SListPopFront(SList** pphead);
//�������ݸ���
size_t SListSize(SList** pphead);
//����������ֵΪval�Ľ��
SList* SListFind(SList** pphead, SLDateType x);
//�����п�
bool SListEmpty(SList** pphead); 
//ɾ��pos���һ�����
void SListEraseAfter(SList* pos);
//ɾ��pos����һ�����
void SListErase(SList** pphead,SList* pos);
//��pos������һ�����
void SListInsert(SList** pphead, SList* pos,SLDateType x);
//��pos�����һ�����
void SListInsertAfter(SList* pos, SLDateType x);
