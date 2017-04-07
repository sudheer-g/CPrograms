#include<stdio.h>
int binarysearch_modified(int a[], int num, int x, int index)
{
	int low, high, mid;
	low = 0;
	high = x - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num < a[mid])
			high = mid - 1;
		else if (num>a[mid])
			low = mid + 1;
		else
			return 1;
	}
	return -1;
}
int right_binary_search(int *arr, int low, int high,int key,int size)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (((mid == size - 1) && (arr[mid] == key)) || ((arr[mid] == key) && (arr[mid] < arr[mid + 1])))
	{
		printf("%d", mid);
		return mid;
	}
	else
	{
		if (arr[mid] > key)
			return right_binary_search(arr, low, mid - 1, key, size);
		else
			return right_binary_search(arr, mid+1, high, key, size);
	}
}
void main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	right_binary_search(arr, 0, 5, 4, 5);
}