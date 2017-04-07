#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	int data;
	struct ListNode *left;
	struct ListNode *right;
};
void inorder(struct TreeNode * root, void(*visit)(struct TreeNode*))
{
	if (root == NULL)
		return;

	inorder(root->left, visit);
	visit(root);
	inorder(root->right, visit);
}
struct TreeNode *NewNode(int data)
{
	struct TreeNode *node = NULL;
	node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
int SearchRootInInorder(int *InorderArray, int RootValue,int StartIndex,int EndIndex)
{
	int InorderArrayIterator = 0;
	for (InorderArrayIterator = StartIndex; InorderArrayIterator < EndIndex; InorderArrayIterator++)
	{
		if (InorderArray[InorderArrayIterator] == RootValue)
			return InorderArrayIterator;
	}
}
struct TreeNode *ConstructTreeFromInorderAndPreorder(int *InorderArray, int *PreorderArray, int FirstIndex, int LastIndex, int *PreOrderIterator)
{
	int CurrentRootIndex = 0;
	struct TreeNode *root;
	if (FirstIndex > LastIndex)
		return NULL;
	root = NewNode(PreorderArray[(*PreOrderIterator)]);
	(*PreOrderIterator)++;
	if (FirstIndex == LastIndex)
		return root;
	CurrentRootIndex = SearchRootInInorder(InorderArray, root->data, FirstIndex, LastIndex);
	root->left = ConstructTreeFromInorderAndPreorder(InorderArray, PreorderArray, FirstIndex, CurrentRootIndex - 1, PreOrderIterator);
	root->right = ConstructTreeFromInorderAndPreorder(InorderArray, PreorderArray, CurrentRootIndex + 1, LastIndex, PreOrderIterator);
	return root;
}
void printNode(struct TreeNode * root)
{
	printf("%d ", root->data);
}
void main()
{
	int InorderArray[] = { 4, 2, 5, 1, 6, 3 };
	int PreorderArray[] = { 1, 2, 4, 5, 3, 6 };
	int LengthOfTree = 6;//sizeof(InorderArray)/sizeof(InorderArray[0]);
	int PreOrderIterator = 0;
	struct TreeNode *root=NULL;
	root=ConstructTreeFromInorderAndPreorder(InorderArray, PreorderArray, 0, LengthOfTree - 1,&PreOrderIterator);
	inorder(root, printNode);
}