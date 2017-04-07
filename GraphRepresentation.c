#include<stdio.h>
#include<stdlib.h>
struct Graph_Matrix
{
	int V;
	int E;
	int **Adj;
};
struct Graph_List
{
	int V;
	int E;
	int *Adj;
};
struct Graph_Matrix *adjMatrixOfGraph()
{
	int i, u, v;
	struct Graph_Matrix *G = (struct Graph_Matrix *)malloc(sizeof(struct Graph_Matrix));
	if (!G)
	{
		printf("Memory Error");
		return;
	}
	scanf("%d%d", &G->V, &G->E);
	G->Adj = (int **)malloc(sizeof(int *)*G->V);
	G->Adj[0] = (int *)malloc(sizeof(int)*G->V*G->V);
	for (i = 0; i < G->V; i++)
		G->Adj[i] = (*G->Adj + G->V * i);
	for (u = 0; u < G->V; u++)
	{
		for (v = 0; v < G->V; v++)
		{
			G->Adj[v][v] = 0;
		}
	}
	for (i = 0; i < G->E; i++)
	{
		fflush(stdin);
		scanf("%d%d", &u, &v);
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}
void main()
{
	adjMatrixOfGraph();
}