#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	//int* a6 = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		//a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	/*int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();*/
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	/*printf("MergeSort:%d\n", end6 - begin6);*/
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	//free(a6);
}
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
// 插入排序
//直接插入排序 当插入第i(i>=1)个元素时，前面的array[0],array[1],…,array[i-1]已经排好序，此时用array[i]的排序码与
//array[i - 1], array[i - 2], …的排序码顺序进行比较，找到插入位置即将array[i]插入
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
//希尔插入排序
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

// 堆排序
//向下调整算法，前提是根节点的左右两个子树都已经是大堆或者小堆；
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
	//从第一个非叶子结点开始调，倒着用向下调整算法；n-1是最有一个结点的坐标，（最后一个结点坐标-1）/2是最后一个非叶子结点的坐标
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

// 冒泡排序
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

int GetMiddleIndex(int* a,int begin,int end)
{
	if (a[begin] > a[(begin+end)/2])
	{
		//a[begin]>a[(begin+end)/2]
		if (a[end] > a[begin])
		{
			//a[end]>a[begin]>a[(begin+end)/2]
			return begin;
		}
		else if (a[(begin + end) / 2] > a[end])
		{
			//a[begin]>a[(begin+end)/2]>a[end]
			return (begin + end) / 2;
		}
		else
		{
			//a[begin]>a[end]>a[(begin+end)/2]
			return end;
		}
	}
	else
	{
		//a[(begin+end)/2]>a
		if (a[end] > a[(begin + end) / 2])
		{
			//c>a[(begin+end)/2]>a
			return (begin + end) / 2;
		}
		else if (a[begin] > a[end])
		{
			//a[(begin+end)/2]>a[begin]>a[end]
			return begin;
		}
		else
		{
			//a[(begin+end)/2]>a[end]>a[begin]
			return end;
		}
	}
}

// 快速排序hoare版本(左右指针法)--单趟快速排序
int PartSort1(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		//right找小
		while (left < right&&a[right] >= a[key])
		{
			right--;
		}
		//left找大
		while (left < right&&a[left] <= a[key])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[key]);
	return left;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	while (left < right)
	{
		//right先走，找比a{hole]小的值，放在hole的地方，right处就形成了一个坑
		while (left < right&&a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
		//left找比a[hole]大的值，放在right处，填补right的坑，自己的位置形成新得坑
		while (left < right&&a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int key = left;
	//一开始cur在a[1]的位置，prev在a[0]的位置
	int prev = left, cur = left+1;
	while (cur <= right)
	{
		//cur遇到比a[key]的值还要小的值时停下来，prev++，然后交换prev和cur
		while (cur <= right&&a[cur] >= a[key])
		{
			cur++;
		}
		if (cur <= right)
		{
			swap(&a[++prev], &a[cur++]);
		}
	}
	//cur 走到数组尾时，交换key和prev,如此做之后，prev左边的值都比它小，右边的值都比他大
	swap(&a[key], &a[prev]);
	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	//三数取中法--如果数组本来就是有序的，快排的时间复杂度就变成了0（N*N），我们通过三数取中法，使a[left]的值不是最小，来避免最坏的这种情况
	int MidIndex = GetMiddleIndex(a, begin, end);
	swap(&a[begin], &a[MidIndex]);

	//小区间优化，1.如果子区间数据较多，用快排比较划算。2.如果子区间数据较少，这是递归就不如插入排序划算了
	if (begin < end - 10)
	{
		int keyi = PartSort3(a, begin, end);

		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}
}


//递归，闲待编译器优化很好，性能已经不是大问题
//最大的问题->递归深度太深，程序本身没有问题，但是栈空间不够，导致栈溢出
//只能改成非递归，改成非递归有两种方式：
//1.直接改循环->斐波那契数列求解
//2.树遍历非递归和快排非递归等等，只能用Stack存储数据模拟递归过程
// 快速排序 非递归实现

void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	//先进左端点，再进右端点
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		//取出左右端点的值，即一趟快速排序的begin和end；这里要注意进栈和出栈的顺序
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//一趟快速排序结束后，把它形成的两个新的小区间依次进栈
		int MidIndex = GetMiddleIndex(a, left, right);
		swap(&a[left], &a[MidIndex]);
		int keyi = PartSort1(a, left, right);
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi+1);
			StackPush(&st, right);
		}
	}
}