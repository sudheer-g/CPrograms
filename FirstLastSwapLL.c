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
void display(struct node *head)
{
	struct node *p;
	p = head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;

	}
}
void swap_first_and_last_nodes(struct node **head)
{
	struct node *first, *last,*prev_end,*temp;
	first= *head;
	last = *head;
	prev_end = NULL;
	while (last->next != NULL)
	{
		prev_end = last;
		last = last->next;
	}
	while (first != NULL)
	{
		temp = last;
		last->next = first->next;
		first->next = last;
		prev_end->next = NULL;
		last = prev_end;
		first = first->next->next;
	}

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
	swap_first_and_last_nodes(&head);
	display(head);
}