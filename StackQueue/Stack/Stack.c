#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void StackInit(Stack* pst)
{
	assert(pst);

	pst->a = (Stack*)malloc(sizeof(Stack)* 4);
	pst->top = 0;
	pst->capacity = 4;
	return;
}
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
	return;
}

void StackPush(Stack* pst, STDateType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDateType*	tmp = (STDateType*)realloc(pst->a,sizeof(STDateType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	pst->a[pst->top] = x;
	pst->top++;
	return;
}

void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->top--;
	return;
}

STDateType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	return pst->a[pst->top-1];
}

bool StackEmpty(Stack* pst)
{
	return pst->top == 0;
}

int StrackSize(Stack* pst)
{
	return pst->top;
}