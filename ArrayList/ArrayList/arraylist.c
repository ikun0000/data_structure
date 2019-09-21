/****************************************************/
/* project name: ArrayList                          */
/* create time: 2019-9-21                           */
/* modify time: 2019-9-21                           */
/* author: ikun000                                  */
/* version: v1.0                                    */
/****************************************************/


#include "arraylist.h"
#include <stdlib.h>

// ��ʼ��ArrayList
// ������
// p: ��Ҫ��ʼ����ArrayList�ĵ�ַ
// size: ArrayList��������
// ����ֵ��
// ����ERROR��ʾArrayList��ʼ��ʧ�ܣ�����OK��ʾ��ʼ���ɹ�
int InitArrayList(ArrayList *p, int size)
{
	p->save_array = (ElementType)malloc(sizeof(ElementType) * size);
	if (p->save_array == NULL)
	{
		return ERROR;
	}
	
	p->size = size;
	p->length = 0;
	return OK;
}


// ����ArrayList
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyArrayList(ArrayList *p)
{
	free(p->save_array);
}


// ��ָ��λ�ò���һ��Ԫ��
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// element: �����Ԫ��
// pos: �����λ�ã���1��ʼ��
// ����ֵ��
// ����ɹ�����OK�����򷵻�ERROR
int InsertElement(ArrayList *p, ElementType element, int pos)
{
	if (pos < 1 || pos > p->length + 1)    // ���pos����Ч��
	{
		return ERROR;
	}
	if (p->length + 1 > p->size)           // ���ArrayList�Ƿ��пռ�
	{
		return ERROR;
	}

	int i;
	for (i = p->length - 1; i >= pos - 1 ; i--)
	{
		p->save_array[i + 1] = p->save_array[i];
	}
	p->save_array[pos - 1] = element;
	p->length++;

	return OK;
}


// ɾ��ָ��λ�õ�Ԫ��
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// pos: ɾ����λ�ã���1��ʼ��
// result: ���ɾ��Ԫ�ص�ֵ�ĵ�ַ������ΪNULL
// ����ֵ��
// ɾ���ɹ�����OK�����򷵻�ERROR
int DeleteElement(ArrayList *p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->length + 1)    // ���pos����Ч��
	{
		return ERROR;
	}
	if (p->length == 0)					   // ���ArrayList�Ƿ񻹿���ɾ��Ԫ��
	{
		return ERROR;
	}

	if (result != NULL) 
	{
		*result = p->save_array[pos - 1];
	}
	
	int i;
	for (i = pos - 1; i <= p->length - 1; i++)
	{
		p->save_array[i] = p->save_array[i + 1];
	}
	p->length--;

	return OK;
}


// ��ȡָ��λ�õ�Ԫ��
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// pos: ɾ����λ�ã���1��ʼ��
// result: ���ɾ��Ԫ�ص�ֵ�ĵ�ַ������ΪNULL
// ����ֵ��
// ɾ���ɹ�����OK�����򷵻�ERROR
int GetElement(ArrayList *p, int pos, ElementType *result)
{
	if (pos < 1 || pos > p->length + 1)    // ���pos����Ч��
	{
		return ERROR;
	}

	if (result != NULL)
	{
		*result = p->save_array[pos - 1];
	}

	return OK;
}


// �޸��ƶ�λ��Ԫ�ص�ֵ
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// newelement: �µ�Ԫ�ص�ֵ
// result: ���ɾ��Ԫ�ص�ֵ�ĵ�ַ������ΪNULL
// pos: �޸ĵ�λ�ã���1��ʼ��
// ����ֵ��
// ɾ���ɹ�����OK�����򷵻�ERROR
int ModifyElement(ArrayList *p, ElementType newelement, ElementType *result, int pos)
{
	if (pos < 1 || pos > p->length + 1)    // ���pos����Ч��
	{
		return ERROR;
	}

	if (result != NULL)
	{
		*result = p->save_array[pos - 1];
	}
	p->save_array[pos - 1] = newelement;

	return OK;
}


// ��ȡArrayList��length
// ������
// p: ��Ҫ��ȡlength��ArrayList�ĵ�ַ
// ����ֵ��
// ArrayList��length
int GetLength(ArrayList *p)
{
	return p->length;
}


// ���ArrayList
// ������
// p: ��Ҫ�����ArrayList�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearArrayList(ArrayList *p)
{
	p->length = 0;
}