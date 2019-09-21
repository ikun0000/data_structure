/****************************************************/
/* project name: ArrayList                          */
/* create time: 2019-9-21                           */
/* modify time: 2019-9-21                           */
/* author: ikun0000                                 */
/* version: v1.0                                    */
/****************************************************/


#include "arraylist.h"
#include <stdlib.h>

// 初始化ArrayList
// 参数：
// p: 需要初始化的ArrayList的地址
// size: ArrayList的总容量
// 返回值：
// 返回ERROR表示ArrayList初始化失败，返回OK表示初始化成功
int InitArrayList(ArrayList *p, int size)
{
	p->save_array = (ElementType *)malloc(sizeof(ElementType) * size);
	if (p->save_array == NULL)
	{
		return ERROR;
	}
	
	p->size = size;
	p->length = 0;
	return OK;
}


// 销毁ArrayList
// 参数：
// p: 需要销毁的ArrayList的地址
// 返回值：
// 此函数不会失败
void DestroyArrayList(ArrayList *p)
{
	free(p->save_array);
}


// 在指定位置插入一个元素
// 参数：
// p: 需要销毁的ArrayList的地址
// element: 插入的元素
// pos: 插入的位置（从1开始）
// 返回值：
// 插入成功返回OK，否则返回ERROR
int InsertElement(ArrayList *p, ElementType element, int pos)
{
	if (pos < 1 || pos > p->length + 1)    // 检查pos的有效性
	{
		return ERROR;
	}
	if (p->length + 1 > p->size)           // 检查ArrayList是否还有空间
	{
		return ERROR;
	}

	int i;
	for (i = p->length - 1; i >= pos - 1 ; i--)
	{
		p->save_array[i + 1] = p->save_array[i];
	}
	p->save_array[pos - 1] = element;
	p->length++;

	return OK;
}


// 删除指定位置的元素
// 参数：
// p: 需要销毁的ArrayList的地址
// pos: 删除的位置（从1开始）
// result: 存放删除元素的值的地址，可以为NULL
// 返回值：
// 删除成功返回OK，否则返回ERROR
int DeleteElement(ArrayList *p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->length + 1)    // 检查pos的有效性
	{
		return ERROR;
	}
	if (p->length == 0)					   // 检查ArrayList是否还可以删除元素
	{
		return ERROR;
	}

	if (result != NULL) 
	{
		*result = p->save_array[pos - 1];
	}
	
	int i;
	for (i = pos - 1; i <= p->length - 1; i++)
	{
		p->save_array[i] = p->save_array[i + 1];
	}
	p->length--;

	return OK;
}


// 获取指定位置的元素
// 参数：
// p: 需要销毁的ArrayList的地址
// pos: 删除的位置（从1开始）
// result: 存放删除元素的值的地址，可以为NULL
// 返回值：
// 删除成功返回OK，否则返回ERROR
int GetElement(ArrayList *p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->length + 1)    // 检查pos的有效性
	{
		return ERROR;
	}

	if (result != NULL)
	{
		*result = p->save_array[pos - 1];
	}

	return OK;
}


// 修改制定位置元素的值
// 参数：
// p: 需要销毁的ArrayList的地址
// newelement: 新的元素的值
// result: 存放删除元素的值的地址，可以为NULL
// pos: 修改的位置（从1开始）
// 返回值：
// 删除成功返回OK，否则返回ERROR
int ModifyElement(ArrayList *p, ElementType newelement, ElementType *result, int pos)
{
	if (pos < 1 || pos > p->length + 1)    // 检查pos的有效性
	{
		return ERROR;
	}

	if (result != NULL)
	{
		*result = p->save_array[pos - 1];
	}
	p->save_array[pos - 1] = newelement;

	return OK;
}


// 获取ArrayList的length
// 参数：
// p: 需要获取length的ArrayList的地址
// 返回值：
// ArrayList的length
int GetLength(ArrayList *p)
{
	return p->length;
}


// 清除ArrayList
// 参数：
// p: 需要清除的ArrayList的地址
// 返回值：
// 此函数不会失败
void ClearArrayList(ArrayList *p)
{
	p->length = 0;
}
