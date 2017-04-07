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
struct node *pos(struct node *head, int k)
{
	int count = 1;
	struct node *p, *end;
	struct node *prev;
	p = head;
	end = head;
	while ((p != NULL) && (count < k))
	{
		p = p->next;
		count++;
		if ((p->next == NULL) && (count < k))
			return head;
	}
	prev = NULL;
	while (p->next != NULL)
	{
		p = p->next;
		prev = end;
		end = end->next;
		count++;
	}
	if ((k <= 0) || (k > count))
		return head;

	if (end == head)
	{
		struct node *t = head;
		head = head->next;
		free(t);
		return head;

	}
	else if (end->next == NULL)
	{
		prev->next = NULL;
		return head;
	}
	else
	{
		prev->next = end->next;
		end->next = NULL;
		free(end);
		return head;
	}
}
void main()
{
	struct node *head;
	head = NULL;
	create(&head, 1);
	create(&head, 2);
	create(&head, 3);
	create(&head, 4);
	create(&head, 5);
	create(&head, 6);
	head=pos(head, 1);
	display(&head);
}