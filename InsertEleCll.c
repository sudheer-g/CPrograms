#include<stdio.h>
#include<stdlib.h>
struct cll{
	int data;
	struct cll *next;
};
void create(struct cll **head, int data)
{
	struct cll *current = *head;
	struct cll *temp = (struct cll *)malloc(sizeof(struct cll));
	if (!temp)
		return;
	temp->data = data; 
	temp->next = *head;
	if (*head == NULL)
		*head = temp;
	else
	{
		while (current->next != *head){
			if (current->next == NULL)
				break;
			current = current->next;
		}
		temp->next = *head;
		current->next = temp;
	}

}
void insert(struct cll **head,int data)
{
	struct cll *current = *head;
	struct cll *temp;
	struct cll *prev;
	int flag = 0;
	prev = NULL;
	temp = (struct cll *)malloc(sizeof(struct cll));
	temp->data = data;
	if (current == NULL)
	{
		temp->next = temp;
		*head = temp;
		return;
	}
	do{
		if (current->data <= temp->data)
		{
			prev = current;
			current = current->next;
		}
		else
		{
			prev->next = temp;
			temp->next = current;
			flag = 1;
			break;
		}

	} while (current->next != *head);
	if (flag == 0)
	{
		current->next = temp;
		temp->next = *head;
	}

}
void display(struct cll *head)
{
	struct cll *p;
	p = head;
	if (head == NULL)
		return;
	do
	{
		printf("%d->", p->data);
		p = p->next;
	} while (p != head);
}
void main()
{
	struct cll *head;
	head = NULL;
	create(&head, 1);
	create(&head, 2);
	create(&head, 3);
	create(&head, 5);
	create(&head, 6);
	create(&head, 7);
	insert(&head, 4);
	display(head);
}