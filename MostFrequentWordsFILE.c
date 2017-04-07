#include<stdio.h>
void main()
{
	FILE *fp;
	fp = fopen("C:\\Users\\Sudheer\\Documents\\Visual Studio 2013\\Projects\\ParseHTML\\ParseHTML\\Parse.txt", "r");
	if (fp == NULL)
	{
		printf("Cant open File\n");
		exit(1);
	}


}