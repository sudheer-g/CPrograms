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
void sort(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *curr = *head;
	int c = 1;
	struct node *prev = NULL, *tail, *temp;
	tail = *head;
	while (tail->next)
	{
		tail = tail->next;
		c++;
	}
	prev = curr;
	while ((curr) && (c>1))
	{
		if (curr->data == 0)
		{
			if (prev == curr)
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
				temp = curr->next;
				prev->next = curr->next;
				curr->next = *head;
				*head = curr;
				curr = temp;
			}
		}
		else if (curr->data == 2)
		{
			if (prev == curr)
			{
				temp = curr->next;
				curr->next = NULL;
				tail->next = curr;
				*head = temp;
				curr = temp;
				prev = curr;
				tail = tail->next;
			}
			else
			{
				temp = curr->next;
				prev->next = curr->next;
				curr->next = NULL;
				tail->next = curr;
				curr = temp;
				tail = tail->next;
			}
		}
		else if (curr->data == 1)
		{
			prev = curr;
			curr = curr->next;

		}
		c--;
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
	display(&head);
	printf("\n");
	sort(&head);
	display(&head);
}