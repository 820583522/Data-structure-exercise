#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"



int main()
{

	
	////�����������������Ǵ�ѣ�Ҫʹ������������ɴ�ѣ������µ�����
	//int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	//int n = sizeof(a) / sizeof(a[0]);
	//AdjustDown(a, n, 0);

	//��������һ������ʹ���ɴ�ѣ�
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(a) / sizeof(a[0]);
	//���ѣ��˴������Ǵ��
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
	//	AdjustDown(a, n, i);
	//}
	////ȡ��������������� �����������һһ��Ԫ�ؽ�������ʣ�µ�Ԫ���ٽ��ж������ظ���
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

