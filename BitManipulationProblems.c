#include<stdio.h>
#include<stdlib.h>
void CheckEvenOrOdd(int num1)
{
	if (num1 & 1)
	{
		printf("Odd\n");
	}
	else
	{
		printf("Even\n");
	}
}
void SetNthBit(int num1,int n)
{
	num1 = num1 | (1 << n);
	printf("%d", num1);
}
void UnsetNthBit(int num1, int n)
{
	num1 = num1 & ~(1 << n);
	printf("%d", num1);
}
void UnsetRightMostBit(int num1)
{
	num1 = num1 & (num1 - 1);
	printf("\n%d", num1);
}
void IsolateRightMostBit(int num1)
{
	num1 = num1 & (-num1);
	printf("\n%d", num1);
}
void RightMostBitPropogate(int num1)
{
	num1 = num1 | (num1-1);
	printf("\n%d", num1);
}
void CountSetBits(int num1)
{
	int count=0;
	while (num1)
	{
		num1= num1 & (num1-1);
		count++;
	}
	printf("\n%d", count);
}
int UpdateBits(int n, int m, int i, int j)
{
	int AllOnes = ~0;
	int left = AllOnes << (j + 1);
	int right = ((1 << i) - 1);
	int mask = left | right;
	int n_cleared = n&mask;
	int m_shifted = m << i;
	return n_cleared | m_shifted;
}
int Add(int x, int y)
{
	if (y == 0)
		return x;
	else
		return Add(x ^ y, (x & y) << 1);
}
void main()
{
	int num1 = 12;
	int MergedNumber = 0;
	int Sum = 0;
	CheckEvenOrOdd(num1);
	UnsetNthBit(num1, 3);
	UnsetRightMostBit(num1);
	IsolateRightMostBit(12);
	RightMostBitPropogate(num1);
	CountSetBits(num1);
	MergedNumber = UpdateBits(1024, 19,3,7);
	printf("\n%d", MergedNumber);
	Sum = Add(2, 3);
	printf("\n%d", Sum);
}