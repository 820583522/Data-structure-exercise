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
// ��������  �������i(i>=1)��Ԫ��ʱ��ǰ���array[0],array[1],��,array[i-1]�Ѿ��ź��򣬴�ʱ��array[i]����������
//array[i - 1], array[i - 2], ����������˳����бȽϣ��ҵ�����λ�ü���array[i]���룬ԭ��λ���ϵ�Ԫ��˳�����,ע�͵Ĵ������Լ�д�ģ��±ߵĴ����Ǻ����
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