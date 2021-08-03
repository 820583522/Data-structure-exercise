#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int LTDateType;
typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* ListInit();
void ListDestory(LTNode** pphead);
LTNode* BuyListNode(LTDateType x);
void ListPushBack(LTNode* phead, LTDateType x);
void ListPrint(LTNode* phead);
void ListPopBack(LTNode* phead);

bool ListEmpty(LTNode* phead);
size_t ListSize(LTNode* phead);

void ListPushFront(LTNode* phead, LTDateType x);
void ListPopFront(LTNode* phead);
void ListInsert(LTNode* pos,LTDateType x);
void ListErase(LTNode* phead);
LTNode* ListFind(LTNode* phead, LTDateType x);