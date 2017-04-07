#include<stdio.h>
struct test
{
	int arr[10];
	int len;
	int expected;
}testDB[] = { { { 1, 2, 3, 4, 5 }, 4, 15 } , { { { 1, 1, 1, 1, 1 }, 4, 5 } } };
int arr_sum(int *arr, int n) {
	if (n < 0) {
		//base case:
		return 0;
	}
	else{
		return arr[n] + arr_sum(arr, n - 1);
	}
}
void main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	printf("%d", arr_sum(a, 4));
}