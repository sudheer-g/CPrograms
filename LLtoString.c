#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void reverse(char *s)
{
	int i, j;
	char c;
	for (i = 0, j = strlen(s) - 1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
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
void convert(struct node **head)
{
	int num=0, rem=0, rev=0,j=0,k=0,i=0;
	struct node *p;
	p = *head;
	char a[100], b[100];
	if (p == NULL)
	{
		printf("Empty String\n");
		return;
	}
	while (p != NULL)
	{
		num = p->data;
		while (num != 0)
		{
			rem = num % 10;
			a[j++] = rem + '0';
			num = num / 10;

		}
		a[j] = '\0';
		reverse(a);
		while (a[i] != '\0')
		{
			b[k++] = a[i];
			i++;
		}
		b[k] = '\0';
		j = 0;
		i = 0;
		p = p->next;

	}
	printf("\n%s", b);

}
void main()
{
	int i = 0, size,num;
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
	display(&head);
	printf("\nThe List is in string format:\n");
	convert(&head);
}