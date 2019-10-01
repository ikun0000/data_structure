/************************************************/
/* project name: Stack                          */
/* create time: 2019-9-30                       */
/* modify time: 2019-9-30                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/

#ifndef _STACK_H
#define _STACK_H


#define OK 0
#define ERROR -1

typedef int ElementType;
typedef int Status;


typedef struct _Stack {
	ElementType *base;			// 栈base指针指向栈底
	int top;					// 栈顶元素的索引，同时也可以表示栈当前的长度
	int size;					// 栈的容量
} Stack, *PStack;


// 初始化栈
// 参数：
// p: Stack的地址
// size: 初始化的栈容量
// 返回值：
// 成功返回OK，否则返回ERROR
Status InitStack(Stack *p, int size);


// 销毁一个栈
// 参数：
// p: Stack的地址
// 返回值：
// 此函数不会失败
void DestroyStack(Stack *p);


// 向栈中压入数据
// 参数：
// p: Stack的地址
// element: 压入栈的数据（该版本的栈支持动态扩容）
// 返回值：
// 成功返回OK，否则返回ERROR
Status push(Stack *p, ElementType element);


// 从栈中弹出数据
// 参数：
// p: Stack的地址
// result: 接收弹出的数据的变量的地址
// 返回值：
// 成功返回OK，否则返回ERROR
Status pop(Stack *p, ElementType *result);


// 获取栈顶元素的值，但不做弹栈操作
// 参数：
// p: Stack的地址
// result: 接收弹出的数据的变量的地址
// 返回值：
// 成功返回OK，否则返回ERROR
Status GetTopElement(Stack *p, ElementType *result);


// 获取栈当前的长度
// 参数：
// p: Stack的地址
// 返回值：
// 返回栈当前的长度
int GetLength(Stack *p);


// 清空栈空间
// 参数：
// p: Stack的地址
// 返回值：
// 此函数不会失败
void ClearStack(Stack *p);

#endif