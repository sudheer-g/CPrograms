#include<stdio.h>
#include<math.h>
struct test
{
	char ExpectedOutput;
	int FirstPointCoordinates[2];
	int SecondPointCoordinates[2];
	int ThirdPointCoordinates[2];
}testDB[] = { { 'I', { 1, 2 }, { 3, 3 }, { 1, 4 } },{ 'N', { 1, 1 }, { 2, 2 }, { 3, 3 } } };
void VerifyOutput(char AcquiredOutput, char ExpectedOutput,int IndexIterator)
{
	if (AcquiredOutput == ExpectedOutput)
	{
		printf("Test Case %d Passed!\n", IndexIterator + 1);
		return;
	}
	else
	{
		printf("Test Case %d Failed!\n", IndexIterator + 1);
	}
}
int SquareTheNumber(int Number)
{
	return Number*Number;
}
float FindLengthOfTheLine(int FirstPoint[2], int SecondPoint[2])
{
	float LengthofTheLine = 0;
	int DifferenceBetweenXCoordinates = 0;
	int DifferenceBetweenYCoordinates = 0;
	DifferenceBetweenXCoordinates = abs(FirstPoint[0] - SecondPoint[0]);
	DifferenceBetweenYCoordinates = abs(FirstPoint[1] - SecondPoint[1]);
	DifferenceBetweenXCoordinates = SquareTheNumber(DifferenceBetweenXCoordinates);
	DifferenceBetweenYCoordinates = SquareTheNumber(DifferenceBetweenYCoordinates);
	LengthofTheLine = (float)sqrt(DifferenceBetweenXCoordinates + DifferenceBetweenYCoordinates);
	return LengthofTheLine;
}
char FindTypeOfTriangle(float FirstLineLength, float SecondLineLength, float ThirdLineLength)
{
	if ((FirstLineLength + SecondLineLength == ThirdLineLength) || (SecondLineLength + ThirdLineLength == FirstLineLength) || (FirstLineLength + ThirdLineLength == SecondLineLength))
	{
		return 'N';
	}
	if ((FirstLineLength == SecondLineLength) && (SecondLineLength == ThirdLineLength) && (FirstLineLength == ThirdLineLength))
	{
		return 'E';
	}
	else if ((FirstLineLength == SecondLineLength) && (SecondLineLength != ThirdLineLength))
	{
		return 'I';
	}
	else
	{
		return 'S';
	}

}
void ExecuteTestCasesForDeterminingTypeOfTriangle()
{
	int IndexIterator = 0;
	char ExpectedOutput = 0;
	char AcquiredOutput;
	int FirstPointCoordinates[2];
	int SecondPointCoordinates[2];
	int ThirdPointCoordinates[2];
	float FirstLineLength = 0;
	float SecondLineLength = 0;
	float ThirdLineLength = 0;
	while (IndexIterator < 2)
	{
		FirstPointCoordinates[0] = testDB[IndexIterator].FirstPointCoordinates[0];
		FirstPointCoordinates[1] = testDB[IndexIterator].FirstPointCoordinates[1];
		SecondPointCoordinates[0] = testDB[IndexIterator].SecondPointCoordinates[0];
		SecondPointCoordinates[1] = testDB[IndexIterator].SecondPointCoordinates[1];
		ThirdPointCoordinates[0] = testDB[IndexIterator].ThirdPointCoordinates[0];
		ThirdPointCoordinates[1] = testDB[IndexIterator].ThirdPointCoordinates[1];
		ExpectedOutput = testDB[IndexIterator].ExpectedOutput;
		FirstLineLength = FindLengthOfTheLine(FirstPointCoordinates, SecondPointCoordinates);
		SecondLineLength = FindLengthOfTheLine(SecondPointCoordinates, ThirdPointCoordinates);
		ThirdLineLength = FindLengthOfTheLine(FirstPointCoordinates, ThirdPointCoordinates);
		AcquiredOutput=FindTypeOfTriangle(FirstLineLength, SecondLineLength, ThirdLineLength);
		VerifyOutput(AcquiredOutput,ExpectedOutput,IndexIterator);
		IndexIterator++;
	}
}
void main()
{
	ExecuteTestCasesForDeterminingTypeOfTriangle();
}