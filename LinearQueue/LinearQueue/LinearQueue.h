/************************************************/
/* project name: LinearQueue                    */
/* create time: 2019-10-1                       */
/* modify time: 2019-10-1                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#ifndef _LINEARQUEUE_H
#define _LINEARQUEUE_H


#define OK 0
#define ERROR -1

typedef int ElementType;
typedef int Status;


typedef struct _Node {
	ElementType data;		// 数据域
	struct _Node *next;		// 指针域
} Node, *PNode;

typedef struct _LinearQueue {
	int length;				// 队列元素个数
	Node *head;				// 队列头
	Node *tail;				// 队列尾
} LinearQueue, *PLinearQueue;


// 初始化队列
// 参数：
// p: LinearQueue的地址
// 返回值：
// 此函数不会失败
void InitLinearQueue(LinearQueue *p);


// 销毁队列
// 参数：
// p: LinearQueue的地址
// 返回值：
// 此函数不会失败
void DestroyLinearQueue(LinearQueue *p);


// 新增一个元素
// 参数：
// p: LinearQueue的地址
// element: 新增的元素
// 返回值：
// 成功返回OK，否则返回ERROR
Status AddElement(LinearQueue *p, ElementType element);


// 删除一个元素
// 参数：
// p: LinearQueue的地址
// result: 接收删除元素的值的变量地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status RemoveElement(LinearQueue *p, ElementType *result);


// 获取队列元素个数
// 参数：
// p: LinearQueue的地址
// 返回值：
// 成功返回OK，否则返回ERROR
int GetLength(LinearQueue *p);


// 清除队列
// 参数：
// 参数：
// p: LinearQueue的地址
// 返回值：
// 此函数不会失败
void ClearLinearQueue(LinearQueue *p);

#endif