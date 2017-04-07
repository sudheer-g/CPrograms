#include<stdio.h>
#define LOAD_FACTOR 20
struct ListNode
{
	int key;
	int data;
	struct ListNode *next;
};
struct HashTableNode
{
	int bcount;
	struct ListNode *next;
};
struct HashTable
{
	int tsize;
	int count;
	struct HashTableNode **Table;
};
struct HashTable *CreateHashTable(int size)
{
	struct HashTable *h;
	int i = 0;
	h = (struct HashTable *)malloc(sizeof(struct HashTable));
	if (!(h))
	{
		return NULL;
	}
	h->tsize = size / LOAD_FACTOR;
	h->count = 0;
	h->Table = (struct HashTableNode **)malloc(sizeof(struct HashTableNode *)* h->tsize);
	if (!(h->Table))
	{
		printf("Memory Error");
		return NULL;
	}
	for (i = 0; i < h->tsize; i++)
	{
		h->Table[i]->next = NULL;
		h->Table[i]->bcount = 0;
	}
	return h;
}
int HashSearch(struct HashTable *h, int data)
{
	struct ListNode *temp;
	temp = h->Table[Hash()]
}