#include<stdio.h>
#include<stdlib.h>
typedef struct b_tree{
	int data;
	struct b_tree *left;
	struct b_tree *right;
}node;
void print_inorder(node * root)
{
	if (root)
	{
		print_inorder(root->left);
		printf("%d\n", root->data);
		print_inorder(root->right);
	}
}
void in_order(node *root, int *max)
{
	if (root)
	{
		int count = 0;
		if ((root->left == NULL) && (root->right == NULL))
			count = 0;
		else if ((root->left != NULL) && (root->right != NULL))
			count = 2;
		else
			count = 1;
		if (count > *max)
			*max = count;
		if (*max == 2)
			return;
		in_order(root->left,max);
		in_order(root->right,max);
	}
}
void weight(node *root)
{
	if (root)
	{
		weight(root->left);
		root->data = 1;
		if (root->left)
			root->data +=root->left->data;

		if (root->right)
			root->data += root->right->data;
	}
}
void create(node **root, int data)
{
	node *temp = NULL;
	if (!(*root))
	{
		temp = (node *)malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = data;
		*root = temp;
	}
	else
	{
	if (data < (*root)->data)
	{
		create(&(*root)->left, data);
	}
	else if (data > (*root)->data)
	{
		create(&(*root)->right, data);
	}
    }
}
void main()
{
	node *root = NULL;
	create(&root,2);
	create(&root, 1);
	create(&root, 3);
	create(&root, 4);
	print_inorder(root);
	//int *max = 0;
	/*in_order(root, &max);
	printf("%d", max);*/
	//weight(&root);
}