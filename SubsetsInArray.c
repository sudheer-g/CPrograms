#include<stdio.h>
#include<math.h>
void PrintSubsets(int *Array,int len)
{
	int IndexIterator = 0;
	int SubSetCount = pow(2, len);
	int j;
	for (IndexIterator = 0; IndexIterator < SubSetCount; IndexIterator++)
	{
		for (j = 0; j < len; j++)
		{
			if (IndexIterator&(1 << j))
				printf("%d", Array[j]);
		}
		printf("\n");
	}
}
void main()
{
	int Array[] = { 1, 2, 3 };
	PrintSubsets(Array, 3);
}