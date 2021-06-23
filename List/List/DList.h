#include<stdio.h>
#pragma once
#include<assert.h>
#include<malloc.h>
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType date;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;


ListNode* BuyListNode(LTDateType x);
ListNode* ListInit(LTDateType x);
void ListPushBack(ListNode* phead, LTDateType x);
void ListPushFront(ListNode* phead, LTDateType x);
void ListPrint(ListNode* phead);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead,LTDateType x);
void ListInsert(ListNode* pos, LTDateType x);
void Listerase(ListNode* pos);