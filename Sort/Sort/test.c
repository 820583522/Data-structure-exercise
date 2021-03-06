#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
void TestInsertSort()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestShellSort()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestSelectSort()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestHeapSort()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}


void TestBubbleSort()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}
void TestQuickSort()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	QuickSort(arr,0, sizeof(arr) / sizeof(arr[0])-1);
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}
void TestQuickSortNonR()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	QuickSortNonR(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}
void TestMergeSort()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	MergeSort(arr, sizeof(arr) / sizeof(arr[0]) );
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}
void TestMergeSortNonR()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8,10,11,7};
	MergeSortNonR(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestCountSort()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8, 10, 11, 7 };
	CountSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
}
//int main()
//{
//	//TestOP();
//	
//	//TestInsertSort();
//	//TestShellSort();
//	//TestSelectSort();
//	//TestHeapSort();
//	//TestBubbleSort();
//	//TestQuickSort();
//	//TestQuickSortNonR();
//	//TestMergeSort();
//	//TestMergeSortNonR();
//	//TestCountSort();
//
//	return 0;
//}


int Min(int a, int b)
{
	return a>b ? b : a;
}
int main()
{
	int N = 0;
	scanf("%d", &N);
	if (N<4)
	{
		printf("0");
	}
	int prev = 1;
	int prevprev = 1;
	int cur = 2;
	int pcur = 2;
	while (cur<N)
	{
		cur = prevprev + prev;
		
		prevprev=prev;
		prev = cur;
	}
	int n = Min(cur - N, N - prevprev);
	printf("%d", n);
}