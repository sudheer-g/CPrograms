#include<stdio.h>
struct test
{
	int InputNumber;
	int ExpectedSum;
}testDB[] = { { 12, 3 }, { 123, 6 }, { 55555, 25 }, { 0, 0 }, {-123,6} };
int CheckNegativity(int TemporaryInputNumber)
{
	if (TemporaryInputNumber < 0)
	{
		TemporaryInputNumber = TemporaryInputNumber*-1;
	}
	return TemporaryInputNumber;
}
int FindSumOfIndividualDigitsOfaNumber(int TemporaryInputNumber)
{
	int remainder = 0;
	int SumOfIndividualDigitsOfaNumber = 0;
	TemporaryInputNumber = CheckNegativity(TemporaryInputNumber);
	while (TemporaryInputNumber > 0)
	{
		remainder = TemporaryInputNumber % 10;
		SumOfIndividualDigitsOfaNumber = SumOfIndividualDigitsOfaNumber + remainder;
		TemporaryInputNumber = TemporaryInputNumber / 10;
	}
	return SumOfIndividualDigitsOfaNumber;
}
void VerifySumOfIndividualDigitsOfaNumber(int SumOfIndividualDigitsOfaNumber, int ExpectedSum, int TestCaseNumber)
{
	if (SumOfIndividualDigitsOfaNumber == ExpectedSum)
	{
		printf("TestCase %d Passed!\n",TestCaseNumber+1);
	}
	else
	{
		printf("TestCase %d Failed!\n", TestCaseNumber + 1);
	}
}
void ExecuteTestCasesForSumOfIndividualDigitsOfaNumber()
{
	
	int TemporaryInputNumber = 0;
	int SumOfIndividualDigitsOfaNumber = 0;
	int IndexIterator = 0;
	int ExpectedSum = 0;
	while (IndexIterator <= 4)
	{
		TemporaryInputNumber = testDB[IndexIterator].InputNumber;
		SumOfIndividualDigitsOfaNumber = FindSumOfIndividualDigitsOfaNumber(TemporaryInputNumber);
		ExpectedSum = testDB[IndexIterator].ExpectedSum;
		VerifySumOfIndividualDigitsOfaNumber(SumOfIndividualDigitsOfaNumber, ExpectedSum, IndexIterator);
		IndexIterator++;
	}
}
void main()
{
	ExecuteTestCasesForSumOfIndividualDigitsOfaNumber();
}
