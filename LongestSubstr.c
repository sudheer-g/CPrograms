#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct test_stubs
{
	char string1[20];
	int len1;
	char string2[20];
	int len2;
	char expected[20];
	int len3;
}testdb[3] = { { "ravi",4,"avi",3,"avi",3}, { "raviteja",8,"tejaa",5,"teja",4 }, { "sudheer",7, "abc",3, "",0 } };
/*int strcmp(char *s1, char *s2) {
	int ret = 0;
	while (!(ret = *s1 - *s2) && *s2)
		++s1, ++s2;

	if (ret < 0) {
		ret = -1;
	}
	else if (ret > 0) {
		ret = 1;
	}

	return ret;
}
int strlen(char *p)
{
	int len = 0;
	while (*(len + p))
		len++;
	return len;
}*/
void loncomsub(char *str1, char *str2, int *maxstart, int *maxend)
{

	int count, maxcount = 0, start = 0;
	int i = 0, j, k;
	if ((str1[i] == '\0') || (str2[i] == '\0'))
	{
		printf("Nothing in common");
	}
	while (str1[i])
	{
		count = 0;
		k = i; j = 0;
		while (str2[j])
		{
			if (str1[k] == str2[j])
			{
				if (count == 0)

				{
					start = k;
				}
				count++;
				k++;
				j++;
			}
			else
			{
				count = 0;
				j++;
			}

			if (count > maxcount)
			{
			maxcount = count;
			*maxstart = start;
			*maxend = k;
			}
		}
		i++;
	}
}
void malloc_manual(char *input1, char *input2,char *res,char *static_1, char *static_2,char *static_res,int len1,int len2,int len3)
{
	input1 = (char *)malloc((len1 + 1) * (sizeof(input1)));
	strcpy(input1, static_1);
	*input2 = (char *)malloc((len2 + 1) * (sizeof(input1)));
	strcpy(input2, static_2);
	*res = (char *)malloc((len3 + 1)*sizeof(res));
	strcpy(res, static_res);

}
int main()
{
	//char a[100], b[100];
	//gets(a);
	//gets(b);
	int i = 0, j = 0;
	int k = 0,x=0;
	char *expected;
	char res[20];
	char *input1, *input2;
	for (k = 0; k < 3; k++)
	{
		malloc_manual(&input1, &input2,&expected,testdb[k].string1, testdb[k].string2,testdb[k].expected,testdb[k].len1,testdb[k].len2,testdb[k].len3);
		//loncomsub(testdb[k].string1, testdb[k].string2, &i, &j);
		printf("%s", input1);
		loncomsub(input1,input2,&i,&j);
		for (; i < j; i++)
		{
			//res[x++] = testdb[k].string1[i];
			res[x++] = input1[i];
		}
		res[x] = '\0';
		if (strcmp(res,expected) == 0)
			printf("Teststub %d is true\n", k);
		else
			printf("Teststub %d is false\n", k);
		 x = 0, i = 0, j = 0;
		 free(input1);
		 free(input2);
		 free(expected);
	}
	return 0;
}