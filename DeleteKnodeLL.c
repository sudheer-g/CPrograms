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
void delete(struct node **head, int pos){
	int k = 1;
	struct node *p, *q;
	if (*head == NULL)
	{
		printf("List Empty");
		return;
	}
	p = *head;
	if (pos == 1)
	{
		*head = (*head)->next;
		free(p);
		return;
	}
	else{
		while ((p != NULL) && (k < pos))
		{
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			//printf("Position does not exist");
		}
		else{
			q->next = p->next;
			free(p);
		}
	}
}
void del(struct node **head,int k)
{
	int n = k;
	struct node *p,*q,*i;
	p = *head;
	q = *head;
	if (k > 1)
	{
		if (p == NULL)
			return;
		while (p != NULL)
		{
			delete(&q, n);
			n = n + k - 1;
			p = p->next;
		}
	}
	else if (k==1)
	{
		while (p)
		{
			i = p->next;
			free(p);
			p = i;
		}
		*head = NULL;

	}
}
void main()
{
	
	int i = 0, size, num,k,n=0;
	printf("Enter the number of nodes:");
	scanf("%d", &size);
	printf("Enter K:");
	scanf("%d", &k);
	struct node *head;
	head = NULL;
	while (i < size)
	{
		printf("\nEnter the node:");
		scanf("%d", &num);
		create(&head, num);
		i++;
	}
	printf("Before Deletion:\n");
	display(&head);
	printf("\nAfter Deletion:\n");
	del(&head, k);
	display(&head);
	
}