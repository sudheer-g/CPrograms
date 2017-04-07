#include<stdio.h>
void reverse(char *s)
{
	long int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
/*int atoi(char *p)
{
	int i, n, sign, j;
	for (i = 0; isspace(p[i]); i++)
		;

	sign = (p[i] == '-') ? -1 : 1;
	if (p[i] == '+' || p[i] == '-')
		i++;
	for (n = 0; isdigit(p[i]); i++)
		n = 10 * n + (p[i] - '0');

	j = sign * n;
	return j;

}*/
int strlen(char *p)
{
	long int len = 0;
	while (*(p + len))
		len++;
	return len;
}
void add(char *num1, char *num2)
{
	char sum[30];
	long long j = 0;
	long long i = 0;
	long long carry=0;
	long long temp = 0;
	long long a = 0, b = 0;
	a = strlen(num1);
	b = strlen(num2);
	a--;
	b--;
	while((a >= 0) && (b>=0))
	{
		temp = carry+num1[a] - '0' + num2[b] - '0';
		if (temp > 9)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		sum[i] = temp % 10 + '0';
		i++;
		a--;
		b--;
	}
	while (a >= 0)
	{
		temp = carry + (num1[a] - '0');
		if (temp > 9)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		sum[i++] = temp % 10 + '0';
		a--;
	}
	while (b >= 0)
	{
		temp = carry + (num2[b] - '0');
		if (temp > 9)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		sum[i++] = temp % 10 + '0';
		b--;
	}
	if (carry)
	{
		sum[i++] = carry + '0';
	}
	sum[i] = '\0';
	reverse(sum);
	printf("%s", sum);
	
}
void main()
{
	char num1[100], num2[30];
	gets(num1);
	gets(num2);
	add(num1, num2);

}