/************************************************/
/* project name: LinearQueue                    */
/* create time: 2019-10-1                       */
/* modify time: 2019-10-1                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include "LinearQueue.h"
#include <stdlib.h>


// 初始化队列
// 参数：
// p: LinearQueue的地址
// 返回值：
// 此函数不会失败
void InitLinearQueue(LinearQueue *p)
{
	p->length = 0;
	p->head = NULL;
	p->tail = NULL;
}


// 销毁队列
// 参数：
// p: LinearQueue的地址
// 返回值：
// 此函数不会失败
void DestroyLinearQueue(LinearQueue *p)
{
	Node *temp;

	if (p->head != NULL)
	{
		temp = p->head->next;
		free(p->head);
		p->head = temp;
	}
}


// 新增一个元素
// 参数：
// p: LinearQueue的地址
// element: 新增的元素
// 返回值：
// 成功返回OK，否则返回ERROR
Status AddElement(LinearQueue *p, ElementType element)
{
	Node *node = (Node *)malloc(sizeof(Node));

	if (node == NULL)
	{
		return ERROR;
	}

	if (0 == p->length)
	{
		p->head = node;
	}

	node->data = element;
	node->next = NULL;
	if (0 != p->length)
	{
		p->tail->next = node;
	}
	p->tail = node;
	p->length += 1;

	return OK;
}


// 删除一个元素
// 参数：
// p: LinearQueue的地址
// result: 接收删除元素的值的变量地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status RemoveElement(LinearQueue *p, ElementType *result)
{
	if (p->head == NULL)
	{
		return ERROR;
	}

	if (1 == p->length)
	{
		p->tail = NULL;
	}

	Node *node = p->head;
	if (result != NULL)
	{
		*result = p->head->data;
	}
	p->head = p->head->next;
	p->length -= 1;
	free(node);

	return OK;
}


// 获取队列元素个数
// 参数：
// p: LinearQueue的地址
// 返回值：
// 成功返回OK，否则返回ERROR
int GetLength(LinearQueue *p)
{
	return p->length;
}


// 清除队列
// 参数：
// 参数：
// p: LinearQueue的地址
// 返回值：
// 此函数不会失败
void ClearLinearQueue(LinearQueue *p)
{
	Node *temp;

	while (p->head != NULL)
	{
		temp = p->head->next;
		free(p->head);
		p->head = temp;
	}

	p->tail = NULL;
	p->length = 0;
}