/************************************************/
/* project name: StaticList                     */
/* create time: 2019-9-27                       */
/* modify time: 2019-9-27                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "StaticList.h"

// 此函数仅用于测试StaticList
int main()
{
	StaticList sl;
	InitStaticList(&sl, 5);
	
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 6; i++)
	{
		int k = rand() % 100;
		InsertElement(&sl, k, i + 1);
		printf("%d\t", k);
	}
	printf("|length: %d\n", GetLength(&sl));


	for (i = 1; i <= 5; i++)
	{
		int k;
		GetElement(&sl, i, &k);
		printf("%d\t", k);
	}
	printf("|length: %d\n", GetLength(&sl));


	DeleteElement(&sl, 1, NULL);
	DeleteElement(&sl, 3, NULL);
	for (i = 1; i <= 3; i++)
	{
		int k;
		GetElement(&sl, i, &k);
		printf("%d\t", k);
	}
	printf("|length: %d\n", GetLength(&sl));
	
	InsertElement(&sl, 11, 4);
	InsertElement(&sl, 22, 1);
	for (i = 1; i <= 5; i++)
	{
		int k;
		GetElement(&sl, i, &k);
		printf("%d\t", k);
	}
	printf("|length: %d\n", GetLength(&sl));

	ModifyElement(&sl, 33, NULL, 3);
	for (i = 1; i <= 5; i++)
	{
		int k;
		GetElement(&sl, i, &k);
		printf("%d\t", k);
	}
	printf("|length: %d\n", GetLength(&sl));

	ClearStaticList(&sl);

	if (ERROR == GetElement(&sl, 1, NULL))
	{
		printf("GetElement success | length: %d\n", GetLength(&sl));
	}

	InsertElement(&sl, 99, 1);
	InsertElement(&sl, 88, 2);
	InsertElement(&sl, 77, 9);
	InsertElement(&sl, 66, 2);
	InsertElement(&sl, 55, 3);
	InsertElement(&sl, 44, 1);
	InsertElement(&sl, 33, 3);
	// 44 99 66 55 88 
	for (i = 1; i <= 5; i++)
	{
		int k;
		GetElement(&sl, i, &k);
		printf("%d\t", k);
	}
	printf("|length: %d\n", GetLength(&sl));

	DestroyStaticList(&sl);
	getchar();
	return 0;
}