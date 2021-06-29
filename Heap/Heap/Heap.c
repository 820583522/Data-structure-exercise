#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapSort(HPDateType* a, int n)
{
	assert(a);
	//取最顶的数【最大的数】 ，和数组最后一一个元素交换；对剩下的元素再进行堆排序，重复；
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void swap(HPDateType* pparent, HPDateType* pchild)
{
	assert(pparent&&pchild);
	HPDateType tmp = *pchild;
	*pchild = *pparent;
	*pparent = tmp;
}

//左子树和右子树都是小堆，要使整个二叉树变成小堆，用向下调整法
void AdjustDown(HPDateType * a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child != n - 1)
		{
			if (a[child + 1] > a[child])
			{
				child++;
			}
		}
		if (a[parent]<a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	return;
}
//向上调整法
void AdjustUp(HPDateType* a, int n,int child)
{
	assert(a);
	int parent = (child-1)/2;
	while (child > 0)
	{
		if (a[parent]<a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
	return;
}


void HeapInit(Heap* php, HPDateType* a, int n)
{
	assert(php);
	php->a = (HPDateType*)malloc(sizeof(HPDateType)*n);
	if (a == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HPDateType)*n);
	php->capacity = n;
	php->size = n;
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, php->size, i);
	}
}
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapPush(Heap* php, HPDateType x)
{
	//扩容
	assert(php);
	if (php->capacity == php->size)
	{
		HPDateType* tmp = (HPDateType*)realloc(php->a, sizeof(HPDateType)*php->capacity* 2);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		php->a= tmp;
		php->capacity *= 2;
	}	
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size, php->size - 1);
}
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDateType HeapTop(Heap* php)
{
	assert(php);
	return php->a[0];
}
int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}

void HeapPrint(Heap* php)
{
	int num = 1;
	int row = 1;
	while (num <= php->size)
	{
		for (;(num<=php->size)&&( num < pow(2, row)); num++)
		{
			printf("%d  ", php->a[num - 1]);
		}
		printf("\n");
		row++;
	}
}