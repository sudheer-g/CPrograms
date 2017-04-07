#include<stdio.h>
#include<stdlib.h>
struct meta
{
	char value[8];
	char value[8];
	char type[4];
	int child[3];
};
struct data
{
	char string_d[8];
	char name[8];
	int value;
	int type;
	int poff;
	int soff;
};