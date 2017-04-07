#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
void create(struct node **head, int data)
{
	struct node *q, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if (!(temp))
		return;
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		q = *head;
		while (q->next != NULL)
			q = q->next;
		q->next = temp;
		temp->prev = q;
	}
}
void find(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *p;
	p = *head;
	struct node *first, *second;
	first = NULL;
	second = NULL;
	int count = 0;
	while (p->next != NULL)
	{ 
		if (p->data < p->next->data)
			p = p->next;
		else
		{
			if (count == 0)
			{
				first = p;
				count = 1;
				p = p->next;
			}
			else
			{
				second = p->next;
				p = p->next;
			}
		}
	}
	if (first->prev != NULL)
		first->prev->next = second;
	if (second->prev != NULL)
		second->prev->next = first;
	struct node *temp;
	temp = first->next;
	first->next = second->next;
	second->next = temp;
	if (first == *head)
		*head = second;

	if (second == p)
		p = first;
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
void main()
{
	struct node *head;
	head = NULL;
	create(&head, 5);
	create(&head, 2);
	create(&head, 3);
	create(&head, 1);
	create(&head, 6);
	display(&head);
	find(&head);
	printf("\n");
	display(&head);
}