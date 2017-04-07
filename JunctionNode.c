#include<stdio.h>
struct ListNode
{
	int data;
	struct ListNode *next;
};
struct ListNode *FindJunctionNode(struct ListNode *FirstList, struct ListNode *SecondList)
{
	int Iterator=0,FirstListLength = 0, SecondListLength = 0,Difference=0;
	if (FirstList == NULL || SecondList == NULL)
		return NULL;
	struct ListNode *head1 = FirstList, *head2 = SecondList;
	while (head1 != NULL)
	{
		FirstListLength++;
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		SecondListLength++;
		head2 = head2->next;
	}
	if (FirstListLength < SecondListLength)
	{
		head1 = SecondList;
		head2 = FirstList;
		Difference = SecondListLength - FirstListLength;
	}
	else
	{
		head2 = SecondList;
		head1 = FirstList;
		Difference = FirstListLength - SecondListLength;
	}
	for (Iterator = 0; Iterator < Difference; Iterator++)
	{
		head1 = head1->next;
	}
	while (head1 != NULL && head2 != NULL)
	{
		if (head1 == head2)
			return head1;
		head1 = head1->next;
		head2 = head2->next;
	}
	return NULL;
}