/************************************************/
/* project name: LinearQueue                    */
/* create time: 2019-10-1                       */
/* modify time: 2019-10-1                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include "LinearQueue.h"
#include <stdlib.h>


// ��ʼ������
// ������
// p: LinearQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void InitLinearQueue(LinearQueue *p)
{
	p->length = 0;
	p->head = NULL;
	p->tail = NULL;
}


// ���ٶ���
// ������
// p: LinearQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyLinearQueue(LinearQueue *p)
{
	Node *temp;

	if (p->head != NULL)
	{
		temp = p->head->next;
		free(p->head);
		p->head = temp;
	}
}


// ����һ��Ԫ��
// ������
// p: LinearQueue�ĵ�ַ
// element: ������Ԫ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status AddElement(LinearQueue *p, ElementType element)
{
	Node *node = (Node *)malloc(sizeof(Node));

	if (node == NULL)
	{
		return ERROR;
	}

	if (0 == p->length)
	{
		p->head = node;
	}

	node->data = element;
	node->next = NULL;
	if (0 != p->length)
	{
		p->tail->next = node;
	}
	p->tail = node;
	p->length += 1;

	return OK;
}


// ɾ��һ��Ԫ��
// ������
// p: LinearQueue�ĵ�ַ
// result: ����ɾ��Ԫ�ص�ֵ�ı�����ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status RemoveElement(LinearQueue *p, ElementType *result)
{
	if (p->head == NULL)
	{
		return ERROR;
	}

	if (1 == p->length)
	{
		p->tail = NULL;
	}

	Node *node = p->head;
	if (result != NULL)
	{
		*result = p->head->data;
	}
	p->head = p->head->next;
	p->length -= 1;
	free(node);

	return OK;
}


// ��ȡ����Ԫ�ظ���
// ������
// p: LinearQueue�ĵ�ַ
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
int GetLength(LinearQueue *p)
{
	return p->length;
}


// �������
// ������
// ������
// p: LinearQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearLinearQueue(LinearQueue *p)
{
	Node *temp;

	while (p->head != NULL)
	{
		temp = p->head->next;
		free(p->head);
		p->head = temp;
	}

	p->tail = NULL;
	p->length = 0;
}