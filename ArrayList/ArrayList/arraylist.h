/****************************************************/
/* project name: ArrayList                          */
/* create time: 2019-9-21                           */
/* modify time: 2019-9-21                           */
/* author: ikun000                                  */
/* version: v1.0                                    */
/****************************************************/

#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#define ERROR -1
#define OK 1

typedef int ElementType;

typedef struct _ArrayList {
	int length;                // 线性表当前的元素个数
	int size;                  // 线性表可容纳元素个数的上限
	ElementType *save_array;   // 存储数据的地址
} ArrayList, *PArrayList;


// 初始化ArrayList
// 参数：
// p: 需要初始化的ArrayList的地址
// size: ArrayList的总容量
// 返回值：
// 返回ERROR表示ArrayList初始化失败，返回OK表示初始化成功
int InitArrayList(ArrayList *p, int size);


// 销毁ArrayList
// 参数：
// p: 需要销毁的ArrayList的地址
// 返回值：
// 此函数不会失败
void DestroyArrayList(ArrayList *p);


// 在指定位置插入一个元素
// 参数：
// p: 需要销毁的ArrayList的地址
// element: 插入的元素
// pos: 插入的位置（从1开始）
// 返回值：
// 插入成功返回OK，否则返回ERROR
int InsertElement(ArrayList *p, ElementType element, int pos);


// 删除指定位置的元素
// 参数：
// p: 需要销毁的ArrayList的地址
// pos: 删除的位置（从1开始）
// result: 存放删除元素的值的地址，可以为NULL
// 返回值：
// 删除成功返回OK，否则返回ERROR
int DeleteElement(ArrayList *p, int pos, ElementType *result);


// 获取指定位置的元素
// 参数：
// p: 需要销毁的ArrayList的地址
// pos: 删除的位置（从1开始）
// result: 存放删除元素的值的地址，可以为NULL
// 返回值：
// 删除成功返回OK，否则返回ERROR
int GetElement(ArrayList *p, int pos, ElementType *result);


// 修改制定位置元素的值
// 参数：
// p: 需要销毁的ArrayList的地址
// newelement: 新的元素的值
// result: 存放删除元素的值的地址，可以为NULL
// pos: 修改的位置（从1开始）
// 返回值：
// 删除成功返回OK，否则返回ERROR
int ModifyElement(ArrayList *p, ElementType newelement, ElementType *result, int pos);


// 获取ArrayList的length
// 参数：
// p: 需要获取length的ArrayList的地址
// 返回值：
// ArrayList的length
int GetLength(ArrayList *p);


// 清除ArrayList
// 参数：
// p: 需要清除的ArrayList的地址
// 返回值：
// 此函数不会失败
void ClearArrayList(ArrayList *p);

#endif