/************************************************/
/* project name: Stack                          */
/* create time: 2019-9-30                       */
/* modify time: 2019-9-30                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include "Stack.h"
#include <stdlib.h>


// ��ʼ��ջ
// ������
// p: Stack�ĵ�ַ
// size: ��ʼ����ջ����
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InitStack(Stack *p, int size)
{
	p->base = (ElementType *)malloc(sizeof(ElementType)* size);
	if (p->base == NULL)
	{
		return ERROR;
	}

	p->size = size;
	p->top = 0;

	return OK;
}


// ����һ��ջ
// ������
// p: Stack�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyStack(Stack *p)
{
	free(p->base);
	p->base = NULL;
}


// ��ջ��ѹ������
// ������
// p: Stack�ĵ�ַ
// element: ѹ��ջ�����ݣ��ð汾��ջ֧�ֶ�̬���ݣ�
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status push(Stack *p, ElementType element)
{
	if (p->size == p->top)
	{
		ElementType *temp = (ElementType *)realloc(p->base, sizeof(ElementType) * p->size * 2);
		if (temp == NULL)
		{
			return ERROR;
		}

		p->base = temp;
		p->size *= 2;
	}

	p->base[p->top] = element;
	p->top += 1;

	return OK;
}


// ��ջ�е�������
// ������
// p: Stack�ĵ�ַ
// result: ���յ��������ݵı����ĵ�ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status pop(Stack *p, ElementType *result)
{
	if (p->top <= 0)
	{
		return ERROR;
	}

	p->top -= 1;
	if (result != NULL)
	{
		*result = p->base[p->top];
	}

	return OK;
}


// ��ȡջ��Ԫ�ص�ֵ����������ջ����
// ������
// p: Stack�ĵ�ַ
// result: ���յ��������ݵı����ĵ�ַ
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status GetTopElement(Stack *p, ElementType *result)
{
	if (p->top <= 0)
	{
		return ERROR;
	}

	*result = p->base[p->top - 1];

	return OK;
}


// ��ȡջ��ǰ�ĳ���
// ������
// p: Stack�ĵ�ַ
// ����ֵ��
// ����ջ��ǰ�ĳ���
int GetLength(Stack *p)
{
	return p->top;
}


// ���ջ�ռ�
// ������
// p: Stack�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearStack(Stack *p)
{
	p->top = 0;
}