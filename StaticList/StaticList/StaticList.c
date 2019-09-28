/************************************************/
/* project name: StaticList                     */
/* create time: 2019-9-27                       */
/* modify time: 2019-9-27                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include "StaticList.h"
#include <stdlib.h>


// 初始化静态链表
// 参数：
// p: 静态链表的地址
// size: 静态链表的容量
// 返回值：
// 初始化成功返回OK，否则返回ERROR
Status InitStaticList(StaticList *p, int size)
{
	p->size = size;
	p->datas = (Node *)malloc(sizeof(Node)* (size + 2));

	if (p->datas == NULL)
	{
		return ERROR;
	}

	p->datas[0].data = 0;			// 定义静态链表的头节点的数据域的data存放静态链表的元素个数
	p->datas[0].cursor = 1;			// 静态链表的头节点的游标指向备用链表
	p->datas[size + 1].cursor = 0;		// 在没有有效链表的情况下尾节点的游标指向头节点
	p->datas[size + 1].data = size;	// 定义尾节点的数据域为备用链表的元素数量

	int i;
	for (i = 1; i < size + 1; i++)
	{
		p->datas[i].cursor = i + 1;
	}

	return OK;
}


// 销毁静态链表
// 参数：
// p: 静态链表的地址
// 返回值：
// 此函数不会失败
void DestroyStaticList(StaticList *p)
{
	free(p->datas);
}


// 在指定位置插入元素
// 参数：
// p: 静态链表的地址
// element: 插入的元素
// pos: 插入的位置
// 返回值：
// 成功返回OK，否则返回ERROR
Status InsertElement(StaticList *p, ElementType element, int pos)
{
	if (pos < 1 || pos > p->datas[0].data + 1)		// 检查pos的有效性
	{
		return ERROR;
	}

	int index = staticlist_malloc(p);
	if (ERROR == index)			// 如果没有获得有效下标，即为p->datas[0].data == p->size
	{
		return ERROR;
	}
	p->datas[index].data = element;

	int previous = p->size + 1;
	int i;
	for (i = 1; i < pos; i++)
	{
		previous = p->datas[previous].cursor;
	}

	p->datas[index].cursor = p->datas[previous].cursor;
	p->datas[previous].cursor = index;
	p->datas[0].data += 1;

	return OK;
}


// 删除指定位置的元素
// 参数：
// p: 静态链表的地址
// pos: 删除的位置
// result: 接收删除位置的元素的地址，可以为NULL
// 返回值：
// 删除成功返回OK，否则返回ERROR
Status DeleteElement(StaticList *p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->datas[0].data)		// 检查pos的有效性
	{
		return ERROR;
	}

	if (0 == p->datas[0].data)
	{
		return ERROR;
	}

	int previous = p->size + 1;
	int i;
	for (i = 1; i < pos; i++)
	{
		previous = p->datas[previous].cursor;
	}

	int deleteindex = p->datas[previous].cursor;
	if (result != NULL)
	{
		*result = p->datas[deleteindex].data;
	}
	p->datas[previous].cursor = p->datas[deleteindex].cursor;

	p->datas[0].data -= 1;
	staticlist_free(p, deleteindex);

	return OK;
}


// 获取指定位置元素的值
// 参数：
// p: 静态链表的地址
// pos: 获取元素的位置
// result: 接受获取元素的地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status GetElement(StaticList *p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->datas[0].data)		// 检查pos的有效性
	{
		return ERROR;
	}

	int index = p->size + 1;
	int i;
	for (i = 0; i < pos; i++)
	{
		index = p->datas[index].cursor;
	}

	if (result != NULL)
	{
		*result = p->datas[index].data;
	}

	return OK;
}


// 修改制定位置的元素
// 参数：
// p: 静态链表的地址
// newelement: 新元素的值
// result: 获取旧元素的值的地址，可以为NULL
// pos: 修改的元素的位置
// 返回值：
// 修改成功返回OK，否则返回ERROR
Status ModifyElement(StaticList *p, ElementType newelement, ElementType *result, int pos)
{
	if (pos < 1 || pos > p->datas[0].data)		// 检查pos的有效性
	{
		return ERROR;
	}

	int index = p->size + 1;
	int i;
	for (i = 0; i < pos; i++)
	{
		index = p->datas[index].cursor;
	}

	if (result != NULL)
	{
		*result = p->datas[index].data;
	}
	p->datas[index].data = newelement;

	return OK;
}


// 获取静态链表的元素数量
// 参数：
// p: 静态链表的地址
// 返回值：
// 此函数返回静态链表的元素数量
int GetLength(StaticList *p)
{
	return p->datas[0].data;
}


// 清空静态链表
// 参数：
// p: 静态链表的地址
// 返回值：
// 此函数不会失败
void ClearStaticList(StaticList *p)
{
	p->datas[0].data = 0;			// 定义静态链表的头节点的数据域的data存放静态链表的元素个数
	p->datas[0].cursor = 1;			// 静态链表的头节点的游标指向备用链表
	p->datas[p->size + 1].cursor = 0;		// 在没有有效链表的情况下尾节点的游标指向头节点
	p->datas[p->size + 1].data = p->size;	// 定义尾节点的数据域为备用链表的元素数量

	int i;
	for (i = 1; i < p->size + 1; i++)
	{
		p->datas[i].cursor = i + 1;
	}

	return OK;
}


// 从静态链表中分配一个存储空间
// 参数：
// p: 静态链表的地址
// 返回值：
// 成功返回存储空间的下标，否则返回ERROR
int staticlist_malloc(StaticList *p)
{
	if (0 == p->datas[p->size + 1].data)		// 检查是否还有空间
	{
		return ERROR;
	}
	p->datas[p->size + 1].data -= 1;

	int result = p->datas[0].cursor;
	if (0 == p->datas[p->size + 1].data)
	{
		p->datas[0].cursor = p->size + 1;			// 在备用链表为空时头节点的游标指向尾节点
	}
	else
	{
		p->datas[0].cursor = p->datas[result].cursor;
	}

	return result;
}


// 释放静态链表的一个存储空间
// 参数：
// p: 静态链表的地址
// pos: 释放的位置的下标
// 返回值
// 此函数不会失败
void staticlist_free(StaticList *p, int pos)
{
	if (p->size == p->datas[p->size + 1].data)
	{
		return;
	}

	p->datas[p->size + 1].data += 1;
	p->datas[pos].cursor = p->datas[0].cursor;
	p->datas[0].cursor = pos;
}


