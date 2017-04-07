#include<stdio.h>
#include<stdlib.h>
struct test
{
	int InputArray[10];
	int ArrayLength;
	int ExpectedMaxElement;
	int ExpectedSecondMaxElement;
}testDB[] = { { { 1, 2, 3, 4, 5 },5, 5, 4 }, { { 0 },1, 0, 0 }, { { 5, 4, 3, 2, 1 },5, 5, 4 }, { { 1, 1 },2, 1, 1 }, { { 1, 2 },2, 2, 1 }, { {-1,-2,-3},3,-1,-2 } };
void TestOutputWithExpectedOutput(int MaxElement, int SecondMaxElement, int ExpectedMaxElement, int ExpectedSecondMaxElement, int IndexIterator)
{
	if ((MaxElement == ExpectedMaxElement) && (SecondMaxElement == ExpectedSecondMaxElement))
	{
		printf("Test case %d Passed!\n", IndexIterator);
	}
	else
	{
		printf("Test case %d Failed!\n", IndexIterator);
	}
	return;
}
void InitializeMaxElementBasedOnArrayLength(int ArrayLength, int *MaxElement, int *SecondMaxElement,int *InputArray)
{
	int TemporaryVariableForSwap=0;
	if (ArrayLength == 1)
	{
		*MaxElement = InputArray[0];
		*SecondMaxElement = InputArray[0];
	}
	if (ArrayLength >= 2)
	{
		*MaxElement = InputArray[0];
		*SecondMaxElement = InputArray[1];
		if (*SecondMaxElement > *MaxElement)
		{
			TemporaryVariableForSwap=*MaxElement;
			*MaxElement = *SecondMaxElement;
			*SecondMaxElement = TemporaryVariableForSwap;
		}
	}
	return;

}
void FindMaxandSecondMaxInAnArray(int *InputArray, int *MaxElement,int *SecondMaxElement,int ArrayLength)
{
	int IndexIterator = 0;
	InitializeMaxElementBasedOnArrayLength(ArrayLength,MaxElement,SecondMaxElement,InputArray);
	if (ArrayLength < 2)
		return;
	for (IndexIterator = 2; IndexIterator < ArrayLength; IndexIterator++)
	{
		if ((InputArray[IndexIterator]>*MaxElement) || (InputArray[IndexIterator]>*SecondMaxElement))
		{
			if (InputArray[IndexIterator] > *MaxElement)
			{
				*SecondMaxElement = *MaxElement;
				*MaxElement = InputArray[IndexIterator];
			}
			else
				*SecondMaxElement = InputArray[IndexIterator];
		}
	}
	//printf("%d %d", *MaxElement, *SecondMaxElement);
}
void ExecuteTestCasesForFindingMaxTwoInanArray()
{
	int IndexIterator = 0;
	int ArrayLength = 0;
	int *InputArray;
	int ArrayIterator = 0;
	int MaxElement=0, SecondMaxElement=0;
	int ExpectedMaxElement = 0, ExpectedSecondMaxElement = 0;
	while (IndexIterator < 6)
	{
		ArrayLength = testDB[IndexIterator].ArrayLength;
		ExpectedMaxElement = testDB[IndexIterator].ExpectedMaxElement;
		ExpectedSecondMaxElement = testDB[IndexIterator].ExpectedSecondMaxElement;
		InputArray = (int *)malloc(ArrayLength*sizeof(int));
		while (ArrayIterator < ArrayLength)
		{
			InputArray[ArrayIterator++] = testDB[IndexIterator].InputArray[ArrayIterator];
		}
		ArrayIterator = 0;
		FindMaxandSecondMaxInAnArray(InputArray, &MaxElement, &SecondMaxElement,ArrayLength);
		TestOutputWithExpectedOutput(MaxElement, SecondMaxElement, ExpectedMaxElement, ExpectedSecondMaxElement,IndexIterator+1);
		IndexIterator++;
		free(InputArray);
	}
}
void main()
{
	ExecuteTestCasesForFindingMaxTwoInanArray();
}