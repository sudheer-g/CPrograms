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
void duplicate(struct node* head){
	if (head == NULL)
		return;

	int a[1000] = { 0 };

	struct node* temp = head;

	struct node* prev = NULL;

	while (temp != NULL){

		a[temp->data]++;

		if (a[temp->data]>1){

			prev->next = temp->next;

			temp = temp->next;

		}

		else{

			prev = temp;

			temp = temp->next;

		}

	}

}
void main()
{
	struct node *head;
	head = NULL;
	create(&head, 1);
	create(&head, 2);
	create(&head, 3);
	create(&head, 3);
	create(&head, 2);
	create(&head, 1);
	display(&head);
	duplicate(head);
	printf("\n");
	display(&head);
}