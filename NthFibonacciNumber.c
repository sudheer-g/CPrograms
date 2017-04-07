#include<stdio.h>
struct test
{
	int InputNumber;
	int ExpectedOutput;
}testDB[] = { { 1, 0 }, { 1, 1 }, { 2, 1 }, { 3, 2 }, { 4, 3 }, { 5, 5 }, { -1, -1 }, { -5, -1 } };
int CheckInputNumber(int *InputNumber)
{
	if (*InputNumber <= 0)
	{
		*InputNumber = -1;
		return -1;
	}
	else if (*InputNumber == 1)
	{
		*InputNumber = 0;
		return -1;
	}
	else if (*InputNumber == 2)
	{
		*InputNumber = 1;
		return -1;
	}
	return 0;
}
void FindNthFibonacciNumberInTheSeries(int *FirstNumber,int *SecondNumber,int InputNumber,int *count,int *Output)
{
	int SumOfPreviousTwoNumbersInTheSeries=0;
	int VerifyFlag = 0;
	Output = CheckInputNumber(InputNumber);
	if (VerifyFlag == -1)
		return;
	if (*count == *InputNumber)
	{
		*InputNumber = *SecondNumber;
		printf("%d", *InputNumber);
		return;
	}
	SumOfPreviousTwoNumbersInTheSeries = *FirstNumber + *SecondNumber;
	*count++;
	FindNthFibonacciNumberInTheSeries(SecondNumber, &SumOfPreviousTwoNumbersInTheSeries, InputNumber, count);
}
void TestOutputWithExpectedOutput(int Output, int ExpectedOutput,int IndexIterator)
{
	if (Output == ExpectedOutput)
	{
		printf("\nTest Case %d Passed!\n", IndexIterator);
	}
	else
	{
		printf("\nTest Case %d Failed!\n", IndexIterator);
	}
}
void ExecuteTestCasesForNthFibonacciNumberInTheSeries()
{
	int InputNumber=0;
	int ExpectedOutput=0;
	int IndexIterator = 1;
	int FirstNumberInTheSeries = 0, SecondNumberInTheSeries = 1;
	int CountOfElementsInTheSeries = 2;
	int Output = 0;
	while (IndexIterator < 8)
	{
		InputNumber = testDB[IndexIterator].InputNumber;
		ExpectedOutput = testDB[IndexIterator].ExpectedOutput;
		FindNthFibonacciNumberInTheSeries(&FirstNumberInTheSeries,&SecondNumberInTheSeries,InputNumber,&CountOfElementsInTheSeries,&Output);
		TestOutputWithExpectedOutput(InputNumber, ExpectedOutput,IndexIterator+1);
		IndexIterator++;
	}
}
void main()
{
	ExecuteTestCasesForNthFibonacciNumberInTheSeries();
}