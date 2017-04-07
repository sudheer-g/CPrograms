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
		printf("Empty list");
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
}
void rem(struct node **head)
{
	struct node *p,*q;
	p = *head;
	while((p != NULL) && (p->next != NULL))
	{
		if (p->data < p->next->data)
		{
			p->data = p->next->data;
			q = p->next;
			p->next = q->next;
			free(q);

		}
		else
			p = p->next;
	}
}
void main()
{
	struct node *head;
	head = NULL;
	int i = 0, size, num;
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
	rem(&head);
	printf("\n");
	display(&head);
}
