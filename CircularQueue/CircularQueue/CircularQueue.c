/************************************************/
/* project name: CircularQueue                  */
/* create time: 2019-10-2                       */
/* modify time: 2019-10-2                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include "CircularQueue.h"
#include <stdlib.h>


// 初始化环形队列
// 参数：
// p: CircularQueue的地址
// size: 环形队列的容量
// 返回值：
// 成功返回OK，否则返回ERROR
Status InitCircularQueue(CircularQueue *p, int size)
{
	p->datas = (ElementType *)malloc(sizeof(ElementType)* size);
	if (p->datas == NULL)
	{
		return ERROR;
	}

	p->head = 0;
	p->tail = 0;
	p->length = 0;
	p->size = size;

	return OK;
}


// 销毁环形队列
// 参数：
// p: CircularQueue的地址
// 返回值：
// 此函数不会失败
void DestroyCircularQueue(CircularQueue *p)
{
	free(p->datas);
	p->datas = NULL;
}


// 添加一个元素
// 参数：
// p: CircularQueue的地址
// element: 添加的元素
// 返回值：
// 成功返回OK，否则返回ERROR
Status AddElement(CircularQueue *p, ElementType element)
{
	if (p->size == p->length)
	{
		return ERROR;
	}

	p->datas[p->tail] = element;
	if (0 == p->length)
	{
		p->head = p->tail;
	}
	p->tail += 1;
	p->tail %= p->size;
	p->length += 1;

	return OK;
}


// 删除一个元素
// 参数：
// p: CircularQueue的地址
// result: 接收删除的元素值得变量的地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status RemoveElement(CircularQueue *p, ElementType *result)
{
	if (p->length == 0)
	{
		return ERROR;
	}

	if (result != NULL)
	{
		*result = p->datas[p->head];
	}
	p->head += 1;
	p->head %= p->size;
	p->length -= 1;

	return OK;
}


// 获取环形队列当前的元素个数
// 参数：
// p: CircularQueue的地址
// 返回值：
// 返回队列元素的个数
int GetLength(CircularQueue *p)
{
	return p->length;
}


// 清空环形队列
// 参数：
// p: CircularQueue的地址
// 返回值：
// 此函数不会失败
void ClearCircularQueue(CircularQueue *p)
{
	p->head = 0;
	p->tail = 0;
	p->length = 0;
}