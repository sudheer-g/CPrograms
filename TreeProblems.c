#include<stdio.h>
#include<stdlib.h>
int MaximumNumber = 0;
struct Node
{
	int value;
	struct Node * left;
	struct Node * right;
};
typedef struct Node Node;
struct ListNode
{
	int data;
	struct ListNode *next;
};
struct Queue
{
	struct ListNode *front;
	struct ListNode *rear;
};
struct Queue *CreateQueue()
{
	struct Queue *Q;
	struct ListNode *temp;
	Q = malloc(sizeof(struct Queue));
	if (!Q)
	{
		return NULL;
	}
	temp = malloc(sizeof(struct ListNode));
	Q->front = Q->rear = NULL;
	return Q;
}
int IsEmptyQueue(struct Queue *Q)
{
	return (Q->front == NULL);
}
void Enqueue(struct Queue *Q, int data)
{
	struct ListNode *newNode;
	newNode = malloc(sizeof(struct ListNode));
	if (!newNode)
	{
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	if (Q->rear)
	{
		Q->rear->next = newNode;
	}
	Q->rear = newNode;
	if (Q->front == NULL)
		Q->front = Q->rear;
}
int DeQueue(struct Queue *Q)
{
	int data = 0;
	struct ListNode *temp;
	if (IsEmptyQueue(Q))
	{
		printf("Empty Queue");
		return 0;
	}
	else
	{
		temp = Q->front;
		data = Q->front->data;
		if (Q->front->next!=NULL)
		   Q->front = Q->front->next;
		else
		{
			Q->front = NULL;
			Q->rear = NULL;
			free(Q->front);
			free(Q->rear);
			return data;
		}
		free(temp);
	}
	return data;
}
void DeleteQueue(struct Queue *Q)
{
	struct ListNode *temp;
	while (Q->front!=NULL)
	{
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
	free(Q);
}
Node* createNode(int value)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void inorder(Node * root, void(*visit)(Node*))
{
	if (root == NULL)
		return;

	inorder(root->left, visit);
	visit(root);
	inorder(root->right, visit);
}
void preorder(Node * root, void(*visit)(Node*))
{
	if (root == NULL)
		return;

	visit(root);
	preorder(root->left, visit);
	preorder(root->right, visit);
}
void postorder(Node * root, void(*visit)(Node*))
{
	if (root == NULL) 
		return;

	postorder(root->left, visit);
	postorder(root->right, visit);
	visit(root);
}
void LevelOrder(Node *root, void(*visit)(Node*))
{
	Node *temp;
	struct Queue *Q = CreateQueue();
	if (!root)
		return;
	Enqueue(Q, root);
	while (!IsEmptyQueue(Q))
	{
		temp = DeQueue(Q);
		visit(temp);
		if (temp->left)
			Enqueue(Q, temp->left);
		if (temp->right)
			Enqueue(Q, temp->right);
	}
	DeleteQueue(Q);
}
void printNode(Node * root)
{
	printf("%d ", root->value);
}
void FindMaxNumber(Node *root)
{
	if (root->value > MaximumNumber)
		MaximumNumber = root->value;
}
int FindMaximumNumberWithoutGlobalVariableThroughRecursion(Node *root)
{
	int RootValue,MaxInLeftSubtree=0, MaxInRightSubtree=0, MaximumNumber = 0;
	if (root != NULL)
	{
		RootValue = root->value;
		MaxInLeftSubtree = FindMaximumNumberWithoutGlobalVariableThroughRecursion(root->left);
		MaxInRightSubtree = FindMaximumNumberWithoutGlobalVariableThroughRecursion(root->right);
		if (MaxInLeftSubtree > MaxInRightSubtree)
			MaximumNumber = MaxInLeftSubtree;
		else
			MaximumNumber = MaxInRightSubtree;
		if (RootValue > MaximumNumber)
			MaximumNumber = RootValue;
	}
	return MaximumNumber;
}
void FindMaximumNumberWithoutGlobalVariableThroughIteration(Node *root)
{
	int max = 0;
	struct Queue *Q = CreateQueue();
	struct Node *CurrentNode = NULL;
	Enqueue(Q, root);
	while (!IsEmptyQueue(Q))
	{
		CurrentNode = DeQueue(Q);
		if (max < CurrentNode->value)
		{
			max = CurrentNode->value;
		}
		if (CurrentNode->left)
		{
			Enqueue(Q, CurrentNode->left);
		}
		if (CurrentNode->right)
		{
			Enqueue(Q, CurrentNode->right);
		}
	}
	DeleteQueue(Q);
	printf("The Max is: %d \n", max);
}
int FindLevelWithMaximumSum(Node *root)
{
	int CurrentSum = 0, MaxSum = 0, LevelWithMaxSum = 0,CurrentLevel=0;
	Node *CurrentNode = NULL;
	struct Queue *Q = CreateQueue();
	Enqueue(Q, root);
	Enqueue(Q, NULL);
	while (!IsEmptyQueue(Q))
	{
		CurrentNode = DeQueue(Q);
		if (CurrentNode == NULL)
		{
			if (CurrentSum > MaxSum)
			{
				MaxSum = CurrentSum;
				LevelWithMaxSum = CurrentLevel;
			}
			CurrentSum = 0;
			if (!IsEmptyQueue(Q))
			{
				Enqueue(Q, NULL);
			}
			CurrentLevel++;
		}
		else
		{
			CurrentSum += CurrentNode->value;
			if (CurrentNode->left)
				Enqueue(Q, CurrentNode->left);
			if (CurrentNode->right)
				Enqueue(Q, CurrentNode->right);
		}
	}
	DeleteQueue(Q);
	return LevelWithMaxSum;
}
int HeightOfTree(Node *root)
{
	int LeftHeight = 0, RightHeight = 0;
	if (root == NULL)
		return 0;
	else{
		LeftHeight = HeightOfTree(root->left);
		RightHeight = HeightOfTree(root->right);
		if (LeftHeight > RightHeight)
			return LeftHeight + 1;
		else
			return RightHeight + 1;
	}
}
void SearchElementInTree(Node *root, int Element,int *FoundFlag)
{
	if (root != NULL)
	{
		if (Element == root->value)
		{
			*FoundFlag = 1;
			return;
		}
		SearchElementInTree(root->left, Element,FoundFlag);
		SearchElementInTree(root->right, Element,FoundFlag);
	}
	return;
}
void FindNumberOfFullNodes(Node *root, int *FullNodeCount)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left&&root->right)
		(*FullNodeCount)++;
	FindNumberOfFullNodes(root->left, FullNodeCount);
	FindNumberOfFullNodes(root->right,FullNodeCount);
}

