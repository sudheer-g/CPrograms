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
void swap(struct node **head)
{
	struct node *current, *n=NULL;
	current = *head;
	if (current == NULL || current->next == NULL)
		return;
	*head = current->next;
	while (current != NULL)
	{
		n = current->next->next;
		current->next->next = current;
		if (n == NULL || n->next == NULL)
		{
			current->next = n;
			return;
		}
		current->next = n->next;
		current = n;

	}

}
void main()
{
	int i = 0, size, num;
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
	printf("List before swapping:\n");
	display(&head);
	printf("\nAfter swapping:\n");
	swap(&head);
	display(&head);
}

