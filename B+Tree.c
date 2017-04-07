#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct meta
{
	int child[3];
	int value[2];
	char type[4];
};

struct data
{
	int value;
	char name[8];
	int type;
	int poff;
	int soff;
};
void create_meta(struct meta* mdata, int value1, int value2, char* type)
{
	mdata->value[0] = value1;
	mdata->value[1] = value2;
	mdata->type[0] = type[0];
	mdata->type[1] = type[1];
	mdata->type[2] = type[2];
	mdata->type[3] = type[3];
}

void create_data(struct data* ddata, int value, char* name, int type)
{
	ddata->value = value;
	strcpy(ddata->name, name);
	ddata->type = type;
}
int dynamic()
{

	FILE* fp = fopen("org.txt", "rb+");

	struct meta* mdata = (struct meta*)malloc(sizeof(struct meta));
	struct data* ddata = (struct data*)malloc(sizeof(struct data));

	char* type = (char*)malloc(4 * sizeof(char));

	int i, value, count = 0, value1, value2, total;

	for (i = 0; i<9; i++)
	{
		printf("enter data %d value ", i);
		scanf("%d", &value);
		create_data(ddata, value, "data", 0);

		ddata->poff = (i - 1) * 24;
		ddata->soff = (i + 1) * 24;

		if (i == 0)
			ddata->poff = -1;
		if (i == 8)
			ddata->soff = -1;

		fwrite(ddata, sizeof(struct data), 1, fp);
		count++;
	}

	i = 0;
	total = count;
	while (count != 1)
	{
		type[0] = '1';
		if (i >= 9)
		{
			fseek(fp, (i + 1) * 24, 0);
			fread(mdata, sizeof(struct meta), 1, fp);
			value1 = mdata->value[0];
			fread(mdata, sizeof(struct meta), 1, fp);
			value2 = mdata->value[0];
			type[0] = '1';
			type[1] = '1';
			type[2] = '1';
		}
		else
		{
			fseek(fp, (i + 1) * 24, 0);
			fread(ddata, sizeof(struct data), 1, fp);
			value1 = ddata->value;
			fread(ddata, sizeof(struct data), 1, fp);
			value2 = ddata->value;
			type[0] = '0';
			type[1] = '0';
			type[2] = '0';
		}

		create_meta(mdata, value1, value2, type);
		mdata->child[0] = (i++) * 24;
		mdata->child[1] = (i++) * 24;
		mdata->child[2] = (i++) * 24;
		fseek(fp, total * 24, 0);
		fwrite(mdata, total*sizeof(struct meta), 1, fp);
		count -= 2;
		total++;
	}
	fclose(fp);
	total = (total - 1) * 24;
	return total;
}