void PrintPath(int *PathArray, int PathLen)
{
	int Iterator = 0;
	for (Iterator = 0; Iterator < PathLen; Iterator++)
		printf("%d->", PathArray[Iterator]);
}

void PrintAllPathsFromRootToLeaf(Node *root, int *PathArray,int PathLen)
{
	if (root == NULL)
		return;
	PathArray[PathLen++] = root->value;
	if ((root->left == NULL) && (root->right == NULL))
	{
		PrintPath(PathArray, PathLen);
		printf("\n");
	}
	else
	{
		if (root->left)
			PrintAllPathsFromRootToLeaf(root->left, PathArray, PathLen);
		if (root->right)
			PrintAllPathsFromRootToLeaf(root->right, PathArray, PathLen);
	}
}
void main()
{
	int SearchResult = 0, FullNodeCount = 0,LevelWithMaxSum=0;
	int PathArray[100];
	Node *n10 = createNode(10);
	Node* n20 = createNode(20);
	Node* n30 = createNode(30);
	Node* n40 = createNode(40);
	Node* n50 = createNode(50);
	n10->left = n20;
	n20->right = n50;
	n10->right = n40;
	n50->right = n30;
	Node *root = n10;
	//postorder(root, printNode);
	//LevelOrder(root, printNode);
	//FindMaximumNumberWithoutGlobalVariableThroughIteration(root);
	//FindNumberOfFullNodes(root, &FullNodeCount);
	//printf("%d",FullNodeCount);
	LevelWithMaxSum = FindLevelWithMaximumSum(root);
	printf("%d", LevelWithMaxSum);
	//PrintAllPathsFromRootToLeaf(root, PathArray, 0);
//	printf("\nThe Maximum Number in the Tree is:\n");
	//inorder(root, FindMaxNumber);
	//MaximumNumber=FindMaximumNumberWithoutGlobalVariableThroughRecursion(root);
//	SearchElementInTree(root, 70,&SearchResult);
//	if (SearchResult == 1)
//		printf("\nElement Found");
//	else
//		printf("\nNot Found");
	//printf("%d", MaximumNumber);
	//printf("\nHeight of tree:%d", HeightOfTree(root));
}