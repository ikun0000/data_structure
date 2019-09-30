/************************************************/
/* project name: StaticList                     */
/* create time: 2019-9-30                       */
/* modify time: 2019-9-30                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"


// 此函数仅用于测试Stack
int main()
{
	Stack st;
	InitStack(&st, 5);

	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 9; i++)
	{
		int k = rand() % 100;

		push(&st, k);

		printf("%d\t", k);
	}
	printf("| length: %d\n", GetLength(&st));

	int result;
	GetTopElement(&st, &result);
	printf("Top element: %d, length: %d\n", result, GetLength(&st));

	while (pop(&st, &result) == OK )
	{
		printf("%d\t", result);
	}
	printf("| length: %d\n", GetLength(&st));


	DestroyStack(&st);

	getchar();
	return 0;
}