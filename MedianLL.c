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
	while (p!=NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	
	}
}
void median(struct node *head)
{
	struct node *p, *q;
	p = head;
	q = head;
	if (p == NULL)
	{
		printf("Empty List");
		return;
	}
	while (q != NULL)
	{
		q = q->next->next;
		if ((q != NULL) && (q->next != NULL))
		    p = p->next;
		if (q==NULL||q->next == NULL)
			break;
	}
	printf("\nThe Median of the Linked List is:->%d",p->data);
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
	
	display(head);
	median(head);
	
}
