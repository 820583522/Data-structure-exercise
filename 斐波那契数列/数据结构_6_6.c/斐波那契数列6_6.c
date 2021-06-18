#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

long long Fibonacci(int N)
{
	long long*fibArray = (long long*)malloc(sizeof(long long)*N);
	fibArray[0] = 0;
	if (N == 1)
		return fibArray;
	fibArray[1] = 1;
	for (int i = 2; i < N; i++)
	{
		fibArray[i] = fibArray[i-1] + fibArray[i - 2];
	}
	return fibArray[N-1];
}
int main()
{

	printf("%d  ", Fibonacci(10));
	return 0;
}