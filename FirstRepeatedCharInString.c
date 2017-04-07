#include<stdio.h>
int LookInHashArray(int *HashArray, char Character)
{
	if (HashArray[Character] == 1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void PrintResult(char Character)
{
	printf("The Result is %c\n", Character);
	return;
}
void InsertInHashArray(int *HashArray, char Character)
{
	HashArray[Character] = 1;
	return;
}
void FirstRepeatedChar(char *InputString)
{
	if (InputString[0] == '\0')
		return;
	int HashArray[256] = { 0 }, IndexIterator = 0, LookUpFlag = 0;
	for (IndexIterator = 0; InputString[IndexIterator] != '\0'; IndexIterator++)
	{
		if ((LookUpFlag=LookInHashArray(HashArray, InputString[IndexIterator])) == 1)
		{
			PrintResult(InputString[IndexIterator]);
			return;
		}
		else
		{
			InsertInHashArray(HashArray, InputString[IndexIterator]);
		}
	}
}
void main()
{
	FirstRepeatedChar("acaczb");
}