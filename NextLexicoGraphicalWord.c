#include<stdio.h>
#include<stdlib.h>
int strlen(char *p)
{
	int len = 0;
	while (*(p + len))
		len++;
	return len;
}
struct test
{
	char input_string[30];
	char expected_output[30];
	char sorted[30];
	int len;
}testDB[] = { { "apple", "ealpp", "aelpp", 5 }, { "acb", "bac", "abc", 3 }, { "abc", "acb", "abc", 3 }, { "table", "taebl", "abelt", 5 }, { "mobile", "moblei", "beilmo", 6 } };
/*int binarysearch(char a[], char num, int x)
{
	int low, high, mid;
	low = 0;
	high = x - 1;                         //Giving Undesired behaviour.
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num < a[mid])
			high = mid - 1;
		else if (num>a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}*/
int linearsearch(char a[], char val, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (val == a[i])
			return i;
	}
	return -1;
}
void testcases()
{
	int i = 0,j=0,len=0,index=0,x=0,counts[30];
	char str[30],sorted_str[30];
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 30; j++)
			counts[j] = 0;
		char *str = (char *)malloc((testDB[i].len + 1)*sizeof(str));
		strcpy(str, testDB[i].input_string);
		strcpy(sorted_str, testDB[i].sorted);
		len = testDB[i].len;
		for (j = 0; j<len;j++)
		{
			if (sorted_str[j] == sorted_str[j + 1])
			{
				counts[j]++;
			}
		}
		for (j =len-1; j>=0; j--)
		{
			if (str[j] > str[j - 1])
			{
				index = j - 1;
				break;
			}
		}
		j = 0;
		//printf("%d\n", index);
		str[index++] = sorted_str[linearsearch(sorted_str,str[index],len) + 1];
		str[index] = '\0';
		for (x = 0; sorted_str[x] != '\0'; x++)
		{
			if (index == len)
				break;
			if (linearsearch(str, sorted_str[x], strlen(str)) == -1)
			{
				if (counts[x] >=1)
				{
					for (j = -1; j < counts[x]; j++)
						str[index++] = sorted_str[x];
				}
				else
				{
					str[index++] = sorted_str[x];
				}
				str[index] = '\0';
			}
		}
		//str[index] = '\0';
		printf("%s\n", str);
		if (strcmp(str, testDB[i].expected_output) == 0)
			printf("Test %d passed\n", i + 1);
		index = 0;
		j = 0;
	}
}
void main()
{
	testcases();
}