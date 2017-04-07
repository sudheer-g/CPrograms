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
struct node *reverse(struct node *head, int k)
{
	if ((head == NULL) || (k < 0))
		return NULL;
	int len = 0;
	struct node *p;
	p = head;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	if (len < k)
		return head;
	struct node* current = head;
	struct node* next = NULL;
	struct node* prev = NULL;
	int count = 0;
	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
		len--;
	}
	if (next != NULL)
	{
		head->next = reverse(next, k);
	}
	return prev;
}

void main()
{
	struct node *head;
	head = NULL;
    int i = 0, size, num, k, n = 0;
	printf("Enter the number of nodes:");
	scanf("%d", &size);
	printf("\nEnter K:\n");
	scanf("%d", &k);
	while (i < size)
	{
		printf("\nEnter the node:");
		scanf("%d", &num);
		create(&head, num);
		i++;
	}
	display(&head);
	head=reverse(head,k);
	printf("\n");
	display(&head);
}