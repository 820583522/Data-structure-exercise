#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
typedef int STDateType;
struct Stack
{
	STDateType* a;
  	int top;      //Õ»¶¥
	int capacity; //ÈÝÁ¿
};
typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
void StackPush(Stack* pst, STDateType x);
void StackPop(Stack* pst);

STDateType StackTop(Stack* pst);

bool StackEmpty(Stack* pst);
int StrackSize(Stack* pst);