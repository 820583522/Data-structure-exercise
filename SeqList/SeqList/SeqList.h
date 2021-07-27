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
//��������
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

//��ӡ˳���
void SeqListPrint(SeqList* ps);

//��ɾ��� pos����ɾ��ĵ��±�
void SeqListErase(SeqList* ps, int pos);
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
void SeqListPushBack(SeqList* ps,SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);
int SeqListFind(SeqList* ps, SLDateType x);