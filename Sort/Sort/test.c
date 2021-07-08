#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

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



int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	TestBubbleSort();
	return 0;
}