#include<stdio.h>
#include<stdlib.h>
void PrintArray(int *Array, int len)
{
	int IndexIterator = 0;
	for (IndexIterator = 0; IndexIterator < len; IndexIterator++)
	{
		printf("%d ", Array[IndexIterator]);
	}
}
void UniqueElementCount(int *Array, int len)
{
	int IndexIterator = 0, ElementCount = 1;
	for (IndexIterator = 0; IndexIterator < len; IndexIterator++)
	{
		if (Array[IndexIterator] == Array[IndexIterator + 1])
		{
			ElementCount++;
		}
		else
		{
			printf("Number of %d's in the array : %d\n", Array[IndexIterator], ElementCount);
			ElementCount = 1;
		}
	}
}
void SwapElementsInAnArray(int *Array, int FirstIndex, int SecondIndex)
{
	int TemporaryVariable = 0;
	TemporaryVariable = Array[FirstIndex];
	Array[FirstIndex] = Array[SecondIndex];
	Array[SecondIndex] = TemporaryVariable;
}
void SortTwoMisplacedElementsInaSortedArray(int *Array, int len)
{
	int IndexIterator = 0, FirstIndex = 0, SecondIndex = 0, IndexFlag = 0;
	for (IndexIterator = 0; IndexIterator < len; IndexIterator++)
	{
		if ((Array[IndexIterator] > Array[IndexIterator + 1]) && (IndexFlag == 0))
		{
			FirstIndex = IndexIterator;
			IndexFlag = 1;
		}
		else if ((Array[IndexIterator] > Array[IndexIterator + 1]) && (IndexFlag == 1))
		{
			SecondIndex = IndexIterator + 1;
			break;
		}
	}
	if (IndexFlag == 1)
	{
		SwapElementsInAnArray(Array, FirstIndex, SecondIndex);
	}
	PrintArray(Array, len);
}
void ShiftArrayElements(int *Array, int len, int IndexToShift)
{
	int IndexIterator = 0;
	for (IndexIterator = len; IndexIterator >= IndexToShift; IndexIterator--)
	{
		Array[IndexIterator] = Array[IndexIterator - 1];
	}
}
void FindRequiredPlaceForAnElement(int *Array, int len,int *IndexIterator,int Element)
{
	for (*IndexIterator = 0; *IndexIterator < len; (*IndexIterator)++)
	{
		if ((Element >= Array[*IndexIterator]) && (Element <= Array[(*IndexIterator) + 1]))
		{
			break;
		}
	}
}
void PlaceElementInSortedArray(int *Array, int len, int Element)
{
	int IndexIterator = 0;
	if (Element <= Array[0])
	{
		ShiftArrayElements(Array, len, 1);
		Array[0] = Element;
	}
	else if (Element >= Array[len - 1])
	{
		Array[len] = Element;
	}
	else
	{
		FindRequiredPlaceForAnElement(Array, len, &IndexIterator, Element);
		ShiftArrayElements(Array, len, IndexIterator+1);
		Array[IndexIterator + 1] = Element;
	}
	PrintArray(Array, len + 1);
}
void FindOddRepeatedElementInArray(int *Array, int len)
{
	int X = 0;
	int IndexIterator = 0;
	for (IndexIterator = 0; IndexIterator < len; IndexIterator++)
	{
		X ^= Array[IndexIterator];
	}
	printf("%d", X);
}
void main()
{
	int Array[10] = {1,1,3,4,4,5,5};
	//UniqueElementCount(Array, 14);
	//SortTwoMisplacedElementsInaSortedArray(Array, 5);
	//PlaceElementInSortedArray(Array, 4,55);
	FindOddRepeatedElementInArray(Array, 7);
}