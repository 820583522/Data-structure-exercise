#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
// ��������
//ֱ�Ӳ������� �������i(i>=1)��Ԫ��ʱ��ǰ���array[0],array[1],��,array[i-1]�Ѿ��ź��򣬴�ʱ��array[i]����������
//array[i - 1], array[i - 2], ����������˳����бȽϣ��ҵ�����λ�ü���array[i]����
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
//ϣ����������
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3+1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int maxIndex=left, minIndex=left;
	while (left < right)
	{
		
		for (int i = left; i<=right; i++)
		{
			if (a[i]>a[maxIndex])
			{
				maxIndex = i;
			}
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
		}
		swap(&a[left], &a[minIndex]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		swap(&a[right], &a[maxIndex]);
		left++;
		right--;
	}
}

// ������
//���µ����㷨��ǰ���Ǹ��ڵ�����������������Ѿ��Ǵ�ѻ���С�ѣ�
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child <n)
	{
		if (child+1<n&&a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}	
}
void HeapSort(int* a, int n)
{
	//�ӵ�һ����Ҷ�ӽ�㿪ʼ�������������µ����㷨��n-1������һ���������꣬�����һ���������-1��/2�����һ����Ҷ�ӽ�������
	for (int i = (n-1-1)/2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// ð������
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int exchenge = 0;
		for (int i = 0; i < n - j - 1; i++)
		{
			if (a[i + 1] < a[i])
			{
				swap(&a[i + 1], &a[i]);
				exchenge = 1;
			}
		}
		if (exchenge == 0)
		{
			break;
		}
	}
}

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int n)
{
	int left = 0, right = n - 1;
	int key = left;
	while (left < right)
	{
		//right��С
		while (a[right]>=a[key])
		{
			right--;	
		}
		//left�Ҵ�
		while (a[left] <= a[key])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[key]);
}