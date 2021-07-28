#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SLDateType int
#define CapaticyDef 2


typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity;
}SeqList;
//��������
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

//��ӡ˳���
void SeqListPrint(SeqList* ps);

//��ɾ��� pos����ɾ��ĵ��±�
void SeqListErase(SeqList* ps, size_t pos);
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
void SeqListPushBack(SeqList* ps,SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);
int SeqListFind(SeqList* ps, SLDateType x);
int SeqListSize(SeqList* ps);
void SeqListAt(SeqList* ps, size_t pos, SLDateType x);