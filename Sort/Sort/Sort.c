#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
// 插入排序  当插入第i(i>=1)个元素时，前面的array[0],array[1],…,array[i-1]已经排好序，此时用array[i]的排序码与
//array[i - 1], array[i - 2], …的排序码顺序进行比较，找到插入位置即将array[i]插入，原来位置上的元素顺序后移,注释的代码是自己写的，下边的代码是杭哥的
/*void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void InsertSort(int* a, int n)
{
	int i = 0;
	while (i < n-1)
	{
		for (int prev = i, cur = i+1; prev >= 0; prev--, cur--)
		{
			if (a[prev] > a[cur])
			{
				swap(&a[prev], &a[cur]);
			}
			else
			{
				break;
			}
		}
		i++;
	}
}*/
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >=0)
		{
			if (tmp< arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}