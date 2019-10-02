/************************************************/
/* project name: CircularQueue                  */
/* create time: 2019-10-2                       */
/* modify time: 2019-10-2                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#ifndef _CIRCULARQUEUE_H
#define _CIRCULARQUEUE_H


#define OK 0
#define ERROR -1

typedef int ElementType;			// 队列存储的数据类型
typedef int Status;					// 状态码


typedef struct _CircularQueue {
	ElementType *datas;				// 队列的存储空间
	int head;						// 队列头下标
	int tail;						// 队列尾下标
	int size;						// 队列的容量
	int length;						// 队列的元素个数
} CircularQueue, *PCircularQueue;


// 初始化环形队列
// 参数：
// p: CircularQueue的地址
// size: 环形队列的容量
// 返回值：
// 成功返回OK，否则返回ERROR
Status InitCircularQueue(CircularQueue *p, int size);


// 销毁环形队列
// 参数：
// p: CircularQueue的地址
// 返回值：
// 此函数不会失败
void DestroyCircularQueue(CircularQueue *p);


// 添加一个元素
// 参数：
// p: CircularQueue的地址
// element: 添加的元素
// 返回值：
// 成功返回OK，否则返回ERROR
Status AddElement(CircularQueue *p, ElementType element);


// 删除一个元素
// 参数：
// p: CircularQueue的地址
// result: 接收删除的元素值得变量的地址，可以为NULL
// 返回值：
// 成功返回OK，否则返回ERROR
Status RemoveElement(CircularQueue *p, ElementType *result);


// 获取环形队列当前的元素个数
// 参数：
// p: CircularQueue的地址
// 返回值：
// 返回队列元素的个数
int GetLength(CircularQueue *p);


// 清空环形队列
// 参数：
// p: CircularQueue的地址
// 返回值：
// 此函数不会失败
void ClearCircularQueue(CircularQueue *p);


#endif