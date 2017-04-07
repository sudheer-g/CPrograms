#include<stdio.h>
void convert_to_binary(float num,int limit)
{
	int i = 0,temp_num=0;
	for (i = 0; i < limit; i++)
	{
		temp_num = num;
		num = num - temp_num;
	}
}
void main()
{
	float num = 0.625;
	int limit=10;
	convert_to_binary(num,limit);
}