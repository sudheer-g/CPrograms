#include<stdio.h>
struct test
{
	int num1;
	int num2;
	int expected;
}testDB[] = { { 1, 5, 120 }, { 1, 6, 720 }, { 1, 3, 4 } };
int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n*factorial(n - 1);
}
int fact2(int num1, int num2)
{
	if (num1 == num2)
		return num1;
	return fact2(num1, (num1 + num2) / 2)*fact2(((num1 + num2) / 2) + 1, num2);
}
void test_cases()
{
	int i = 0;
	while (i < 3)
	{
		if (fact2(testDB[i].num1, testDB[i].num2) == testDB[i].expected)
			printf("Test %d Passed!\n",i+1);
		else
			printf("Test %d Failed\n",i+1);
		i++;
	}
}
void main()
{
	//printf("%d", factorial(5)); 
	//printf("%d", fact2(1,6));
	test_cases();
}