#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

int main()
{
	int arr[] = { 5, 6, 8, 1, 2, 3, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, n);
	InsertSort(arr, n);
	PrintArr(arr, n);
}