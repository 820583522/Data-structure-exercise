#pragma once
typedef int SLDataType;
typedef struct SeqList SL;
#define N 10
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
};
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListCheckCapacity(SL* ps);
void SeqListPopFront(SL* ps);
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
int SeqListFind(SL* ps, SLDataType x);
void SeqListDestory(SL* ps);
