#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SLDateType int
#define CapaticyDef 2


typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SeqList;
//创建销毁
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

//打印顺序表
void SeqListPrint(SeqList* ps);

//增删查改 pos是增删查改的下标
void SeqListErase(SeqList* ps, int pos);
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
void SeqListPushBack(SeqList* ps,SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);
int SeqListFind(SeqList* ps, SLDateType x);