void search(int root, int x, int y)
{
	FILE* fp = fopen("org.txt", "rb+");
	int value, type = 1, offset, child = 0;
	struct meta* mdata = (struct meta*)malloc(sizeof(struct meta));
	struct data* ddata = (struct data*)malloc(sizeof(struct data));
	printf("%d\n", root);

	while (type == 1)
	{
		fseek(fp, root, 0);
		fread(mdata, sizeof(struct meta), 1, fp);

		if (mdata->value[1] <= x)
			child = 2;
		else if (mdata->value[0] <= x)
			child = 1;

		if (mdata->type[child] == '0')
		{
			type = 0;
			offset = mdata->child[child];
			fseek(fp, offset, 0);
			fread(ddata, sizeof(struct data), 1, fp);
			while (ddata->value >= x&&ddata->value <= y)
			{
				printf("%d ", ddata->value);
				fseek(fp, ddata->soff, 0);
				fread(ddata, sizeof(struct data), 1, fp);
			}
		}

		else
		{
			root = mdata->child[child];
			printf("%d\n", root);
		}
	}
	fclose(fp);
}
void main()
{
	FILE *fp = fopen("org.txt", "r");
	int root, x, y;
	if (fp == NULL)
	{
		fp = fopen("org.txt", "w");
		fseek(fp, 1024 * 1024, SEEK_SET);
		fputc('\n', fp);
		fclose(fp);
		root = dynamic();
	}
	//root=dynamic();
	printf("enter x and y values");
	scanf("%d%d", &x, &y);
	search(root, x, y);
}
/*#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct metapage
{
	int childType;
	int children[3];
	int value[2];
};
struct node
{
	char nonsense[12];
	int prev;
	int next;
	int value;
};
int root_off;
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
}
void display(int count)
{
	int i = 0;
	FILE *fp;
	fp = fopen("bplustree.bin", "rb");
	if (fp  == NULL)
	{
		printf("Cant open File\n");
		exit(1);
	}
	struct node *data;
	data = (struct node *)malloc(sizeof(struct node));
	rewind(fp);
	while (i < 2)
	{
		fseek(fp, count * 24, 0);
		fread(data, sizeof(struct node), 1, fp);
		printf("%d\n", data->value);
		i++;
	}
	fclose(fp);
}
/*void create_node(FILE *rp,int count,char *nonsense)
{
	FILE *fp;
	char root_offset[20];
	int root_off=0,i=0;
	if ((fp = fopen("bplustree.bin", "rb+")) == NULL)
	{
		fputs("Can't open file\n", stderr);
		exit(1);
	}
	struct node *data;
	data = (struct node *)malloc(sizeof(struct node));
	strcpy(data->nonsense, nonsense);
	data->prev = count;
	data->value = 50;
	rewind(fp);
	fseek(fp, root_off+1 * 24, 0);
	fwrite(data, count*sizeof(struct node), 1, fp);
	fflush(fp);
	fclose(fp);
	return;
}*/
/*void create_node(int count,char *nonsense)
{
	FILE *fp;
	//char root_offset[20];
	static int root_off = 0;
	static int meta_count = 0;
	static int i = 0;
	static int meta_node = 0;
	if ((fp = fopen("bplustree.bin", "rb+")) == NULL)
	{
		fputs("Can't open file\n", stderr);
		exit(1);
	}
	//if (fgetc(rp) == EOF)
		//fwrite("0", 1, 1, rp);
	struct node *data;
	data = (struct node *)malloc(sizeof(struct node));
	struct node *prev = (struct node *)malloc(sizeof(struct node));
	struct metapage *mdata1 = (struct metapage *)malloc(sizeof(struct metapage));
	strcpy(data->nonsense, nonsense);
	data->prev = count - 1;
	data->next = count + 1;
	data->value = ++i;
	fseek(fp, (count - 1) * 24, 0);
	fwrite(data, sizeof(struct node), 1, fp);
	if (count == 1)
		root_off = 1;
	if (count % 3 == 0)
	{
		fseek(fp, (data->prev-1) * 24, 0);
		fread(prev, sizeof(struct node), 1, fp);
		mdata1->children[0] = prev->prev;
		printf("%d\n", mdata1->children[0]);
		mdata1->children[1] = count-1;
		printf("%d\n", mdata1->children[1]);
		mdata1->children[2] = data->next-1;
		printf("%d\n", mdata1->children[2]);
		mdata1->value[0] = prev->value;
		mdata1->value[1] = data->value;
		mdata1->childType = 0;
		fseek(fp, meta_count *3* 24, 0);
		fwrite(mdata1, sizeof(struct metapage), 1, fp);
		meta_count ++;
	}
	if (meta_count==3)
	{
		struct metapage *mdata = (struct metapage *)malloc(sizeof(struct metapage));
		struct metapage *temp1 = (struct metapage *)malloc(sizeof(struct metapage));
		struct metapage *temp2 = (struct metapage *)malloc(sizeof(struct metapage));
		fseek(fp, 3 * 24, 0);
		fread(temp1, sizeof(struct metapage), 1, fp);
		fseek(fp, 9 * 24, 0);
		fread(temp2, sizeof(struct metapage), 1, fp);
		mdata->value[0] = temp1->value[1];
		mdata->value[1] = temp2->value[0];
		mdata->children[0] = 3;
		mdata->children[1] = 6;
		mdata->children[2] = 9;
		mdata->childType = 1;
		meta_count++;
		root_off = meta_count;
	}
	fflush(fp);
	fclose(fp);
}
void search(int num1,int num2)
{
	FILE *fp;
	struct metapage *meta = (struct metapage *)malloc(sizeof(struct metapage));
	struct node *data = (struct node *)malloc(sizeof(struct node));
	if ((fp = fopen("bplustree.bin", "rb")) == NULL)
	{
		fputs("Can't open file\n", stderr);
		exit(1);
	}
	fseek(fp, root_off * 24, 0);
	fread(meta, sizeof(struct metapage), 1, fp);
	if (num1 <= meta->value[0])
	{
		fseek(fp, meta->children[0] * 24, 0);
		fread(meta, sizeof(struct metapage), 1, fp);
	}
	else if ((num1 > meta->value[0]) && (num1 < meta->value[1]))
	{
		fseek(fp, meta->children[1] * 24, 0);
		fread(meta, sizeof(struct metapage), 1, fp);
	}
	else
	{
		fseek(fp, meta->children[2] * 24, 0);
		fread(meta, sizeof(struct metapage), 1, fp);
	}
	if (num1 < meta->value[0])
	{
		fseek(fp, meta->children[0] * 24, 0);
		fread(data, sizeof(struct node), 1, fp);
	}
	else if ((num1 > meta->value[0]) && (num1<meta->value[1]))
	{
		fseek(fp, meta->children[1] * 24, 0);
		fread(data, sizeof(struct node), 1, fp);
	}
	else
	{
		fseek(fp, meta->children[2] * 24, 0);
		fread(data, sizeof(struct node), 1, fp);
	}
	printf("%d", data->value);
}*/
/*void main()
{
	FILE  *fp,*rp;
	int i = 0;
	int count = 1;
	/*if ((rp = fopen("root.txt", "rb+")) == NULL)
	{
		fputs("Can't open file\n", stderr);
		exit(1);
	}
	if ((fp = fopen("bplustree.bin", "wb")) == NULL)
	{
		fputs("Can't open file\n", stderr);
		exit(1);
	}
	char nonsense[16];
	while (i < 9)
	{
		gets(nonsense);
		create_node(count, nonsense);
		count++;
		i++;
	}
	search(3,6);
	//display(count);
	fclose(fp);
}*/
