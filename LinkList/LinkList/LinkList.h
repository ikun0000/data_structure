/************************************************/
/* project name: LinkList                       */
/* create time: 2019-9-22                       */
/* modify time: 2019-9-22                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define ERROR -1	
#define OK 0

typedef int ElementType;
typedef int Status;

typedef struct linklist {
	ElementType element;			// 链表的数据域
	struct linklist *next;          // 链表的指针域
} LinkList, *PLinklist;


// 初始化链表
// 参数：
// p: PLinkList的地址
// 返回值：
// 成功返回OK，否则返回ERROR
Status InitLinkList(PLinklist *p);


// 销毁链表
// 参数：
// p: 销毁的链表
// 返回值：
// 此函数不会失败
void DestroyLinkList(PLinklist p);


// 在指定位置插入元素
// 参数：
// p: 需要插入元素的链表
// element: 插入的元素
// pos: 插入的位置（从1开始）
// 返回值：
// 成功返回OK，否则返回ERROR
Status InsertElement(PLinklist p, ElementType element, int pos);


// 删除指定位置的元素
// 参数：
// p: 需要删除元素的链表
// pos: 删除的位置（从1开始）
// result: 存放返回元素的变量地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status DeleteElement(PLinklist p, int pos, ElementType *result);


// 获取指定位置的元素
// 参数：
// p: 需要获取元素的链表
// pos: 获取元素的位置（从1开始）
// result: 接收返回元素的变量地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status GetElement(PLinklist p, int pos, ElementType *result);


// 修改指定位置的元素
// 参数：
// p: 需要修改元素的链表
// newelement: 新的元素值
// result: 接收就元素元素值得变量地址，可以为NULL
// pos: 修改元素的位置（从1开始）
// 返回值：
// 成功返回OK，否则返回ERROR
Status ModifyElement(PLinklist p, ElementType newelement, ElementType *result, int pos);


// 获取链表的元素个数
// 参数：
// p: 获取元素个数的链表
// 返回值：
// 返回元素的个数
int GetLength(PLinklist p);


// 清空链表
// 参数：
// p: 清空的链表
// 返回值：
// 此函数不会失败
void ClearLinkList(PLinklist p);

#endif