#include<stdio.h>
#include<math.h>
int FindKthElementInSortedMergedProgression(int a1, int r1, int a2, int r2)
{
	int Flag=0,Iterator = 1, N1 = 1, N2 = 1, KTerm = 0,K, CurrentEleInList1 = a1, CurrentEleInList2 = a2;
	printf("Enter K:\n");
	scanf("%d", &K);
	if (K <= 0)
		return -1;
	if (K == 1)
	{
		if (a1 < a2)
			return a1;
		else
			return a2;             // Assuming its a forward progression
	}
	if (a1 < a2)
	{
		KTerm = a1;
		Flag = 1;
	}
	else
	{
		KTerm = a2;
		Flag = 0;
	}
	while (Iterator < K)
	{
		if (Flag == 1)
		{
			CurrentEleInList1 = a1 * pow(r1, N1 - 1);
			N1++;
		}
		else
		{
			CurrentEleInList2 = a2 * pow(r2, N2 - 1);
			N2++;
		}
		if (CurrentEleInList1 < CurrentEleInList2)
		{
			KTerm = CurrentEleInList1;
			Flag = 1;
		}
		else if (CurrentEleInList1 > CurrentEleInList2)
		{
			KTerm = CurrentEleInList2;
			Flag = 0;
		}
		else
		{
			KTerm = CurrentEleInList1;
			CurrentEleInList1 = a1 * pow(r1, N1 - 1);
			N1++;
			CurrentEleInList2 = a2 * pow(r2, N2 - 1);
			N2++;
			Iterator++;
			Flag = 2;
		}
		Iterator++;
	}
	return KTerm;
}