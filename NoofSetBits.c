#include<stdio.h>
int countbits(int num)
{
	int count = 0, n;
	while (num > 0){
		n = 0;
		while (num >= 1 << (n + 1))
			n++;
		num =num - (1 << n);
		count =count + (num + 1 + (1 << (n - 1))*n);
	}
	return count;
}
void main()
{
	int num;
	scanf("%d", &num);
	int a=0;
	a = countbits(num);
	printf("%d", a);
}