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
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;

	}
}
struct node *sorted(struct node *a, struct node *b)
{
	struct node *x = NULL;
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	if (a->data <= b->data)
	{
		x = a;
		x->next = sorted(a->next, b);
	}
	else
	{
		x = b;
		x->next = sorted(a, b->next);
	}
	return x;
}
void split(struct node *source, struct node **front, struct node **rear)
{
	struct node *fp, *sp;
	if (source == NULL || source->next == NULL)
	{
		*front = source;
		*rear = NULL;
	}
	else
	{
		sp = source;
		fp = source->next;
		while (fp != NULL)
		{
			fp = fp->next;
			if (fp != NULL)
			{
				sp = sp->next;
				fp = fp->next;
			}
		}
		*front = source;
		*rear = sp->next;
		sp->next = NULL;

	}


}
void merge(struct node **head)
{
	struct node *p = *head;
	struct node *a, *b;
	if (p == NULL || p->next == NULL)
		return;
	split(p, &a, &b);
	merge(&a);
	merge(&b);
	*head = sorted(a, b);
}
void combine(struct node **head1, struct node **head2)
{
	struct node *p = *head1;
	struct node *q = *head2;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
}
void main()
{
	int i = 0, size1,size2,num;
	printf("Enter the number of nodes for the first LL:");
	scanf("%d", &size1);
	printf("Enter the number of nodes for the second LL:");
	scanf("%d", &size2);
	struct node *head1;
	struct node *head2;
	struct node *head3 = NULL;
	head1 = NULL;
	head2 = NULL;
	while (i < size1)
	{
		printf("\nEnter the node:");
		scanf("%d", &num);
		create(&head1, num);
		i++;
	}
	i = 0;
	while (i < size2)
	{
		printf("\nEnter the node:");
		scanf("%d", &num);
		create(&head2, num);
		i++;

	}
	combine(&head1, &head2);
	merge(&head1);
	display(&head1);
	
}