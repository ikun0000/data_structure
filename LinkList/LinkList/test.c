/************************************************/
/* project name: LinkList                       */
/* create time: 2019-9-22                       */
/* modify time: 2019-9-22                       */
/* author: ikun0000                             */
/* version: v1.0                                */
/************************************************/

#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 此函数仅用于测试LinkList
int main(int argc, char *argv[])
{
	PLinklist linklist = NULL;
	if (ERROR == InitLinkList(&linklist))
	{
		printf("Init failed!\n");
		return -1;
	}

	int i;
	srand((unsigned int)time(NULL));
	for (i = 1; i <= 12; i++)
	{
		int k = rand() % 100;
		printf("%d\t", k);
		InsertElement(linklist, k, i);
	}
	printf("| length: %d\n", GetLength(linklist));

	for (i = 1; i <= 12; i++)
	{
		ElementType et;
		GetElement(linklist, i, &et);
		printf("%d\t", et);
	}
	printf("| length: %d\n", GetLength(linklist));

	DeleteElement(linklist, 7, NULL);
	DeleteElement(linklist, 3, NULL);
	for (i = 1; i <= 10; i++)
	{
		ElementType et;
		GetElement(linklist, i, &et);
		printf("%d\t", et);
	}
	printf("| length: %d\n", GetLength(linklist));

	ModifyElement(linklist, 110, NULL, 10);
	ModifyElement(linklist, 120, NULL, 4);
	ModifyElement(linklist, 130, NULL, 40);
	for (i = 1; i <= 10; i++)
	{
		ElementType et;
		GetElement(linklist, i, &et);
		printf("%d\t", et);
	}
	printf("| length: %d\n", GetLength(linklist));
	
	
	ClearLinkList(linklist);
	printf("| length: %d\n", GetLength(linklist));

	DestroyLinkList(linklist);
	
	getchar();
	return 0;
}