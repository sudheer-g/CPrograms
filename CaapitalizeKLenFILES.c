#include<stdio.h>
#include<string.h>
void main()
{
	int i = 0,k=0,j=0,count=0;
	FILE *fp1,*fp2;
	char text[100];
	fp1 = fopen("Capitalize.txt", "r");
	fp2 = fopen("Capitalize.txt", "w");
	if (fp1 == NULL)
	{
		printf("Cant open file\n");
		exit(0);
	}
	if (fp2 == NULL)
	{
		printf("Cant open File\n");
		exit(0);
	}
	while (fgets(text, 10, fp1) != NULL)
    {
		if (strlen(text) > 4)
		{
			fseek(fp1, -3, 1);
			while (text[i] != '\n')
			{
				text[i]=text[i] - 32;
				fputc(text[i], fp2);
				i++;
			}
		}
		else
		{
			fputs(text, fp2);
		}
		i = 0;
	}
	fclose(fp1);
	fclose(fp2);
}