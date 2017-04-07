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
	while (p)
	{
		printf("%d->", p->data);
		p = p->next;

	}
}
struct node *addlists(struct node *head1, struct node *head2, int carry)
{
	if (head1==NULL && head2==NULL && carry==NULL)
		return NULL;

	struct node *temp = (struct node *)malloc(sizeof(struct node));

	if (head1==NULL && head2==NULL && carry)
	{
		temp->data = carry;
		temp->next = NULL;
		return temp;
	}

	int sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
	carry = (sum >= 10) ? sum / 10 : 0;
	sum %= 10;

	temp->data = sum;
	temp->next = addlists((head1 ? head1->next : NULL), (head2 ? head2->next : NULL), carry);

	return temp;
}
struct node *create_num()
{
	int n, num = 0, rem = 0;
	printf("\nEnter the Number:");
	scanf("%d", &n);
	struct node *head;
	head = NULL;
	num = n;
	while (num != 0)
	{

		rem = num % 10;
		create(&head, rem);
		num = num / 10;
	}
	return head;
}
int ll_to_num(struct node *head)
{
	int result = 0;
	struct node *p;
	p = head;
	while (p != NULL)
	{
		result = result + p->data;
		if (p->next != NULL)
		{
			result = result * 10;
		}
		p = p->next;
	}
	return result;
}
void reverse(struct node **head)
{
	struct node *p, *q;
	if (*head == NULL)
		return;
	p = *head;
	q = p->next;
	if (q == NULL)
		return;
	reverse(&q);
	p->next->next = p;
	p->next = NULL;
	*head = q;
}
void main()
{

	struct node *num1, *num2,*num3;
	int result = 0;
	num1 = NULL;
	num2 = NULL;
	num3 = NULL;
	num1 = create_num();
	num2 = create_num();
	display(&num1);
	printf("\n");
	display(&num2);
	printf("\nSum:\n");
	num3=addlists(num1, num2,0);
	reverse(&num3);
	result = ll_to_num(num3);
	printf("%d", result);
}