/************************************************/
/* project name: LinearQueue                    */
/* create time: 2019-10-1                       */
/* modify time: 2019-10-1                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinearQueue.h"

// 此函数仅用于测试LinearQueue
int main()
{
	LinearQueue lq;

	InitLinearQueue(&lq);

	srand((unsigned int)time(NULL));
	int i;
	for (i = 0; i < 10; i++)
	{
		int k = rand() % 100;
		AddElement(&lq, k);
		printf("%d\t", k);
	}
	printf("| length: %d\n", GetLength(&lq));


	for (int i = 0; i < 10; i++)
	{
		int k;
		RemoveElement(&lq, &k);
		printf("%d\t", k);
	}
	printf("| length: %d\n", GetLength(&lq));

	for (i = 0; i < 11; i++)
	{
		int k = rand() % 200;
		AddElement(&lq, k);
	}

	ClearLinearQueue(&lq);
	printf("| length: %d\n", GetLength(&lq));

	DestroyLinearQueue(&lq);

	AddElement(&lq, 11);
	AddElement(&lq, 22);
	AddElement(&lq, 33);
	AddElement(&lq, 44);
	AddElement(&lq, 55);
	AddElement(&lq, 66);
	RemoveElement(&lq, NULL);
	RemoveElement(&lq, NULL);
	// 33 44 55 66
	printf("| length: %d\n", GetLength(&lq));
	for (i = 0; i < 4; i++)
	{
		int k;
		RemoveElement(&lq, &k);
		printf("%d\t", k);
	}
	printf("| length: %d\n", GetLength(&lq));

	getchar();
	return 0;
}