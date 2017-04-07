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
struct node * del_odd(struct node *head)
{
	if (head == NULL)
		return NULL;
	else
	{
		if (head->data % 2)
		{
			head = del_odd(head->next);
		}
		else
		{
			head->next = del_odd(head->next);
			return head;
		}
		return head;
	}

}
struct node * del_even(struct node *head)
{
	if (head == NULL)
		return NULL;
	else
	{
		if ((head->data % 2)==0)
		{
			head = del_even(head->next);
		}
		else
		{
			head->next = del_even(head->next);
			return head;
		}
		return head;
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

void mer(struct node **head)
{
	struct node *p = *head;
	struct node *a, *b,*temp;
	if (p == NULL || p->next == NULL)
		return;
	split(p, &a, &b);
	printf("\n");
	a=del_odd(a);
	b = del_even(b);
	temp = a;
	while (temp != NULL)
	{
		if (temp->next == NULL)
		{
			temp->next = b;
			break;
		}
		else
		{
			temp = temp->next;
		}

	}
	*head = a;
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
	display(&head);
	mer(&head);
	printf("\n");
	display(&head);
}