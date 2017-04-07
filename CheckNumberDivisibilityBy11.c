#include<stdio.h>
struct test
{
	int InputNumber;
	int ExpectedOutput;
}testDB[] = { { 11, 1 }, { 2728, 1 }, { 31415, -1 }, { 10, -1 }, { 15, -1 }, { 0, 1 }, { -11, 1 } };
void PrintResultForDivisibilityBy11(int TestReturnValueForDivisibilityBy11, int ExpectedOutput,int IndexIterator)
{
	if (TestReturnValueForDivisibilityBy11 == ExpectedOutput)
	{
		printf("TestCase %d Passed!\n", IndexIterator + 1);
	}
	else
	{
		printf("TestCase %d Failed!\n", IndexIterator + 1);
	}
}
int TestDivisibilityBy11(int SumOfOddandEvenDigitsOfaNumber)
{
	if (SumOfOddandEvenDigitsOfaNumber % 11 == 0)
		return 1;
	else
		return -1;
}
int CheckEvenOrOddPositionandReturnValueOfTheDigit(int remainder, int PositionIndex)
{
	if (PositionIndex % 2 !=0)
	{
		 remainder=remainder*-1;
	}
	return remainder;
}
int FindSumOfOddandEvenDigitsOfaNumber(int TemporaryInputNumber)
{
	int SumOfOddandEvenDigitsOfaNumber = 0;
	int remainder = 0;
	int PositionIndex = 0;
	while (TemporaryInputNumber != 0)
	{
		remainder = TemporaryInputNumber % 10;
		SumOfOddandEvenDigitsOfaNumber = SumOfOddandEvenDigitsOfaNumber + CheckEvenOrOddPositionandReturnValueOfTheDigit(remainder,PositionIndex);
		TemporaryInputNumber = TemporaryInputNumber/10;
		PositionIndex++;
	}
	return SumOfOddandEvenDigitsOfaNumber;
}
void ExecuteTestCasesForDivisibilityby11Check()
{
	int TemporaryInputNumber = 0;
	int SumOfOddandEvenDigitsOfaNumber = 0;
	int IndexIterator = 0;
	int ExpectedOutput = 0;
	int TestReturnValueForDivisibilityBy11 = 0;
	while (IndexIterator < 7)
	{
		TemporaryInputNumber = testDB[IndexIterator].InputNumber;
		ExpectedOutput = testDB[IndexIterator].ExpectedOutput;
		SumOfOddandEvenDigitsOfaNumber = FindSumOfOddandEvenDigitsOfaNumber(TemporaryInputNumber);
		TestReturnValueForDivisibilityBy11=TestDivisibilityBy11(SumOfOddandEvenDigitsOfaNumber);
		PrintResultForDivisibilityBy11(TestReturnValueForDivisibilityBy11, ExpectedOutput,IndexIterator);
		IndexIterator++;
	}
}
void main()
{
	ExecuteTestCasesForDivisibilityby11Check();
}
