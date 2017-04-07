#include<stdio.h>
void allSubsets(int *s, int k, int n, int *a)
{
	int j = 0;
	if (k == n)
	{
		for (j= 0; j < n; j++){
			if (s[j] != 0){
				printf("%d", a[j]);
			}
		}
		printf("\n");
		return;
	}
	s[k] = 1;
	allSubsets(s, k + 1, n, a);
	s[k] = 0;
	allSubsets(s, k + 1, n, a);
}
void main()
{
	int i = 0;
	int a[20]; //= { 1, 2, 3, 4, 5 };
	printf("Enter the size:\n");
	int n;//=5;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int s[20]; 
	printf("The subsets are:\n");
	allSubsets(s, 0, n, a);
}
