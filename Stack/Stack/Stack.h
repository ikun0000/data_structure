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
	ElementType *base;			// ջbaseָ��ָ��ջ��
	int top;					// ջ��Ԫ�ص�������ͬʱҲ���Ա�ʾջ��ǰ�ĳ���
	int size;					// ջ������
} Stack, *PStack;


// ��ʼ��ջ
// ������
// p: Stack�ĵ�ַ
// size: ��ʼ����ջ����
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InitStack(Stack *p, int size);


// ����һ��ջ
// ������
// p: Stack�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyStack(Stack *p);


// ��ջ��ѹ������
// ������
// p: Stack�ĵ�ַ
// element: ѹ��ջ�����ݣ��ð汾��ջ֧�ֶ�̬���ݣ�
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status push(Stack *p, ElementType element);


// ��ջ�е�������
// ������
// p: Stack�ĵ�ַ
// result: ���յ��������ݵı����ĵ�ַ
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status pop(Stack *p, ElementType *result);


// ��ȡջ��Ԫ�ص�ֵ����������ջ����
// ������
// p: Stack�ĵ�ַ
// result: ���յ��������ݵı����ĵ�ַ
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status GetTopElement(Stack *p, ElementType *result);


// ��ȡջ��ǰ�ĳ���
// ������
// p: Stack�ĵ�ַ
// ����ֵ��
// ����ջ��ǰ�ĳ���
int GetLength(Stack *p);


// ���ջ�ռ�
// ������
// p: Stack�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearStack(Stack *p);

#endif