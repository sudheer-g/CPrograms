#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
//struct node *temp1;
void create(struct node **head,int x)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		temp->next = *head;
		*head = temp;
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
void main()
{
	int n,num=0,rem=0;
	printf("\nEnter the Number:");
	scanf("%d", &n);
	struct node *head;
	head = NULL;
	num = n;
/*	while (temp != 0)
	{
		rem = temp % 10;
		rev = rev * 10 + rem;
		temp = temp / 10;
	}*/
	while (num != 0)
	{
		
		rem = num % 10;
	    create(&head,rem);
		num = num / 10;
	}
	printf("After Conversion:\n");

	display(&head);
}