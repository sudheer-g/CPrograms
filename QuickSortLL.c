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
void sort(struct node **start, struct node *end)
{
	if (*start == end)
		return;
	struct node *pivot = *start;
	struct node *temp = *start;
	struct node *temp1;
	while (temp->next != end)
	{
		if (temp->next->data < pivot->data)
		{
			temp1 = (*start);
			*start = temp->next;
			temp->next = temp->next->next;
			(*start)->next = temp1;
		}
		else
			temp = temp->next;
	}
	sort(start, pivot);
	sort(&(pivot->next), end);
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
	sort(&head,NULL);
	display(&head);
}