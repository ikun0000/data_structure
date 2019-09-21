/****************************************************/
/* project name: ArrayList                          */
/* create time: 2019-9-21                           */
/* modify time: 2019-9-21                           */
/* author: ikun000                                  */
/* version: v1.0                                    */
/****************************************************/

#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#define ERROR -1
#define OK 1

typedef int ElementType;

typedef struct _ArrayList {
	int length;                // ���Ա�ǰ��Ԫ�ظ���
	int size;                  // ���Ա������Ԫ�ظ���������
	ElementType *save_array;   // �洢���ݵĵ�ַ
} ArrayList, *PArrayList;


// ��ʼ��ArrayList
// ������
// p: ��Ҫ��ʼ����ArrayList�ĵ�ַ
// size: ArrayList��������
// ����ֵ��
// ����ERROR��ʾArrayList��ʼ��ʧ�ܣ�����OK��ʾ��ʼ���ɹ�
int InitArrayList(ArrayList *p, int size);


// ����ArrayList
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyArrayList(ArrayList *p);


// ��ָ��λ�ò���һ��Ԫ��
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// element: �����Ԫ��
// pos: �����λ�ã���1��ʼ��
// ����ֵ��
// ����ɹ�����OK�����򷵻�ERROR
int InsertElement(ArrayList *p, ElementType element, int pos);


// ɾ��ָ��λ�õ�Ԫ��
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// pos: ɾ����λ�ã���1��ʼ��
// result: ���ɾ��Ԫ�ص�ֵ�ĵ�ַ������ΪNULL
// ����ֵ��
// ɾ���ɹ�����OK�����򷵻�ERROR
int DeleteElement(ArrayList *p, int pos, ElementType *result);


// ��ȡָ��λ�õ�Ԫ��
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// pos: ɾ����λ�ã���1��ʼ��
// result: ���ɾ��Ԫ�ص�ֵ�ĵ�ַ������ΪNULL
// ����ֵ��
// ɾ���ɹ�����OK�����򷵻�ERROR
int GetElement(ArrayList *p, int pos, ElementType *result);


// �޸��ƶ�λ��Ԫ�ص�ֵ
// ������
// p: ��Ҫ���ٵ�ArrayList�ĵ�ַ
// newelement: �µ�Ԫ�ص�ֵ
// result: ���ɾ��Ԫ�ص�ֵ�ĵ�ַ������ΪNULL
// pos: �޸ĵ�λ�ã���1��ʼ��
// ����ֵ��
// ɾ���ɹ�����OK�����򷵻�ERROR
int ModifyElement(ArrayList *p, ElementType newelement, ElementType *result, int pos);


// ��ȡArrayList��length
// ������
// p: ��Ҫ��ȡlength��ArrayList�ĵ�ַ
// ����ֵ��
// ArrayList��length
int GetLength(ArrayList *p);


// ���ArrayList
// ������
// p: ��Ҫ�����ArrayList�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearArrayList(ArrayList *p);

#endif