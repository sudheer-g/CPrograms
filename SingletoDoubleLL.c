#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct DoubleNode{
	int data;
	struct DoubleNode *next;
	struct DoubleNode *prev;
};
void create(struct node **head, int x)
{
	struct node *temp, *temp1;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
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
		printf("Empty List");
		return;
	}
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
}

struct DoubleNode *convert(struct node **head)
{
	struct DoubleNode *DLL;
	DLL = NULL;
	struct node *p;
	struct DoubleNode *q, *temp;
	p = *head;
	while (p != NULL)
	{
		temp = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
		temp->data = p->data;
		temp->next = NULL;
		if (DLL == NULL)
		{
			temp->prev = NULL;
			DLL = temp;
		}
		else
		{
			q = DLL;
			while (q->next != NULL)
			   q = q->next;
			q->next = temp;
			temp->prev = q;
		}
		p = p->next;
	}
	return(DLL);
}
void main()
{
	struct node *head;
	head = NULL;
	struct DoubleNode *DLL;
	DLL = NULL;
	int i = 0, size, num, k, n = 0;
	printf("Enter the number of nodes:");
	scanf("%d", &size);
	while (i < size)
	{
		printf("\nEnter the node:");
		scanf("%d", &num);
		create(&head, num);
		i++;
	}
	display(&head);
	DLL=convert(&head);
	printf("\nThe Double Linked List is:\n");
	display(&DLL);
}