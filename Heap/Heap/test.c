#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"



int main()
{

	
	////左子树和右子树都是大堆，要使整个二叉树变成大堆，用向下调整法
	//int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	//int n = sizeof(a) / sizeof(a[0]);
	//AdjustDown(a, n, 0);

	//对于任意一棵树，使其变成大堆；
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(a) / sizeof(a[0]);
	//建堆，此处建的是大堆
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
	//	AdjustDown(a, n, i);
	//}
	////取最顶的数【最大的数】 ，和数组最后一一个元素交换；对剩下的元素再进行堆排序，重复；
	//HeapSort(a, n);
	Heap heap;
	HeapInit(&heap, a, n);
	HeapPush(&heap, 8);
	HeapPush(&heap, 80);
	
	HeapPrint(&heap);

	HeapPop(&heap);
	HeapPrint(&heap);
	HeapDestory(&heap);
	return 0;
}

