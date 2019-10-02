/************************************************/
/* project name: CircularQueue                  */
/* create time: 2019-10-2                       */
/* modify time: 2019-10-2                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#ifndef _CIRCULARQUEUE_H
#define _CIRCULARQUEUE_H


#define OK 0
#define ERROR -1

typedef int ElementType;			// ���д洢����������
typedef int Status;					// ״̬��


typedef struct _CircularQueue {
	ElementType *datas;				// ���еĴ洢�ռ�
	int head;						// ����ͷ�±�
	int tail;						// ����β�±�
	int size;						// ���е�����
	int length;						// ���е�Ԫ�ظ���
} CircularQueue, *PCircularQueue;


// ��ʼ�����ζ���
// ������
// p: CircularQueue�ĵ�ַ
// size: ���ζ��е�����
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status InitCircularQueue(CircularQueue *p, int size);


// ���ٻ��ζ���
// ������
// p: CircularQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void DestroyCircularQueue(CircularQueue *p);


// ���һ��Ԫ��
// ������
// p: CircularQueue�ĵ�ַ
// element: ��ӵ�Ԫ��
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status AddElement(CircularQueue *p, ElementType element);


// ɾ��һ��Ԫ��
// ������
// p: CircularQueue�ĵ�ַ
// result: ����ɾ����Ԫ��ֵ�ñ����ĵ�ַ������ΪNULL
// ����ֵ��
// �ɹ�����OK�����򷵻�ERROR
Status RemoveElement(CircularQueue *p, ElementType *result);


// ��ȡ���ζ��е�ǰ��Ԫ�ظ���
// ������
// p: CircularQueue�ĵ�ַ
// ����ֵ��
// ���ض���Ԫ�صĸ���
int GetLength(CircularQueue *p);


// ��ջ��ζ���
// ������
// p: CircularQueue�ĵ�ַ
// ����ֵ��
// �˺�������ʧ��
void ClearCircularQueue(CircularQueue *p);


#endif