#include<stdio.h>
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permutations(char *arr,int i,int n)
{
	int j=0;
	if (i == n)
	{
		printf("%s\n", arr);
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			swap((arr + i), (arr + j));
			permutations(arr, i + 1, n);
			swap((arr + i), (arr + j));
		}
	}
}
void main()
{
	char arr[] = "123";
	permutations(arr,0,2);
}
