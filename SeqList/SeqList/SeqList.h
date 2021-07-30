#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SLDateType int
#define CapaticyDef 2  //��ʼ����


typedef struct SeqList
{
	SLDateType* a;    //ָ��̬���ٵ�����
	size_t size;      //��Ч���ݸ���
	size_t capacity;  //�����ռ�Ĵ�С
}SeqList;


//˳����ʼ��
void SeqListInit(SeqList* ps);
//˳�������
void SeqListDestory(SeqList* ps);
//˳����ӡ
void SeqListPrint(SeqList* ps);
//˳���ָ��λ�ò���
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
//˳���ָ��λ��ɾ��
void SeqListErase(SeqList* ps, size_t pos);
//˳���β��
void SeqListPushBack(SeqList* ps,SLDateType x);
//˳���ͷ��
void SeqListPushFront(SeqList* ps, SLDateType x);
//˳���ͷɾ
void SeqListPopFront(SeqList* ps);
//˳���βɾ
void SeqListPopBack(SeqList* ps);
//˳������
int SeqListFind(SeqList* ps, SLDateType x);
//˳������ݸ���
int SeqListSize(SeqList* ps);
//�޸�ָ��λ�õ�����
void SeqListAt(SeqList* ps, size_t pos, SLDateType x);
//˳���������飬������ˣ���������
void SeqListCapacityCheck(SeqList* ps)