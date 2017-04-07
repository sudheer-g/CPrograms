#include<stdio.h>
void put_tabs(FILE *wp,int left_brace_count)
{
	int temp = 0;
	temp = left_brace_count;
	while (temp != 0)
	{
		fputc('\t', wp);
		printf("\t");
		temp--;
	}
	return;
}
void main()
{
	FILE *fp,*wp;
	fp = fopen("C:\\Users\\Sudheer\\Downloads\\grades.json", "r");
	wp = fopen("output.txt", "w");
	char ch;
	int left_brace_count = 0;
	//int temp = 0;
	while ((ch=fgetc(fp)) != EOF)
	{
		//printf("%c", ch);
		if (ch == '{')
		{
			left_brace_count++;
			fputs("{\n", wp);
			printf("{\n");
			put_tabs(wp,left_brace_count);
		}
		else if (ch == ',')
		{
			fputs(",\n",wp);
			printf(",\n"); 
			put_tabs(wp,left_brace_count);
			printf("\t");
			fputc('\t', wp);

		}
		else if (ch == '}')
		{
			if (left_brace_count == 1)
			{
				fputs("\n}", wp);
				printf("\n}");
			}
			else
			{
				printf("\n\t\t }");
				fputs("\n\t\t }",wp);
			}
			left_brace_count--;
		}
		else
		{
			fputc(ch, wp);
			printf("%c", ch);
		}
	}
	fclose(fp);
	fclose(wp);
}