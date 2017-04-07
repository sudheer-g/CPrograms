#include<stdio.h>
/*void main()
{
	int arr[100][100],rotatedarr[100][100];
	int i = 0, j = 0,rotated_i=0,rotated_j=0;
	int n = 3;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	j = 0;
	for (rotated_i = 0; rotated_i < n; rotated_i++)
	{
		i = 2;
		for (rotated_j = 0; rotated_j < n; rotated_j++)
		{
			rotatedarr[rotated_i][rotated_j] = arr[i][j];
			i--;
		}
		j++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", rotatedarr[i][j]);
		}
		printf("\n");
	}
}*/
void main()
{
	int arr[100][100];
	int i = 0, j = 0;
	int n = 3;
	int layer = 0;
	int first = 0;
	int last = 0,offset=0,top=0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (layer=0;layer < n/2; layer++)
	{
		first = layer;
		last = n - 1 - layer;
		for (i = first; i < last; i++)
		{
			offset = i - first;
			top = arr[first][i];
			arr[first][i] = arr[last - offset][first];
			arr[last - offset][first] = arr[last][last - offset];
			arr[last][last - offset] = arr[i][last];
			arr[i][last] = top;

		}

	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

}