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
		printf("Empty list");

	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
}
int length(struct node *head)
{
	int len=0;
	struct node *p;
	p = head;
	while (p != NULL)
	{ 
		len++;
		p = p->next;
	}
	return len;
}
void insert(struct node **head, int x, int pos)
{
	int k = 1;
	struct node *temp,*temp1,*temp2;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp1 = *head;
	if (!temp)
	{
		printf("Memory Error");
		return;
	}

	if (pos == 1){
		temp->next = temp1;
		*head = temp;
	}
	else
	{
		while ((temp1 != NULL) && (k < pos)){
			k++;
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = temp;
		temp->next = temp1;
	}
}
struct node *ins(struct node *head, int k,int len)
{
	int n = k;
	struct node *p;
	p = head;
	while (p!=NULL)
	{
		if (n<=0)
		{
			break;
		}
		if (n <= len)
		{
			insert(&head, k, n+1);
			n = n+k+1;
			len++;
		}
		else
			break;
		p = p->next;

	}
	return head;
}
void main()
{
	int k,n=0,size,i=0,num;
	printf("Enter the number of nodes:");
	scanf("%d", &size);
	printf("\nEnter K:");
	scanf("%d", &k);
	struct node *head;
	head = NULL;
	while (i < size)
	{
		printf("\nEnter the node:");
		scanf("%d", &num);
		create(&head, num);
		i++;
	}
	printf("\nBefore Insertion\n");
	display(&head);
	n = length(head);
	head=ins(head, k,n);
	printf("\nAfter Insertion:\n");
	display(&head);
}