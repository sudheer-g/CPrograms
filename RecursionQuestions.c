#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int binarySearch(int *arr, int lower, int upper, int target)
{
	if (lower > upper || arr[lower]>arr[upper])
		return -1;
	if (arr[(lower+upper)/2] == target)
		return 1;
	if (arr[(lower + upper) / 2] > target)
		return binarySearch(arr, 0, ((lower + upper) / 2)-1, target);
	if (arr[(lower + upper) / 2] < target)
		return binarySearch(arr, ((lower + upper) / 2)+1, upper, target);

}
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void printPermutes(char *str, int length, int level)
{
	int i = 0;
	if (length == level)
	{
		printf("%s\n", str);
		return;
	}
	else
	{
		for (i = level; i <= length; i++)
		{
			swap((str+level), (str+i));
			printPermutes(str, length, level + 1);
			swap((str+level), (str+i));
		}
	}
}
int doAllFactorials(int *arr, int N, int recursionLevel)
{
	if (N > 1)
	{
		arr[recursionLevel] = N * doAllFactorials(arr, N - 1, recursionLevel + 1);
		return arr[recursionLevel];
	}
	else
	{
		arr[recursionLevel] = 1;
		return 1;
	}
}
void printArray(int *arr, int N)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d,", arr[i]);
}
void allFactorials(int N)
{
	if (N <= 0)
	{
		printf("1");
		return;
	}
	int *arr;
	int i;
	arr = (int *)malloc(N*sizeof(int));
	for (i = 0; i < N; i++)
		arr[i] = 0;
	doAllFactorials(arr, N, 0);
	printArray(arr, N);
}
void main()
{
	int N = 15;
	char str[] = "1234";
	//allFactorials(N);
	//int arr[] = {1,2,3,4,5};
	//printf("%d", binarySearch(arr, 0, 4, 5));
	printPermutes(str, 3, 0);
}

