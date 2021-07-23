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

// ��������hoare�汾(����ָ�뷨)--���˿�������
int PartSort1(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		//right��С
		while (left < right&&a[right] >= a[key])
		{
			right--;
		}
		//left�Ҵ�
		while (left < right&&a[left] <= a[key])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[key]);
	return left;
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	while (left < right)
	{
		//right���ߣ��ұ�a{hole]С��ֵ������hole�ĵط���right�����γ���һ����
		while (left < right&&a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
		//left�ұ�a[hole]���ֵ������right�����right�Ŀӣ��Լ���λ���γ��µÿ�
		while (left < right&&a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int key = left;
	//һ��ʼcur��a[1]��λ�ã�prev��a[0]��λ��
	int prev = left, cur = left+1;
	while (cur <= right)
	{
		//cur������a[key]��ֵ��ҪС��ֵʱͣ������prev++��Ȼ�󽻻�prev��cur
		while (cur <= right&&a[cur] >= a[key])
		{
			cur++;
		}
		if (cur <= right)
		{
			swap(&a[++prev], &a[cur++]);
		}
	}
	//cur �ߵ�����βʱ������key��prev,�����֮��prev��ߵ�ֵ������С���ұߵ�ֵ��������
	swap(&a[key], &a[prev]);
	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	//����ȡ�з�--������鱾����������ģ����ŵ�ʱ�临�ӶȾͱ����0��N*N��������ͨ������ȡ�з���ʹa[left]��ֵ������С������������������
	int MidIndex = GetMiddleIndex(a, begin, end);
	swap(&a[begin], &a[MidIndex]);

	//С�����Ż���1.������������ݽ϶࣬�ÿ��űȽϻ��㡣2.������������ݽ��٣����ǵݹ�Ͳ��������������
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


//�ݹ飬�д��������Ż��ܺã������Ѿ����Ǵ�����
//��������->�ݹ����̫�������û�����⣬����ջ�ռ䲻��������ջ���
//ֻ�ܸĳɷǵݹ飬�ĳɷǵݹ������ַ�ʽ��
//1.ֱ�Ӹ�ѭ��->쳲������������
//2.�������ǵݹ�Ϳ��ŷǵݹ�ȵȣ�ֻ����Stack�洢����ģ��ݹ����
// �������� �ǵݹ�ʵ��

void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	//�Ƚ���˵㣬�ٽ��Ҷ˵�
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		//ȡ�����Ҷ˵��ֵ����һ�˿��������begin��end������Ҫע���ջ�ͳ�ջ��˳��
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//һ�˿�����������󣬰����γɵ������µ�С�������ν�ջ
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