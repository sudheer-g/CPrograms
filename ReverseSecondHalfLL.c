#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
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
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;

	}
}
void reverse(struct node **head)
{
	struct node *p, *q;
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
void rev(struct node **head)
{
	struct node *p,*q,*prev;
	p = *head;
	q = *head;
	prev = NULL;
	while (q != NULL)
	{
		q = q->next->next;
		if ((q != NULL) && (q->next != NULL))
		{
			prev = p;
			p = p->next;
		}
		if (q == NULL || q->next == NULL)
			break;
	}
	reverse(&p->next);
	prev->next = p;
	
}
void main()
{
	struct node *head;
	head = NULL;
	create(&head, 1);
	create(&head, 2);
	create(&head, 3);
	create(&head, 4);
	create(&head, 5);
	create(&head, 6);
	display(&head);
	rev(&head);
	printf("\n");
	display(&head);
}