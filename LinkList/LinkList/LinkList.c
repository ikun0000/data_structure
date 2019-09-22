/************************************************/
/* project name: LinkList                       */
/* create time: 2019-9-22                       */
/* modify time: 2019-9-22                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/

#include "LinkList.h"
#include <stdlib.h>


// 初始化链表
// 参数：
// p: PLinkList的地址
// 返回值：
// 成功返回OK，否则返回ERROR
Status InitLinkList(PLinklist *p)
{
	*p = (LinkList *)malloc(sizeof(LinkList));
	if (*p == NULL)
	{
		return ERROR;
	}

	(*p)->element = 0;         // 定义头节点的数据域为链表的长度
	(*p)->next = NULL;
}


// 销毁链表
// 参数：
// p: 销毁的链表
// 返回值：
// 此函数不会失败
void DestroyLinkList(PLinklist p)
{
	PLinklist temp;
	while ( p != NULL )
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}


// 在指定位置插入元素
// 参数：
// p: 需要插入元素的链表
// element: 插入的元素
// pos: 插入的位置（从1开始）
// 返回值：
// 成功返回OK，否则返回ERROR
Status InsertElement(PLinklist p, ElementType element, int pos)
{
	int i;

	if (pos < 1 || pos > p->element + 1)      // 检查pos的有效性
	{
		return ERROR;
	}
	
	PLinklist insert = (LinkList *)malloc(sizeof(LinkList));
	if (insert == NULL)
	{
		return ERROR;
	}
	p->element++;
	insert->element = element;

	for (i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}

	insert->next = p->next;
	p->next = insert;

	return OK;
}


// 删除指定位置的元素
// 参数：
// p: 需要删除元素的链表
// pos: 删除的位置（从1开始）
// result: 存放返回元素的变量地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status DeleteElement(PLinklist p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->element)             // 检查pos的有效性
	{
		return ERROR;
	}
	p->element--;

	int i;
	PLinklist temp;
	for (i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}

	temp = p->next;
	p->next = temp->next;

	if (result != NULL)
	{
		*result = temp->element;
	}
	free(temp);

	return OK;
}


// 获取指定位置的元素
// 参数：
// p: 需要获取元素的链表
// pos: 获取元素的位置（从1开始）
// result: 接收返回元素的变量地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status GetElement(PLinklist p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->element)             // 检查pos的有效性
	{
		return ERROR;
	}

	int i;
	for (i = 0; i < pos; i++)
	{
		p = p->next;
	}

	if (result != NULL)
	{
		*result = p->element;
	}

	return OK;
}


// 修改指定位置的元素
// 参数：
// p: 需要修改元素的链表
// newelement: 新的元素值
// result: 接收就元素元素值得变量地址，可以为NULL
// pos: 修改元素的位置（从1开始）
// 返回值：
// 成功返回OK，否则返回ERROR
Status ModifyElement(PLinklist p, ElementType newelement, ElementType *result, int pos)
{
	if (pos < 1 || pos > p->element)             // 检查pos的有效性
	{
		return ERROR;
	}

	int i;
	for (i = 0; i < pos; i++)
	{
		p = p->next;
	}

	if (result != NULL)
	{
		*result = p->element;
	}
	p->element = newelement;

	return OK;
}


// 获取链表的元素个数
// 参数：
// p: 获取元素个数的链表
// 返回值：
// 返回元素的个数
int GetLength(PLinklist p)
{
	return p->element;
}


// 清空链表
// 参数：
// p: 清空的链表
// 返回值：
// 此函数不会失败
void ClearLinkList(PLinklist p)
{
	PLinklist temp = p;

	p->element = 0;
	p = p->next;
	temp->next = NULL;
	
	while (p != NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}