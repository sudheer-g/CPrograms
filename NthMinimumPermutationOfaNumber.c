#include<stdio.h>
#define MAXSIZE 9
struct test
{
	char InputNumber[MAXSIZE];
	char ExpectedOutput[MAXSIZE];
	int RequiredMinimumPermutation;
}testDB[] = { { "12345678", "12345867", 5 }, { "12345789", "12345987", 6 }, { "87654321", "12345867", 5 }, { "1234", "1423", 5 },
{ "12345678", "87654321", 40320 }, { "12sdf", "", 1 }, { "1234", "", 30 }, { "1234", "1234", 1 }, { "12345678", "87654312",40319 } };
void strcpy(char *FirstString, char *SecondString)
{
	while (*SecondString != '\0')
	{
		*FirstString = *SecondString;
		FirstString++;
		SecondString++;
	}
	*FirstString = '\0';
}
int strcmp(char *FirstString, char *SecondString)
{
	for (; *FirstString == *SecondString; FirstString++, SecondString++)
		if (*FirstString == '\0')
			return 0;
	return ((*FirstString < *SecondString) ? -1 : +1);
}
void strrev(char *InputString,int LengthOfInputNumber)
{
	long int FirstIndex, SecondIndex;
	char TemporaryCharacterForSwap;

	for (FirstIndex = 0, SecondIndex = LengthOfInputNumber - 1; FirstIndex<SecondIndex; FirstIndex++, SecondIndex--) {
		TemporaryCharacterForSwap = InputString[FirstIndex];
		InputString[FirstIndex] = InputString[SecondIndex];
		InputString[SecondIndex] = TemporaryCharacterForSwap;
	}
}
int Factorial(int InputNumber)
{
	int FactorialOfTheNumber = 1;
	int Iterator = 1;
	if (InputNumber < 0)
	{
		return 0;
	}
	for (Iterator = 1; Iterator <= InputNumber; Iterator++)
	{
		FactorialOfTheNumber *= Iterator;
	}
	return FactorialOfTheNumber;
}
void TestOutputsWithExpectedOutputs(char *InputNumber,char *ExpectedOutput,int IndexIterator)
{
	if (strcmp(InputNumber, ExpectedOutput) == 0)
	{
		printf("\nTest Case %d Passed!\n", IndexIterator);
	}
	else
	{
		printf("\nTest Case %d Failed!\n", IndexIterator);
	}
}
void SwapElements(int FirstNumberIndex, int SecondNumberIndex, char *list)
{
	int TemporaryNumberForSwap = 0;
	TemporaryNumberForSwap = list[FirstNumberIndex];
	list[FirstNumberIndex] = list[SecondNumberIndex];
	list[SecondNumberIndex] = TemporaryNumberForSwap;
}
int partition(char *InputString, int low, int high, int AscendingFlag)
{
	int PivotElement = InputString[high];
	int IndexIterator = (low - 1);

	for (int PartitionIterator = low; PartitionIterator <= high - 1; PartitionIterator++)
	{
		if (AscendingFlag == 0)
		{
			if (InputString[PartitionIterator] >= PivotElement)
			{
				IndexIterator++;
				SwapElements(IndexIterator, PartitionIterator, InputString);
			}
		}
		else
		{
			if (InputString[PartitionIterator] <= PivotElement)
			{
				IndexIterator++;
				SwapElements(IndexIterator, PartitionIterator, InputString);
			}
		}
	}
	SwapElements(IndexIterator + 1, high, InputString);
	return (IndexIterator + 1);
}

