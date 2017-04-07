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
	if (p == NULL)
	{
		printf("Empty List\n");
		return;
	}
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}

}
void check(struct node **head)
{
	struct node *p, *begin, *end;
	struct node *prev;
	p = *head;
	prev = NULL;
	if (head == NULL || p->next == NULL)
		return;
	while (p != NULL)
	{
		if (p->data <= p->next->data)
		{
			prev = p;
			p = p->next;
		}
		else
		{
			begin = p;
			end = p->next;
			break;
		}
	}
	if (begin != NULL&&end != NULL)
	{

		if (prev != NULL)
			prev->next = end;

		begin->next = end->next;
		end->next = begin;

		if (begin == *head)
			*head = end;
	}
	
}
void main()
{
	struct node *head;
	head = NULL;
	create(&head, 1);
	create(&head, 2);
	create(&head, 3);
	create(&head, 5);
	create(&head, 4);
	display(&head);
	check(&head);
	printf("\n");
	display(&head);
}