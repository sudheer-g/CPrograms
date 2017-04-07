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
	if (*head == NULL)
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
void shift(struct node **head)
{
	if (*head==NULL)
		return;
	struct node *p, *q;
	struct node *end,*end2;
	p = *head;
	end = *head;
	while (end->next != NULL)
	{
		end = end->next;
	}
	end2 = end;
	while ((p->data % 2 == 0) && (p != end))
	{
		end2->next = p;
		p = p->next;
		end2->next->next = NULL;
		end2 = end2->next;
	}
	if (p->data % 2)
	{
		*head = p;
		while (p != end)
		{
			if (p->data % 2)
			{
				q = p;
				p = p->next;
			}
			else
			{
				q->next = p->next;
				p->next = NULL;
				end2->next = p;
				end2 = p;
				p = q->next;
			}
		}
	}
	else
		q = p;
	if ((end2 != end) && ((end->data) % 2 == 0))
	{
		q->next = end->next;
		end->next = NULL;
		end2->next = end;
	}

}
void main()
{
	struct node *head = NULL;
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
	shift(&head);
	display(&head);
}