void QuickSort(char *InputString, int low, int high, int AscendingFlag)
{
	if (low < high)
	{
		int PartitionIndex = partition(InputString, low, high, AscendingFlag);
		QuickSort(InputString, low, PartitionIndex - 1, AscendingFlag);
		QuickSort(InputString, PartitionIndex + 1, high, AscendingFlag);
	}
}
int ValidDigitofANumber(char Digit)
{
	if ((Digit<'0') || (Digit>'9'))
		return 1;      //Returning 1 if Invalid
	return 0;
}
int ValidateNumber(char *FirstInputNumber)
{
	int IndexIterator = 0;
	int FirstValidNumberFlag = 0;
	int FirstValidFlag;
	if (FirstInputNumber[0] == '\0')
	{
		printf("Enter Valid Numbers!\n");
		return 1;
	}
	while (FirstInputNumber[IndexIterator] != '\0')
	{
		if (FirstValidFlag = (ValidDigitofANumber(FirstInputNumber[IndexIterator])) == 1)
		{
			printf("\nEnter Valid Number!\n");
			return 1;
		}
		IndexIterator++;
	}

	return 0;
}
void NullifyString(char *String)
{
	String[0] = '\0';
}
void BusinessLogicToCalculateNthMinimumPermutation(char *InputNumber, int RequiredMinimumPermutation,int LengthOfInputNumber)
{
	int FirstIndexForSwap = 0, SecondIndexForSwap = 0;
	int CountOfPermutations = 1;
	while (CountOfPermutations < RequiredMinimumPermutation)
	{
		FirstIndexForSwap = LengthOfInputNumber - 1;
		while (InputNumber[FirstIndexForSwap - 1] >= InputNumber[FirstIndexForSwap])
		{
			FirstIndexForSwap--;
		}
		SecondIndexForSwap = LengthOfInputNumber;
		while (InputNumber[SecondIndexForSwap - 1] <= InputNumber[FirstIndexForSwap - 1])
		{
			SecondIndexForSwap--;
		}
		// swap values at position FirstIndexForSwap-1 and SecondIndexForSwap-1
		SwapElements(FirstIndexForSwap - 1, SecondIndexForSwap - 1, InputNumber);
		FirstIndexForSwap++;
		SecondIndexForSwap = LengthOfInputNumber;
		while (FirstIndexForSwap < SecondIndexForSwap)
		{
			SwapElements(FirstIndexForSwap - 1, SecondIndexForSwap - 1, InputNumber);
			FirstIndexForSwap++;
			SecondIndexForSwap--;
		}
		CountOfPermutations++;
	}
}
void FindNthMinimumPermutationOfANumber(char *InputNumber, int RequiredMinimumPermutation)
{
	int LengthOfInputNumber = 0;
	int ValidationFlag = 0;
	int MaximumPossiblePermutations = 0;
	printf("The Input Number is:\n");
	LengthOfInputNumber = printf("%s", InputNumber);
	ValidationFlag=ValidateNumber(InputNumber);
	if (ValidationFlag == 1)
	{
		NullifyString(InputNumber);
		return;
	}
	QuickSort(InputNumber, 0, LengthOfInputNumber - 1, 1);
	if (RequiredMinimumPermutation == 1)
	{
		return;
	}
	MaximumPossiblePermutations = Factorial(LengthOfInputNumber);
	if (MaximumPossiblePermutations == RequiredMinimumPermutation)
	{
		strrev(InputNumber,LengthOfInputNumber);
		return;
	}
	BusinessLogicToCalculateNthMinimumPermutation(InputNumber, RequiredMinimumPermutation, LengthOfInputNumber);
}
void ExecuteTestCasesToFindNthMinimumPermutationOfANumber()
{
	int IndexIterator = 0;
	while (IndexIterator < 9)
	{
		FindNthMinimumPermutationOfANumber(testDB[IndexIterator].InputNumber, testDB[IndexIterator].RequiredMinimumPermutation);
		TestOutputsWithExpectedOutputs(testDB[IndexIterator].InputNumber, testDB[IndexIterator].ExpectedOutput,IndexIterator+1);
		IndexIterator++;
	}
}
void main()
{
	ExecuteTestCasesToFindNthMinimumPermutationOfANumber();
}