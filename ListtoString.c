#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
struct node *temp1;

struct node* create(struct node *head, int x)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		temp1 = head;
	}
	else
	{


		temp1->next = temp;
		temp1 = temp;
	}
	return(head);
}
int strlen(char *p)
{
	int len = 0;
	while (*(p + len))
		len++;
	return len;
}
void reverse(char *s)
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
void itoa(int a)
{
	int i = 0, sign = 0;
	int rem = 0;
	char p[30];
	sign = a;
	if (sign < 0)
	{
		a = -a;
	}
	int temp = a;
	while (temp != 0)
	{
		rem = temp % 10;
		p[i++] = rem + '0';
		temp = temp / 10;
	}
	if (sign < 0)
	{
		p[i++] = '-';

	}
	p[i] = '\0';
	reverse(p);
	printf("%s", p);
}
void insert(struct node **head, int x, int pos)
{
	int k = 0;
	struct node *temp, *p, *q;
	temp = (struct node *)malloc(sizeof(struct node));
	if (!temp)
	{
		printf("Memory Error");
		return;
	}
	temp->data = x;
	p = *head;
	if (pos == 1)
	{
		temp->next = p;
		*head = temp;
	}
	else
	{
		while ((p != NULL) && (k < pos))
		{
			k++;
			q = p;
			p = p->next;
		}
		q->next = temp;
		temp->next = p;
	}

}
void display(struct node **head)
{
	struct node *p;
	p = *head;
	while (p != NULL)
	{
		printf("->%d", p->data);
		p = p->next;
	}
}
void convert(struct node **head)
{
	char a[100];
	int i = 0, j = 0,x=0;
	struct node *p;
	while (p != NULL)
	{
		x = p->data;
		itoa(x);
		
	}
	a[j] = '\0';
	printf("%s", a);
}
void main()
{
	int a = 20;
	head = NULL;
	head = create(head, 11);
	create(head, 12);
	create(head, 13);
	create(head, 14);
	display(&head);
	
	itoa(a);

}