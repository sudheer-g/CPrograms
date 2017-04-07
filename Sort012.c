#include<stdio.h>
void CountNumbers(int *Array, int *CountArrayForNumbers, int Len)
{
	int IndexIterator = 0;
	for (IndexIterator = 0; IndexIterator < Len; IndexIterator++)
	{
		if (Array[IndexIterator] == 0)
		{
			CountArrayForNumbers[0]++;
		}
		else if (Array[IndexIterator] == 1)
		{
			CountArrayForNumbers[1]++;
		}
		else
		{
			CountArrayForNumbers[2]++;
		}
	}
}
void FillArray(int *Array, int Len, int ElementCount, int *IndexIterator,int Element)
{
	for (; (((*IndexIterator) < Len) && (ElementCount > 0)); (*IndexIterator)++, ElementCount--)
	{
		Array[(*IndexIterator)] = Element;
	}
}
void SortPositions(int *Array, int Len)
{
	int CountArrayForNumbers[] = { 0, 0, 0 };
	int IndexIterator = 0, ElementCount = 0;
	CountNumbers(Array, CountArrayForNumbers, Len);
	ElementCount = CountArrayForNumbers[0];
	FillArray(Array, Len, ElementCount, &IndexIterator,0);
	ElementCount = CountArrayForNumbers[1];
	FillArray(Array, Len, ElementCount, &IndexIterator, 1);
	ElementCount = CountArrayForNumbers[2];
	FillArray(Array, Len, ElementCount, &IndexIterator, 2);
}
void main()
{
	int Array[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2 };
	SortPositions(Array, 21);
	int i = 0;
	while (i < 21)
	{
		printf("%d", Array[i]);
		i++;
	}
}