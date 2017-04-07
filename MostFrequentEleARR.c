#include<stdio.h>
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}
void quickSort(int A[], int l, int h)
{
	if (l < h)
	{
		int p = partition(A, l, h); 
		quickSort(A, l, p - 1);
		quickSort(A, p + 1, h);
	}
}
void main()
{
	int i = 0, arr[100];
	int n;
	int count = 0,max_count = 0;
	int index = 0;
	printf("Enter the size");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, n - 1);
	index = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count++;
			if (count > max_count)
			{
				count = max_count;
				index = i;
			}
		}
		else
			count = 0;
	}
	printf("%d", arr[index]);
}