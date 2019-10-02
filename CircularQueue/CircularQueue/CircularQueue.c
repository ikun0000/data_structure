/************************************************/
/* project name: CircularQueue                  */
/* create time: 2019-10-2                       */
/* modify time: 2019-10-2                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include "CircularQueue.h"
#include <stdlib.h>


// ��ʼ�����ζ���
// ������
// p: CircularQueue�ĵ�ַ
// size: ���ζ��е�����
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InitCircularQueue(CircularQueue *p, int size)
{
	p->datas = (ElementType *)malloc(sizeof(ElementType)* size);
	if (p->datas == NULL)
	{
		return ERROR;
	}

	p->head = 0;
	p->tail = 0;
	p->length = 0;
	p->size = size;

	return OK;
}


// ���ٻ��ζ���
// ������
// p: CircularQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyCircularQueue(CircularQueue *p)
{
	free(p->datas);
	p->datas = NULL;
}


// ���һ��Ԫ��
// ������
// p: CircularQueue�ĵ�ַ
// element: ��ӵ�Ԫ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status AddElement(CircularQueue *p, ElementType element)
{
	if (p->size == p->length)
	{
		return ERROR;
	}

	p->datas[p->tail] = element;
	if (0 == p->length)
	{
		p->head = p->tail;
	}
	p->tail += 1;
	p->tail %= p->size;
	p->length += 1;

	return OK;
}


// ɾ��һ��Ԫ��
// ������
// p: CircularQueue�ĵ�ַ
// result: ����ɾ����Ԫ��ֵ�ñ����ĵ�ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status RemoveElement(CircularQueue *p, ElementType *result)
{
	if (p->length == 0)
	{
		return ERROR;
	}

	if (result != NULL)
	{
		*result = p->datas[p->head];
	}
	p->head += 1;
	p->head %= p->size;
	p->length -= 1;

	return OK;
}


// ��ȡ���ζ��е�ǰ��Ԫ�ظ���
// ������
// p: CircularQueue�ĵ�ַ
// ����ֵ��
// ���ض���Ԫ�صĸ���
int GetLength(CircularQueue *p)
{
	return p->length;
}


// ��ջ��ζ���
// ������
// p: CircularQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearCircularQueue(CircularQueue *p)
{
	p->head = 0;
	p->tail = 0;
	p->length = 0;
}