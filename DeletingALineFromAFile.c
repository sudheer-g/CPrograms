/*#include<stdio.h>
void main()
{
	FILE *ReadPointer,*WritePointer;
	int LineNumber,LineCount=1;
	char ReadBuffer[100];
	ReadPointer=fopen("TestFile.txt", "r");
	WritePointer = fopen("TestFile.txt", "r+");
	while (fgets(ReadBuffer, 100, ReadPointer) != NULL)
	{
		if ((ReadBuffer[0] >= 'a') && (ReadBuffer[0] <= 'z'))
		{
			ReadBuffer[0] = ReadBuffer[0] - 32;
		}
			fputs(ReadBuffer, WritePointer);
	}
	fflush(WritePointer);
	fclose(ReadPointer);
	fclose(WritePointer);
}*/