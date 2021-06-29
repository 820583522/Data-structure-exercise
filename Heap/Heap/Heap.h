#pragma once
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>
typedef int HPDateType;
typedef struct Heap
{
	HPDateType* a;
	int size;
	int capacity;
}Heap;
void swap(HPDateType* pparent, HPDateType* pchild);
void AdjustDown(HPDateType * a, int n, int parent);
void HeapSort(HPDateType* a, int n);
void HeapInit(Heap* php, HPDateType* a, int n);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDateType x);
void HeapPop(Heap* php);
HPDateType HeapTop(Heap* php);
int HeapSize(Heap* php);
bool HeapEmpty(Heap* php);
void HeapPrint(Heap* php);
void AdjustUp(HPDateType* php,int n, int child);