/************************************************/
/* project name: CircularQueue                  */
/* create time: 2019-10-2                       */
/* modify time: 2019-10-2                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

// 此函数仅用于测试CircularQueue
int main()
{
	CircularQueue cq;

	InitCircularQueue(&cq, 10);

	srand((unsigned int)time(NULL));
	int i;
	for (i = 0; i < 10; i++)
	{
		int k = rand() % 200;
		AddElement(&cq, k);
		printf("%d\t", k);
	}
	printf("| length: %d\n", GetLength(&cq));

	RemoveElement(&cq, NULL);
	RemoveElement(&cq, NULL);
	RemoveElement(&cq, NULL);
	AddElement(&cq, 11);
	AddElement(&cq, 22);
	for (i = 0; i < 9; i++)
	{
		int k;
		RemoveElement(&cq, &k);
		printf("%d\t", k);
	}
	printf("| length: %d\n", GetLength(&cq));


	AddElement(&cq, 11);
	AddElement(&cq, 22);
	AddElement(&cq, 33);
	AddElement(&cq, 44);
	AddElement(&cq, 55);
	AddElement(&cq, 66);
	printf("| length: %d\n", GetLength(&cq));
	ClearCircularQueue(&cq);
	printf("| length: %d\n", GetLength(&cq));

	DestroyCircularQueue(&cq);

	getchar();
	return 0;
}