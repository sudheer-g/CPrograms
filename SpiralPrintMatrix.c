#include<stdio.h>
void PrintSpiral(int(*Array)[4],int RowLen,int ColumnLen)
{
	int RowStart = 0, ColumnStart = 0;
	int RowEnd = RowLen, ColumnEnd = ColumnLen;
	int i = 0, j = 0;
	while ((RowStart < RowEnd) && (ColumnStart < ColumnEnd))
	{
		i = RowStart, j = ColumnStart;
		for (j = ColumnStart; j < ColumnEnd; j++)
		{
			printf("%d ", Array[i][j]);
		}
		j--;
		for (i = RowStart+1; i < RowEnd; i++)
		{
			printf("%d ", Array[i][j]);
		}
		i--;
		for (j = ColumnEnd - 1; j > ColumnStart; j--)
		{
			printf("%d ", Array[i][j]);
		}
		j++;
		for (i = RowEnd - 2; i > RowStart; i--)
		{
			printf("%d ", Array[i][j]);
		}
		RowStart++, ColumnStart++, RowEnd--, ColumnEnd--;
	}
}
void main()
{
	int m = 3, n = 4;
	int Array[][4] = { { 1, 2, 3,10 }, { 4, 5, 6,11 }, { 7, 8, 9,12 } };
	PrintSpiral(Array,m,n);
}