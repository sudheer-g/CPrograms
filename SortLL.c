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
void sort(struct node *head)
{
	struct node *current;
	int temp = 0,swapped=1;
	current = head;
	if (current == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		current = head;
		while (current->next != NULL)
		{
			if ((current->data) > (current->next->data))
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}

}

void main()
{
	int i = 0, size, num;
	printf("Enter the number of nodes:");
	scanf("%d", &size);
	struct node *head;
	head = NULL;
	while (i < size)
	{
		printf("\nEnter the node:");
		scanf("%d", &num);
		create(&head, num);
		i++;
	}
	printf("\nList Before Sorting:\n");
	display(&head);
	printf("\nList after Sorting:\n");
	sort(head);
	printf("\n");
	display(&head);
}