/************************************************/
/* project name: Stack                          */
/* create time: 2019-9-30                       */
/* modify time: 2019-9-30                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include "Stack.h"
#include <stdlib.h>


// 初始化栈
// 参数：
// p: Stack的地址
// size: 初始化的栈容量
// 返回值：
// 成功返回OK，否则返回ERROR
Status InitStack(Stack *p, int size)
{
	p->base = (ElementType *)malloc(sizeof(ElementType)* size);
	if (p->base == NULL)
	{
		return ERROR;
	}

	p->size = size;
	p->top = 0;

	return OK;
}


// 销毁一个栈
// 参数：
// p: Stack的地址
// 返回值：
// 此函数不会失败
void DestroyStack(Stack *p)
{
	free(p->base);
	p->base = NULL;
}


// 向栈中压入数据
// 参数：
// p: Stack的地址
// element: 压入栈的数据（该版本的栈支持动态扩容）
// 返回值：
// 成功返回OK，否则返回ERROR
Status push(Stack *p, ElementType element)
{
	if (p->size == p->top)
	{
		ElementType *temp = (ElementType *)realloc(p->base, sizeof(ElementType) * p->size * 2);
		if (temp == NULL)
		{
			return ERROR;
		}

		p->base = temp;
		p->size *= 2;
	}

	p->base[p->top] = element;
	p->top += 1;

	return OK;
}


// 从栈中弹出数据
// 参数：
// p: Stack的地址
// result: 接收弹出的数据的变量的地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status pop(Stack *p, ElementType *result)
{
	if (p->top <= 0)
	{
		return ERROR;
	}

	p->top -= 1;
	if (result != NULL)
	{
		*result = p->base[p->top];
	}

	return OK;
}


// 获取栈顶元素的值，但不做弹栈操作
// 参数：
// p: Stack的地址
// result: 接收弹出的数据的变量的地址
// 返回值：
// 成功返回OK，否则返回ERROR
Status GetTopElement(Stack *p, ElementType *result)
{
	if (p->top <= 0)
	{
		return ERROR;
	}

	*result = p->base[p->top - 1];

	return OK;
}


// 获取栈当前的长度
// 参数：
// p: Stack的地址
// 返回值：
// 返回栈当前的长度
int GetLength(Stack *p)
{
	return p->top;
}


// 清空栈空间
// 参数：
// p: Stack的地址
// 返回值：
// 此函数不会失败
void ClearStack(Stack *p)
{
	p->top = 0;
}