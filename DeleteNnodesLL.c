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
void delete(struct node *head, int m, int n)
{
	int i;
	struct node *temp = NULL;
	i = m;
	if (head == NULL)
		return;
	while (head!=NULL)
	{
		for (i = 0; (i<m - 1) &&( head != NULL); i++)
			head = head->next;
		if (head!=NULL)
			temp = head;
		for (i = 0; (i <= n)&&(head != NULL); i++)
			head = head->next;
		if (head!=NULL)
			temp->next = head;
	}
}

void main()
{
	struct node *head;
	head = NULL;
	int i = 0, size, num, m, n;
	scanf("%d%d", &m, &n);
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
	delete(head, m, n);
	printf("\n");
	display(&head);
}