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
int divisible(struct node **head)
{
	if (*head == NULL)
		return;
	int odd_sum = 0, even_sum = 0;
	int count = 0;
	struct node *p;
	p = *head;
	while (p != NULL)
	{
		if (count == 0)
		{
			odd_sum = odd_sum + p->data;
			count = 1;
		}
		else if (count == 1)
		{
			even_sum = even_sum + p->data;
			count = 0;
		}
		p = p->next;
	}
	return(even_sum - odd_sum);
}
int check(int result)
{
	int sum1=0, sum2=0, rem;
	if (result < 0)
	{
		result = -result;
	}
	if (result==0)
	{
		return 0;
	}
	if (result < 10)
	{
		return 1;
	}

	while (result > 0)
	{
		sum1 = sum1 + result % 10;
		result = result / 10;
		sum2 = sum2 + result % 10;
		result = result / 10;
	}
	if (sum1 > sum2)
	{
		rem = sum1 - sum2;
	}
	else
		rem = sum2 - sum1;
	check(rem);

}
void main()
{
	int result = 0,value=0;
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
	result = divisible(&head);
	value=check(result);
	if (value == 0)
		printf("Divisible");
	else
		printf("Not divisible");
}