/************************************************/
/* project name: StaticList                     */
/* create time: 2019-9-27                       */
/* modify time: 2019-9-27                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include "StaticList.h"
#include <stdlib.h>


// ��ʼ����̬����
// ������
// p: ��̬����ĵ�ַ
// size: ��̬���������
// ����ֵ��
// ��ʼ���ɹ�����OK�����򷵻�ERROR
Status InitStaticList(StaticList *p, int size)
{
	p->size = size;
	p->datas = (Node *)malloc(sizeof(Node)* (size + 2));

	if (p->datas == NULL)
	{
		return ERROR;
	}

	p->datas[0].data = 0;			// ���徲̬�����ͷ�ڵ���������data��ž�̬�����Ԫ�ظ���
	p->datas[0].cursor = 1;			// ��̬�����ͷ�ڵ���α�ָ��������
	p->datas[size + 1].cursor = 0;		// ��û����Ч����������β�ڵ���α�ָ��ͷ�ڵ�
	p->datas[size + 1].data = size;	// ����β�ڵ��������Ϊ���������Ԫ������

	int i;
	for (i = 1; i < size + 1; i++)
	{
		p->datas[i].cursor = i + 1;
	}

	return OK;
}


// ���پ�̬����
// ������
// p: ��̬����ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyStaticList(StaticList *p)
{
	free(p->datas);
}


// ��ָ��λ�ò���Ԫ��
// ������
// p: ��̬����ĵ�ַ
// element: �����Ԫ��
// pos: �����λ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InsertElement(StaticList *p, ElementType element, int pos)
{
	if (pos < 1 || pos > p->datas[0].data + 1)		// ���pos����Ч��
	{
		return ERROR;
	}

	int index = staticlist_malloc(p);
	if (ERROR == index)			// ���û�л����Ч�±꣬��Ϊp->datas[0].data == p->size
	{
		return ERROR;
	}
	p->datas[index].data = element;

	int previous = p->size + 1;
	int i;
	for (i = 1; i < pos; i++)
	{
		previous = p->datas[previous].cursor;
	}

	p->datas[index].cursor = p->datas[previous].cursor;
	p->datas[previous].cursor = index;
	p->datas[0].data += 1;

	return OK;
}


// ɾ��ָ��λ�õ�Ԫ��
// ������
// p: ��̬����ĵ�ַ
// pos: ɾ����λ��
// result: ����ɾ��λ�õ�Ԫ�صĵ�ַ������ΪNULL
// ����ֵ��
// ɾ���ɹ�����OK�����򷵻�ERROR
Status DeleteElement(StaticList *p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->datas[0].data)		// ���pos����Ч��
	{
		return ERROR;
	}

	if (0 == p->datas[0].data)
	{
		return ERROR;
	}

	int previous = p->size + 1;
	int i;
	for (i = 1; i < pos; i++)
	{
		previous = p->datas[previous].cursor;
	}

	int deleteindex = p->datas[previous].cursor;
	if (result != NULL)
	{
		*result = p->datas[deleteindex].data;
	}
	p->datas[previous].cursor = p->datas[deleteindex].cursor;

	p->datas[0].data -= 1;
	staticlist_free(p, deleteindex);

	return OK;
}


// ��ȡָ��λ��Ԫ�ص�ֵ
// ������
// p: ��̬����ĵ�ַ
// pos: ��ȡԪ�ص�λ��
// result: ���ܻ�ȡԪ�صĵ�ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status GetElement(StaticList *p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->datas[0].data)		// ���pos����Ч��
	{
		return ERROR;
	}

	int index = p->size + 1;
	int i;
	for (i = 0; i < pos; i++)
	{
		index = p->datas[index].cursor;
	}

	if (result != NULL)
	{
		*result = p->datas[index].data;
	}

	return OK;
}


// �޸��ƶ�λ�õ�Ԫ��
// ������
// p: ��̬����ĵ�ַ
// newelement: ��Ԫ�ص�ֵ
// result: ��ȡ��Ԫ�ص�ֵ�ĵ�ַ������ΪNULL
// pos: �޸ĵ�Ԫ�ص�λ��
// ����ֵ��
// �޸ĳɹ�����OK�����򷵻�ERROR
Status ModifyElement(StaticList *p, ElementType newelement, ElementType *result, int pos)
{
	if (pos < 1 || pos > p->datas[0].data)		// ���pos����Ч��
	{
		return ERROR;
	}

	int index = p->size + 1;
	int i;
	for (i = 0; i < pos; i++)
	{
		index = p->datas[index].cursor;
	}

	if (result != NULL)
	{
		*result = p->datas[index].data;
	}
	p->datas[index].data = newelement;

	return OK;
}


// ��ȡ��̬�����Ԫ������
// ������
// p: ��̬����ĵ�ַ
// ����ֵ��
// �˺������ؾ�̬�����Ԫ������
int GetLength(StaticList *p)
{
	return p->datas[0].data;
}


// ��վ�̬����
// ������
// p: ��̬����ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearStaticList(StaticList *p)
{
	p->datas[0].data = 0;			// ���徲̬�����ͷ�ڵ���������data��ž�̬�����Ԫ�ظ���
	p->datas[0].cursor = 1;			// ��̬�����ͷ�ڵ���α�ָ��������
	p->datas[p->size + 1].cursor = 0;		// ��û����Ч����������β�ڵ���α�ָ��ͷ�ڵ�
	p->datas[p->size + 1].data = p->size;	// ����β�ڵ��������Ϊ���������Ԫ������

	int i;
	for (i = 1; i < p->size + 1; i++)
	{
		p->datas[i].cursor = i + 1;
	}

	return OK;
}


// �Ӿ�̬�����з���һ���洢�ռ�
// ������
// p: ��̬����ĵ�ַ
// ����ֵ��
// �ɹ����ش洢�ռ���±꣬���򷵻�ERROR
int staticlist_malloc(StaticList *p)
{
	if (0 == p->datas[p->size + 1].data)		// ����Ƿ��пռ�
	{
		return ERROR;
	}
	p->datas[p->size + 1].data -= 1;

	int result = p->datas[0].cursor;
	if (0 == p->datas[p->size + 1].data)
	{
		p->datas[0].cursor = p->size + 1;			// �ڱ�������Ϊ��ʱͷ�ڵ���α�ָ��β�ڵ�
	}
	else
	{
		p->datas[0].cursor = p->datas[result].cursor;
	}

	return result;
}


// �ͷž�̬�����һ���洢�ռ�
// ������
// p: ��̬����ĵ�ַ
// pos: �ͷŵ�λ�õ��±�
// ����ֵ
// �˺�������ʧ��
void staticlist_free(StaticList *p, int pos)
{
	if (p->size == p->datas[p->size + 1].data)
	{
		return;
	}

	p->datas[p->size + 1].data += 1;
	p->datas[pos].cursor = p->datas[0].cursor;
	p->datas[0].cursor = pos;
}


