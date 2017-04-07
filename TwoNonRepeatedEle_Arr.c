#include <stdio.h>
#include <stdlib.h>
void find(int arr[], int n)
{
	int x = 0, y = 0;
	int xor = arr[0];
	int bit; 
	int i;

	for (i = 1; i < n; i++)
		xor ^= arr[i];

	bit = xor & ~(xor - 1);

	for (i = 0; i < n; i++)
	{
		if (arr[i] & bit)
			x = x ^ arr[i]; 
		else
			y = y ^ arr[i];
	}
	printf("The non-repeating elements are %d and %d", x, y);
	
}
void main()
{
	int a[100], i = 0, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	find(a, n);
}