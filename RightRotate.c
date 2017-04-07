#include<stdio.h>
void reverse(int *arr,int s,int n)
{
	int i = 0, j = 0,temp=0;
	for (i = s, j = n - 1; i <= j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
void brute_right_rotate(int *arr,int n,int k)
{
	int i = 0,r=0,temp;
	while (r < k)
	{
		temp = arr[n - 1];
		for (i = n-1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[i] = temp;
		r++;
	}
}
void rev_right_rotate(int *arr, int n, int k)
{
	reverse(arr, 0,n);
	reverse(arr, 0,k);
	reverse(arr, k, n);
}
void gcd_rotate(int *arr, int n)
{
         
}
void main()
{
	int i=0,arr[] = { 1, 2, 3, 4, 5 };
	//brute_right_rotate(arr,5, 2);
	rev_right_rotate(arr, 5, 3);
	for (i = 0; i < 5; i++)
		printf("%d", arr[i]);
}