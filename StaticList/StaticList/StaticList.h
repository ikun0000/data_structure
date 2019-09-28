/************************************************/
/* project name: StaticList                     */
/* create time: 2019-9-27                       */
/* modify time: 2019-9-27                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/

#ifndef _STATICLIST_H
#define _STATICLIST_H

#define OK 0				// �ɹ�״̬��
#define ERROR -1			// ʧ��״̬��

typedef int ElementType;	// ����洢Ԫ�ص���������
typedef int Status;	


typedef struct _Node {
	ElementType data;			// �ڵ��������
	int cursor;					// �ڵ���α�
} Node, *PNode;


typedef struct _StaticList {
	Node *datas;				// �������α�Ĵ洢λ��
	int size;					// ��̬���������
} StaticList, *PStaticList;


// ��ʼ����̬����
// ������
// p: ��̬����ĵ�ַ
// size: ��̬���������
// ����ֵ��
// ��ʼ���ɹ�����OK�����򷵻�ERROR
Status InitStaticList(StaticList *p, int size);


// ���پ�̬����
// ������
// p: ��̬����ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyStaticList(StaticList *p);


// ��ָ��λ�ò���Ԫ��
// ������
// p: ��̬����ĵ�ַ
// element: �����Ԫ��
// pos: �����λ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InsertElement(StaticList *p, ElementType element, int pos);


// ɾ��ָ��λ�õ�Ԫ��
// ������
// p: ��̬����ĵ�ַ
// pos: ɾ����λ��
// result: ����ɾ��λ�õ�Ԫ�صĵ�ַ������ΪNULL
// ����ֵ��
// ɾ���ɹ�����OK�����򷵻�ERROR
Status DeleteElement(StaticList *p, int pos, ElementType *result);


// ��ȡָ��λ��Ԫ�ص�ֵ
// ������
// p: ��̬����ĵ�ַ
// pos: ��ȡԪ�ص�λ��
// result: ���ܻ�ȡԪ�صĵ�ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status GetElement(StaticList *p, int pos, ElementType *result);


// �޸��ƶ�λ�õ�Ԫ��
// ������
// p: ��̬����ĵ�ַ
// newelement: ��Ԫ�ص�ֵ
// result: ��ȡ��Ԫ�ص�ֵ�ĵ�ַ������ΪNULL
// pos: �޸ĵ�Ԫ�ص�λ��
// ����ֵ��
// �޸ĳɹ�����OK�����򷵻�ERROR
Status ModifyElement(StaticList *p, ElementType newelement, ElementType *result, int pos);


// ��ȡ��̬�����Ԫ������
// ������
// p: ��̬����ĵ�ַ
// ����ֵ��
// �˺������ؾ�̬�����Ԫ������
int GetLength(StaticList *p);


// ��վ�̬����
// ������
// p: ��̬����ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearStaticList(StaticList *p);


// �Ӿ�̬�����з���һ���洢�ռ�
// ������
// p: ��̬����ĵ�ַ
// ����ֵ��
// �ɹ����ش洢�ռ���±꣬���򷵻�ERROR
int staticlist_malloc(StaticList *p);


// �ͷž�̬�����һ���洢�ռ�
// ������
// p: ��̬����ĵ�ַ
// pos: �ͷŵ�λ�õ��±�
// ����ֵ
// �˺�������ʧ��
void staticlist_free(StaticList *p, int pos);


#endif