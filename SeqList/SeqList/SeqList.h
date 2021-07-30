#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SLDateType int
#define CapaticyDef 2  //初始容量


typedef struct SeqList
{
	SLDateType* a;    //指向动态开辟的数组
	size_t size;      //有效数据个数
	size_t capacity;  //容量空间的大小
}SeqList;


//顺序表初始化
void SeqListInit(SeqList* ps);
//顺序表销毁
void SeqListDestory(SeqList* ps);
//顺序表打印
void SeqListPrint(SeqList* ps);
//顺序表指定位置插入
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
//顺序表指定位置删除
void SeqListErase(SeqList* ps, size_t pos);
//顺序表尾插
void SeqListPushBack(SeqList* ps,SLDateType x);
//顺序表头插
void SeqListPushFront(SeqList* ps, SLDateType x);
//顺序表头删
void SeqListPopFront(SeqList* ps);
//顺序表尾删
void SeqListPopBack(SeqList* ps);
//顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
//顺序表数据个数
int SeqListSize(SeqList* ps);
//修改指定位置的数据
void SeqListAt(SeqList* ps, size_t pos, SLDateType x);
//顺序表容量检查，如果满了，进行增容
void SeqListCapacityCheck(SeqList* ps)