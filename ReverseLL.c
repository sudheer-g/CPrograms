#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void create(struct node **head, int x)
{
	struct node *temp,*temp1;
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
		while (temp1->next!=NULL)
		    temp1= temp1->next;
		temp1->next=temp;
	}
}
void display(struct node **head)
{
	struct node *p;
	p = *head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
}
void reverse(struct node **head)
{
	struct node *p,*q;
	if (*head == NULL)
		return;
	p = *head;
	q = p->next;
	if (q == NULL)
		return;
	reverse(&q);
	p->next->next = p;
	p->next = NULL;
	*head = q;
}
void main()
{
	int size, i = 0, num;
	printf("Enter the number of nodes:");
	scanf("%d", &size);
	struct node *head;
	head = NULL;
	while (i < size)
	{
		printf("\nEnter the node:");
		scanf("%d", &num);
		create(&head, num);
		i++;
	}
	display(&head);
	reverse(&head);
	printf("\nThe Reversed Linked List is:\n");
	display(&head);
}