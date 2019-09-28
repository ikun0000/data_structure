/************************************************/
/* project name: StaticList                     */
/* create time: 2019-9-27                       */
/* modify time: 2019-9-27                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/

#ifndef _STATICLIST_H
#define _STATICLIST_H

#define OK 0				// 成功状态码
#define ERROR -1			// 失败状态码

typedef int ElementType;	// 定义存储元素的数据类型
typedef int Status;	


typedef struct _Node {
	ElementType data;			// 节点的数据域
	int cursor;					// 节点的游标
} Node, *PNode;


typedef struct _StaticList {
	Node *datas;				// 数据与游标的存储位置
	int size;					// 静态链表的容量
} StaticList, *PStaticList;


// 初始化静态链表
// 参数：
// p: 静态链表的地址
// size: 静态链表的容量
// 返回值：
// 初始化成功返回OK，否则返回ERROR
Status InitStaticList(StaticList *p, int size);


// 销毁静态链表
// 参数：
// p: 静态链表的地址
// 返回值：
// 此函数不会失败
void DestroyStaticList(StaticList *p);


// 在指定位置插入元素
// 参数：
// p: 静态链表的地址
// element: 插入的元素
// pos: 插入的位置
// 返回值：
// 成功返回OK，否则返回ERROR
Status InsertElement(StaticList *p, ElementType element, int pos);


// 删除指定位置的元素
// 参数：
// p: 静态链表的地址
// pos: 删除的位置
// result: 接收删除位置的元素的地址，可以为NULL
// 返回值：
// 删除成功返回OK，否则返回ERROR
Status DeleteElement(StaticList *p, int pos, ElementType *result);


// 获取指定位置元素的值
// 参数：
// p: 静态链表的地址
// pos: 获取元素的位置
// result: 接受获取元素的地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status GetElement(StaticList *p, int pos, ElementType *result);


// 修改制定位置的元素
// 参数：
// p: 静态链表的地址
// newelement: 新元素的值
// result: 获取旧元素的值的地址，可以为NULL
// pos: 修改的元素的位置
// 返回值：
// 修改成功返回OK，否则返回ERROR
Status ModifyElement(StaticList *p, ElementType newelement, ElementType *result, int pos);


// 获取静态链表的元素数量
// 参数：
// p: 静态链表的地址
// 返回值：
// 此函数返回静态链表的元素数量
int GetLength(StaticList *p);


// 清空静态链表
// 参数：
// p: 静态链表的地址
// 返回值：
// 此函数不会失败
void ClearStaticList(StaticList *p);


// 从静态链表中分配一个存储空间
// 参数：
// p: 静态链表的地址
// 返回值：
// 成功返回存储空间的下标，否则返回ERROR
int staticlist_malloc(StaticList *p);


// 释放静态链表的一个存储空间
// 参数：
// p: 静态链表的地址
// pos: 释放的位置的下标
// 返回值
// 此函数不会失败
void staticlist_free(StaticList *p, int pos);


#endif