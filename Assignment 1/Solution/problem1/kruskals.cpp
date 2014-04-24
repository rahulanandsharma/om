#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


struct Edge
{
	int src, dest, weight;
	int edgeno;
};

struct Graph
{
	int V, E;
	struct Edge* edge;
};


struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
	graph->V = V;
	graph->E = E;

	graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

	return graph;
}

struct subset
{
	int parent;
	int rank;
};

int find(struct subset subsets[], int i)
{

	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}


void KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	struct Edge result[V];  // Tnis will store the resultant MST
	int e = 0;  // An index variable, used for result[]
	int i = 0;  // An index variable, used for sorted edges

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);


	struct subset *subsets =
		(struct subset*) malloc( V * sizeof(struct subset) );

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Number of edges to be taken is equal to V-1
	while (e < V - 1)
	{
		// Step 2: Pick the smallest edge. And increment the index
		// for next iteration
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does't cause cycle, include it
		// in result and increment the index of result for next edge
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// Else discard the next_edge
	}

	int sum=0;
	for (i = 0; i < e; ++i)
	{
	cout<<result[i].edgeno<<" ";
	sum+=result[i].weight;
	}
	cout<<endl;
	cout<<sum<<endl;
	return;
}

// Driver program to test above functions
int main()
{
	int V = 4;  // Number of vertices in graph
	int E = 5;  // Number of edges in graph

	cin>>V>>E;

	struct Graph* graph = createGraph(V, E);

	for(int i=0;i<E;i++)
	{
		cin>>graph->edge[i].src;
		cin>>graph->edge[i].dest;
		cin>>graph->edge[i].weight;
		graph->edge[i].edgeno=i;
	}
	KruskalMST(graph);
	return 0;
}
