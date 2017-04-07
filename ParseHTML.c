#include<stdio.h>
void main()
{
	FILE *fp1, *fp2;
	char ch;
	int flag = 0,check=0,count=0;
	fp1 = fopen("parser.txt", "r");
	fp2 = fopen("Parse.txt", "w");
	if (fp1 == NULL)
	{
		printf("Cant open File\n");
		exit(1);
	}
	if (fp2 == NULL)
	{
		printf("Cant open File\n");
		exit(2);
	}
	while ((ch=fgetc(fp1)) != EOF)
	{
		if (ch == '<')
		{
			flag = 1;
			if (fgetc(fp1) == 's')
				check = 1;
		}
		if ((flag == 0) && (check==0))
		{
			fputc(ch, fp2);
		}
		if (ch == '>')
		{
			flag = 0;
			if ((count == 0) && (check==1))
			{
				check = 1;
				count++;
			}
			else if ((count == 1) && (check==1))
			{
				check = 0;
				count = 0;
			}
			else
			{
				check = 0;
			}
		}
	}
	fclose(fp1);
	fclose(fp2);

}