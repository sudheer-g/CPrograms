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
void swap(struct node **head,int k)
{
	struct node *p,*prev,*end,*prev2;
	prev2 = NULL;
	struct node *begin = NULL;
	end = *head;
	prev = NULL;
	p = *head;
	int count = 1;
	while ((p != NULL) && (count < k))
	{
		prev = p;
		p = p->next;
		count++;
	}
	begin = p;
	while (p->next!= NULL)
	{
		p = p->next;
		prev2 = end;
		end = end->next;
		count++;
	}
	if (prev != NULL)
		prev->next = end;
	if (prev2 != NULL)
		prev2->next = begin;

	struct node *temp = begin->next;
	begin->next = end->next;
	end->next = temp;

	if (k == 1)
		*head = end;

	if (k == count)
		*head = begin;

}
void main()
{
	struct node *head;
	head = NULL;
	int i = 0, size, num,k=0;
	scanf("%d", &k);
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
	swap(&head, k);
	printf("\n");
	display(&head);

}