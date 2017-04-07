#include<stdio.h>
#include<stdlib.h>
struct node{
	char *name;
	int marks;
	struct node *next;
};
int strcmp(char *string1, char *string2)
{
	int i = 0;
	int value = 2; 
	while (value == 2)
	{
		if (string1[i]>string2[i])
		{
			value = 1;
		}
		else if (string1[i]<string2[i])
		{
			value = -1;
		}
		else
		{
			i++;
		}
	}
	return(value);
}
int strlen(char *p)
{
	int len = 0;
	while (*(p + len))
		len++;
	return len;
}
void strcpy(char *a, char *b)
{
	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';
}
void create(struct node **head, int marks,char *name)
{
	struct node *temp, *temp1;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->name = malloc(strlen(name) + 1);
	temp->marks = marks;
	strcpy(temp->name, name);
	temp->next = NULL;
	flushall();
	if (*head == NULL)
	{
		*head = (struct node *)malloc(sizeof(struct node));
		*head = temp;
	}
	else
	{
		temp1 = *head;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
}
void display(struct node **head)
{
	struct node *p;
	p = *head;
	if (p == NULL)
	{
		printf("Empty List\n");
		return;
	}
	while (p != NULL)
	{
		printf("%s,%d->", p->name,p->marks);
		p = p->next;
	}
}
struct node *sorted(struct node *a, struct node *b,int flag)
{
	struct node *x = NULL;
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	if (flag == 1)
	{
		if (a->marks <= b->marks)
		{
			x = a;
			x->next = sorted(a->next, b,flag);
		}
		else
		{
			x = b;
			x->next = sorted(a, b->next,flag);
		}
		return x;
	}
	else
	{
		if (strcmp(a->name,b->name)<=0)
		{
			x = a;
			x->next = sorted(a->next, b,flag);
		}
		else
		{
			x = b;
			x->next = sorted(a, b->next,flag);
		}
		return x;
	}
}
void split(struct node *source, struct node **front, struct node **rear)
{
	struct node *fp, *sp;
	if (source == NULL || source->next == NULL)
	{
		*front = source;
		*rear = NULL;
	}
	else
	{
		sp = source;
		fp = source->next;
		while (fp != NULL)
		{
			fp = fp->next;
			if (fp != NULL)
			{
				sp = sp->next;
				fp = fp->next;
			}
		}
		*front = source;
		*rear = sp->next;
		sp->next = NULL;

	}


}
void merge(struct node **head,int flag)
{
	struct node *p = *head;
	struct node *a, *b;
	if (p == NULL || p->next == NULL)
		return;
	split(p, &a, &b);
	merge(&a,flag);
	merge(&b,flag);

	*head = sorted(a, b,flag);
}
void main()
{
	struct node *head;
	head = NULL;
	int size;
	printf("Enter the number of nodes:");
	scanf("%d", &size);
	int i = 0,num;
	char s[100];
	while (i < size)
	{
		printf("Enter the name of the student:\n");
		scanf("%s", &s);
		printf("Enter the Marks for the student:");
		scanf("%d", &num);
		create(&head, num, s);
		i++;
	}
	printf("Before Sorting:\n");
	display(&head);
	printf("\n\nSorting According to marks:\n\n");
	merge(&head,1);
	display(&head);
	printf("\n\nSorting According to names:\n\n");
	merge(&head, 0);
	display(&head);
}