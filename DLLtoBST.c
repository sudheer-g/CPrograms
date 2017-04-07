#include<stdio.h>
#include<stdlib.h>
struct DoubleNode{
	int data;
	struct DoubleNode *next;
	struct DoubleNode *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;
void inorder(struct node *tree){
	if (tree!=NULL)
	{
		inorder(tree->left);
		printf("%d\n", tree->data);
		inorder(tree->right);
	}
}
void create_tree(struct node **tree, int data)
{
	struct node *temp;
	if ((*tree)==NULL){
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		*tree = temp;
		return;
	}
	if (data<(*tree)->data)
	{
		create_tree(&(*tree)->left, data);
	}
	else if (data>(*tree)->data)
	{
		create_tree(&(*tree)->right, data);
	}
}
void create_DLL(struct DoubleNode **head,int data)
{
	struct DoubleNode *q, *temp;
	temp = (struct DoubleNode *)malloc(sizeof(struct DoubleNode));
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		q = *head;
		while (q->next != NULL)
			q = q->next;
		q->next = temp;
		temp->prev = q;
	}
}

void display(struct DoubleNode **head)
{
	struct DoubleNode *p;
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
struct node *create(struct DoubleNode *head)
{
	struct DoubleNode *p;
	struct node *tree;
	tree = NULL;
	p = head;
	while (p != NULL)
	{
		create_tree(&tree, p->data);
		p = p->next;
	}
	return tree;
}
void main()
{
	struct DoubleNode *head;
	struct node *tree;
	head = NULL;
	create_DLL(&head, 1);
	create_DLL(&head, 2);
	create_DLL(&head, 3);
	create_DLL(&head, 4);
	tree = create(head);
	inorder(tree);
	display(&head);
}