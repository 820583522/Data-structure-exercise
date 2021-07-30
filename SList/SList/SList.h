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

//链表初始化
void SListIint(SList** pphead);
//链表销毁
void SListDestory(SList** phead);
//链表打印
void SListPrint(SList** phead);


//创建一个新节点
SList* BuySListNode(SLDateType x);
//链表尾插
void SListPushBack(SList** pphead,SLDateType x);
//链表头插
void SListPushFront(SList** pphead, SLDateType x);
//链表尾删
void SListPopBack(SList** pphead);
//链表头删
void SListPopFront(SList** pphead);
//链表数据个数
size_t SListSize(SList** pphead);
//查找链表中值为val的结点
SList* SListFind(SList** pphead, SLDateType x);
//链表判空
bool SListEmpty(SList** pphead); 
//删除pos后的一个结点
void SListEraseAfter(SList* pos);
//删除pos处的一个结点
void SListErase(SList** pphead,SList* pos);
//在pos处插入一个结点
void SListInsert(SList** pphead, SList* pos,SLDateType x);
//在pos后插入一个结点
void SListInsertAfter(SList* pos, SLDateType x);
