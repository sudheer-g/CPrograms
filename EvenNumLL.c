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
		printf("Empty List");
		return;
	}
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}

}
void even(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *p;
	p = *head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	if ((p->data) % 2 == 0)
	{
		printf("\nThe number is even");
	}
	else
		printf("\nThe number is odd");

}
void main()
{
	struct node *head;
	head = NULL;
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
	even(&head);
}