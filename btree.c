#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;
void preorder(struct node *tree){
	if (tree)
	{
		printf("%d\n", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
void inorder(struct node *tree){
	if (tree)
	{
		inorder(tree->left);
		printf("%d\n", tree->data);
		inorder(tree->right);
	}
}
void postorder(struct node *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	printf("%d\n", tree->data);
}
void insert(struct node **tree, int data)
{
	struct node *temp;
	if (!(*tree))
	{
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	*tree = temp;
	return;
      }
	if (data<(*tree)->data)
	{
		insert(&(*tree)->left, data);
	}
	else if (data>(*tree)->data)
	{
		insert(&(*tree)->right, data);
	}
}
struct node *FindMinNodeInABranch(struct node *root)
{
	struct node *currentNode = root;
	if (currentNode->left != NULL)
	{
		currentNode = currentNode->left;
	}
	return currentNode;
}
struct node *InorderSuccessor(struct node *root, struct node *CurrentNode)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (CurrentNode->right != NULL)
	{
		return FindMinNodeInABranch(CurrentNode->right);
	}
	struct node *InorderSuccessor = NULL;
	while (root != NULL)
	{
		if (CurrentNode->data < root->data)
		{
			InorderSuccessor = root;
			root = root->left;
		}
		else if (CurrentNode->data > root->data)
		{
			root = root->right;
		}
		else
			break;
	}
	return InorderSuccessor;
}
void main()
{
	struct node *root;
	struct node *CurrentNode = NULL;
	struct node *inorderSuccessor=NULL;
	root = NULL;
	insert(&root, 20);
	insert(&root, 8);
	insert(&root, 22);
	insert(&root, 4);
	insert(&root, 12);
	insert(&root, 10);
	insert(&root, 14);
	CurrentNode = root->left->right->right;
	//inorder(root);
	inorderSuccessor = InorderSuccessor(root, CurrentNode);
	printf("%d", inorderSuccessor->data);
	
}