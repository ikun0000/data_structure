/************************************************/
/* project name: LinkList                       */
/* create time: 2019-9-22                       */
/* modify time: 2019-9-22                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define ERROR -1	
#define OK 0

typedef int ElementType;
typedef int Status;

typedef struct linklist {
	ElementType element;			// �����������
	struct linklist *next;          // �����ָ����
} LinkList, *PLinklist;


// ��ʼ������
// ������
// p: PLinkList�ĵ�ַ
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InitLinkList(PLinklist *p);


// ��������
// ������
// p: ���ٵ�����
// ����ֵ��
// �˺�������ʧ��
void DestroyLinkList(PLinklist p);


// ��ָ��λ�ò���Ԫ��
// ������
// p: ��Ҫ����Ԫ�ص�����
// element: �����Ԫ��
// pos: �����λ�ã���1��ʼ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InsertElement(PLinklist p, ElementType element, int pos);


// ɾ��ָ��λ�õ�Ԫ��
// ������
// p: ��Ҫɾ��Ԫ�ص�����
// pos: ɾ����λ�ã���1��ʼ��
// result: ��ŷ���Ԫ�صı�����ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status DeleteElement(PLinklist p, int pos, ElementType *result);


// ��ȡָ��λ�õ�Ԫ��
// ������
// p: ��Ҫ��ȡԪ�ص�����
// pos: ��ȡԪ�ص�λ�ã���1��ʼ��
// result: ���շ���Ԫ�صı�����ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status GetElement(PLinklist p, int pos, ElementType *result);


// �޸�ָ��λ�õ�Ԫ��
// ������
// p: ��Ҫ�޸�Ԫ�ص�����
// newelement: �µ�Ԫ��ֵ
// result: ���վ�Ԫ��Ԫ��ֵ�ñ�����ַ������ΪNULL
// pos: �޸�Ԫ�ص�λ�ã���1��ʼ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status ModifyElement(PLinklist p, ElementType newelement, ElementType *result, int pos);


// ��ȡ�����Ԫ�ظ���
// ������
// p: ��ȡԪ�ظ���������
// ����ֵ��
// ����Ԫ�صĸ���
int GetLength(PLinklist p);


// �������
// ������
// p: ��յ�����
// ����ֵ��
// �˺�������ʧ��
void ClearLinkList(PLinklist p);

#endif