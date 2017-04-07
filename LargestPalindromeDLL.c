#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node *next;
	struct node *prev;
};
void create(struct node **head, int data)
{
	struct node *q, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if (!(temp))
		return;
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		q = *head;
		while (q->next != NULL)
			q = q->next;
		q->next = temp;
		temp->prev = q;
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
		printf("%c->", p->data);
		p = p->next;
	}
}
int is_pal(struct node *a, struct node *b)
{
	struct node *p, *q;
	p = a;
	q = b;
	while ((p != q) && (p->prev!=q))
	{
		if (p->data == q->data)
		{
			p = p->next;
			q = q->prev;
		}
		else
			break;
	}
	if ((p == q) || (p->prev==q))
		return 1;

	else
		return 0;
}
void display_pal(struct node *a, struct node *b)
{
	struct node *p;
	p = a;
	struct node *q;
	q = b;
	printf("The largest Palindrome is:");
	while (p != b->next)
	{
		printf("%c", p->data);
		p = p->next;
	}
}
void palindrome_finder(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *p,*q;
	p = *head;
	q = NULL;
	int max_count = 2, count = 2;
	struct node *begin = NULL, *end = NULL;
	while (p != NULL)
	{
		q = p->next;
		count = 2;
		while (q != NULL)
		{
			if ((p->data) == (q->data))
			{
				if (count >= max_count)
				{
					max_count = count;
					if (is_pal(p, q) == 1)
					{
						begin = p;
						end = q;
					}
				}
				count++;
				q = q->next;
			}
			else
			{
				q = q->next;
				count++;
			}
		}
		p = p->next;
	}
	if ((begin != NULL) && (end != NULL))
		display_pal(begin, end);
	else
		printf("No palindrome in the list");
}
void main()
{
	struct node *head;
	head = NULL;
	create(&head, 'd');
	create(&head, 'e');
	create(&head, 'p');
	create(&head, 'o');
	create(&head, 'p');
	create(&head, 'e');
	create(&head, 'd');
	display(&head);
	printf("\n");
	palindrome_finder(&head);
}