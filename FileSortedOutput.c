#include<stdio.h>
int strcmp(char *str1, char *str2)
{
	int i = 0;
	while ((str1[i] != '\0') && (str2[i] != '\0'))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return str1[i] - str2[i];
	}
	return 0;
}
void main()
{
	int i = 0,j=0,k=0,m=0,count=0;
	FILE *fp,*op;
	char text[100];
	char word[100][100];
	fp=fopen("words.txt", "r");
	if (fp == NULL)
	{
		printf("Cant open File\n");
		exit(0);
	}
	op = fopen("output.txt", "w");
	if (op == NULL)
	{
		printf("Cant open File\n");
		exit(0);
	}
	if (fgets(text, 100, fp) != NULL)
	{
		for (i = 0; text[i] != '\0'; i++)
		{
			if (text[i] != ',')
			{
				word[k][j++] = text[i];
			}
			else
			{
				word[k][j] = '\0';
				j = 0;
				k++;
				count++;
			}
		}
	}
	for (k = 0; k < count; k++)
	{
		for (m = k + 1; m < count; m++)
		{
			printf("%d\n", strcmp(word[k], word[m]));
		}
	}
	fclose(fp);
	fclose(op);
}