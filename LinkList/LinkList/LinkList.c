/************************************************/
/* project name: LinkList                       */
/* create time: 2019-9-22                       */
/* modify time: 2019-9-22                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/

#include "LinkList.h"
#include <stdlib.h>


// ��ʼ������
// ������
// p: PLinkList�ĵ�ַ
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InitLinkList(PLinklist *p)
{
	*p = (LinkList *)malloc(sizeof(LinkList));
	if (*p == NULL)
	{
		return ERROR;
	}

	(*p)->element = 0;         // ����ͷ�ڵ��������Ϊ����ĳ���
	(*p)->next = NULL;
}


// ��������
// ������
// p: ���ٵ�����
// ����ֵ��
// �˺�������ʧ��
void DestroyLinkList(PLinklist p)
{
	PLinklist temp;
	while ( p != NULL )
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}


// ��ָ��λ�ò���Ԫ��
// ������
// p: ��Ҫ����Ԫ�ص�����
// element: �����Ԫ��
// pos: �����λ�ã���1��ʼ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InsertElement(PLinklist p, ElementType element, int pos)
{
	int i;

	if (pos < 1 || pos > p->element + 1)      // ���pos����Ч��
	{
		return ERROR;
	}
	
	PLinklist insert = (LinkList *)malloc(sizeof(LinkList));
	if (insert == NULL)
	{
		return ERROR;
	}
	p->element++;
	insert->element = element;

	for (i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}

	insert->next = p->next;
	p->next = insert;

	return OK;
}


// ɾ��ָ��λ�õ�Ԫ��
// ������
// p: ��Ҫɾ��Ԫ�ص�����
// pos: ɾ����λ�ã���1��ʼ��
// result: ��ŷ���Ԫ�صı�����ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status DeleteElement(PLinklist p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->element)             // ���pos����Ч��
	{
		return ERROR;
	}
	p->element--;

	int i;
	PLinklist temp;
	for (i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}

	temp = p->next;
	p->next = temp->next;

	if (result != NULL)
	{
		*result = temp->element;
	}
	free(temp);

	return OK;
}


// ��ȡָ��λ�õ�Ԫ��
// ������
// p: ��Ҫ��ȡԪ�ص�����
// pos: ��ȡԪ�ص�λ�ã���1��ʼ��
// result: ���շ���Ԫ�صı�����ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status GetElement(PLinklist p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->element)             // ���pos����Ч��
	{
		return ERROR;
	}

	int i;
	for (i = 0; i < pos; i++)
	{
		p = p->next;
	}

	if (result != NULL)
	{
		*result = p->element;
	}

	return OK;
}


// �޸�ָ��λ�õ�Ԫ��
// ������
// p: ��Ҫ�޸�Ԫ�ص�����
// newelement: �µ�Ԫ��ֵ
// result: ���վ�Ԫ��Ԫ��ֵ�ñ�����ַ������ΪNULL
// pos: �޸�Ԫ�ص�λ�ã���1��ʼ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status ModifyElement(PLinklist p, ElementType newelement, ElementType *result, int pos)
{
	if (pos < 1 || pos > p->element)             // ���pos����Ч��
	{
		return ERROR;
	}

	int i;
	for (i = 0; i < pos; i++)
	{
		p = p->next;
	}

	if (result != NULL)
	{
		*result = p->element;
	}
	p->element = newelement;

	return OK;
}


// ��ȡ�����Ԫ�ظ���
// ������
// p: ��ȡԪ�ظ���������
// ����ֵ��
// ����Ԫ�صĸ���
int GetLength(PLinklist p)
{
	return p->element;
}


// �������
// ������
// p: ��յ�����
// ����ֵ��
// �˺�������ʧ��
void ClearLinkList(PLinklist p)
{
	PLinklist temp = p;

	p->element = 0;
	p = p->next;
	temp->next = NULL;
	
	while (p != NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}