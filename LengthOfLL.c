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
void display(struct node *head)
{
	struct node *p;
	p = head;
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
void RemoveDuplicatesFromAnUnsortedList(struct node **head)
{
	struct node *Static, *Moving, *PreviousToMoving;
	Static = *head;
	PreviousToMoving = NULL;
	while (Static != NULL)
	{
		Moving = Static->next;
		PreviousToMoving = Static;
		while (Moving != NULL)
		{
			if (Moving->data == Static->data)
			{
				PreviousToMoving->next = Moving->next;
				Moving->next = NULL;
				free(Moving);
				Moving = PreviousToMoving;
			}
			PreviousToMoving = Moving;
			Moving = Moving->next;
		}
		Static = Static->next;
	}
}
int NthElementFromBehindRecursive(struct node *head, int N)
{
	struct node *p = head;
	if (p == NULL)
		return 0;
	int i = NthElementFromBehindRecursive(p->next, N) + 1;
	if (i == N)
	{
		printf("%d", p->data);
		exit(0);
	}
	return i;
}
int NthElementFromBehind(struct node *head,int N)
{
	if (N < 0)
	{
		printf("\nEnter a valid Number");
		return;
	}
	struct node *SlowPointer,*FastPointer;
	int TemporaryN = 0;
	TemporaryN = N;
	SlowPointer = head;
	FastPointer = head;
	while (TemporaryN > 0)
	{
		if (FastPointer == NULL)
		{
			printf("\nNot Enough Elements\n");
			return;
		}
		FastPointer = FastPointer->next;
		TemporaryN--;
	}
	while (FastPointer!= NULL)
	{
		FastPointer = FastPointer->next;
		SlowPointer = SlowPointer->next;
	}
	printf("\n%d", SlowPointer->data);
	return 0;
}
void main()
{
	struct node *head = NULL;
	create(&head, 1);
	create(&head, 2);
	create(&head, 3);
	create(&head, 1);
	create(&head, 2);
	create(&head, 2);
	create(&head, 4);
	create(&head, 4);
	create(&head, 5);
	create(&head, 1);
	create(&head, 6);
	display(head);
	printf("\n");
	//NthElementFromBehind(head, -6);
	NthElementFromBehindRecursive(head, 2);
	//RemoveDuplicatesFromAnUnsortedList(&head);
	//printf("\n");
	//display(head);
}