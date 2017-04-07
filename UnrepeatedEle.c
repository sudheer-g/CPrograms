#include <stdio.h>
int single(int a[],int n) {

	int ones = 0, twos = 0;

	for (int i = 0; i < n; i++){

		ones = (ones ^ a[i]) & ~twos;

		twos = (twos ^ a[i]) & ~ones;

	}

	return ones;
}
void main()
{
	int n, i = 0,a[100],num=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	num=single(a, n);
	printf("%d", num);
}