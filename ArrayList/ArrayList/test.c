/****************************************************/
/* project name: ArrayList                          */
/* create time: 2019-9-21                           */
/* modify time: 2019-9-21                           */
/* author: ikun0000                                 */
/* version: v1.0                                    */
/****************************************************/


#include <stdio.h>
#include "arraylist.h"
#include <stdlib.h>
#include <time.h>


// 此函数用于测试ArrayList
int main(int argc, char *argv[])
{
	ArrayList array_list;
	
	if (ERROR == InitArrayList(&array_list, 10))
	{
		return -1;
	}

	srand((unsigned int)time(NULL));
	int i;
	for (i = 1; i <= 10; i++)
	{
		int k = rand() % 100;
		printf("%d\t", k);
		InsertElement(&array_list, k, i);
	}
	
	printf("| length: %d\n", GetLength(&array_list));

	for (i = 1; i <= 10; i++)
	{
		ElementType a;
		GetElement(&array_list, i, &a);
		printf("%d\t", a);
	}

	printf("| length: %d\n", GetLength(&array_list));
	
	DeleteElement(&array_list, 3, NULL);
	for (i = 1; i <= 9; i++)
	{
		ElementType a;
		GetElement(&array_list, i, &a);
		printf("%d\t", a);
	}

	printf("| length: %d\n", GetLength(&array_list));

	DeleteElement(&array_list, 7, NULL);
	for (i = 1; i <= 8; i++)
	{
		ElementType a;
		GetElement(&array_list, i, &a);
		printf("%d\t", a);
	}

	printf("| length: %d\n", GetLength(&array_list));

	InsertElement(&array_list, 22, 5);
	for (i = 1; i <= 9; i++)
	{
		ElementType a;
		GetElement(&array_list, i, &a);
		printf("%d\t", a);
	}

	printf("| length: %d\n", GetLength(&array_list));

	for (i = 1; i <= 9; i++)
	{
		DeleteElement(&array_list, 1, NULL);
	}
	printf("| length: %d\n", GetLength(&array_list));

	InsertElement(&array_list, 11, 1);
	InsertElement(&array_list, 22, 2);
	InsertElement(&array_list, 33, 3);
	InsertElement(&array_list, 44, 3);
	InsertElement(&array_list, 55, 1);
	InsertElement(&array_list, 66, 30);
	// 55, 11, 22, 44, 33
	for (i = 1; i <= 5; i++)
	{
		ElementType g;
		GetElement(&array_list, i, &g);
		printf("%d\t", g);
	}
	printf("| length: %d\n", GetLength(&array_list));

	ClearArrayList(&array_list);
	if (OK == GetElement(&array_list, 3, NULL))
	{
		printf("ClearArrayList() failed!\n");
	}
	printf("| length: %d\n", GetLength(&array_list));

	DestroyArrayList(&array_list);
	getchar();
	return 0;
}
