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
void delete(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *p, *q;
	p = *head;
	q = p;
	while (q!=NULL)
	{
		q = q->next->next;
		if ((q != NULL) && (q->next != NULL))
			p = p->next;
		if (q == NULL || q->next == NULL)
			break;
	}
	p->next = NULL;
	while ((q != NULL) && (q->next!=NULL))
	{
		q = p->next;
		free(p);
	}
	

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
	delete(&head);
	display(&head);
}