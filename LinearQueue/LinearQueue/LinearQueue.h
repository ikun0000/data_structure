/************************************************/
/* project name: LinearQueue                    */
/* create time: 2019-10-1                       */
/* modify time: 2019-10-1                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#ifndef _LINEARQUEUE_H
#define _LINEARQUEUE_H


#define OK 0
#define ERROR -1

typedef int ElementType;
typedef int Status;


typedef struct _Node {
	ElementType data;		// ������
	struct _Node *next;		// ָ����
} Node, *PNode;

typedef struct _LinearQueue {
	int length;				// ����Ԫ�ظ���
	Node *head;				// ����ͷ
	Node *tail;				// ����β
} LinearQueue, *PLinearQueue;


// ��ʼ������
// ������
// p: LinearQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void InitLinearQueue(LinearQueue *p);


// ���ٶ���
// ������
// p: LinearQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyLinearQueue(LinearQueue *p);


// ����һ��Ԫ��
// ������
// p: LinearQueue�ĵ�ַ
// element: ������Ԫ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status AddElement(LinearQueue *p, ElementType element);


// ɾ��һ��Ԫ��
// ������
// p: LinearQueue�ĵ�ַ
// result: ����ɾ��Ԫ�ص�ֵ�ı�����ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status RemoveElement(LinearQueue *p, ElementType *result);


// ��ȡ����Ԫ�ظ���
// ������
// p: LinearQueue�ĵ�ַ
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
int GetLength(LinearQueue *p);


// �������
// ������
// ������
// p: LinearQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearLinearQueue(LinearQueue *p);

#endif