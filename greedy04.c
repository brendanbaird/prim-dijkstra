#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adjWgtVec.h"
#include "loadWgtGraph.h"
#include "minPQ.h"

void greedyTree(int* status, int* parent, double* fringeWgt, AdjWgtVec * adjInfo);

void updateFringe(MinPQ pq, int v, AdjWgtVec * adjInfo);

double calcPriority(MinPQ pq, AdjWgt wInfo, int v);

int printOutput(MinPQ pq);

static int n;				// number of vertices
//static AdjWgtVec * adjInfo;
static int task;			// 'P' or 'D'
static int s;				// start vertex

int main(int argc, char* argv[])
{
	AdjWgtVec * adjInfo;
	int m;	// number of edges
	int * status;
	int * parent;
	double * fringeWgt;
	char line[1024];
	FILE *fp;
	char* lPtr;

	if (argc == 1)
	{
		printf("No input data\n");
		exit(1);
	}

	// decides whether Prim's or Dijkstra's algorithm runs
	if (strcmp(argv[1], "-P") == 0)
		task = 'P';

	else if (strcmp(argv[1], "-D") == 0)
		task = 'D';

	s = atoi(argv[2]);	// finds starting vertex

	if (strcmp(argv[3], "-") == 0)
	{
		fp = stdin;
	}
	else
	{
		fp = fopen(argv[3], "r");
	}
	
	printf("Opened %s for input.\n", argv[3]);
	
	lPtr = fgets(line, 1024, fp);
	n = parseN(lPtr);	// finds number of vertices
	printf("n = %d\n", n);

	adjInfo = initAdjInfo(n);	// allocates space for AdjWgtVec adjInfo

	// loads undirected edges if doing Prim's algorithm
	if (task == 'P')
		m = loadAdjInfoU(fp, adjInfo);
	else
		m = loadAdjInfo(fp, adjInfo);
	
	fclose(fp);
	
	printf("m = %d\n", m);

	// allocating space for arrays to be used in greedyTree
	status = malloc((n+1) * sizeof(int));
	parent = malloc((n+1) * sizeof(int));
	fringeWgt = malloc((n+1) * sizeof(double));

	greedyTree(status, parent, fringeWgt, adjInfo);

	return 0;
}

void greedyTree(int* status, int* parent, double* fringeWgt, AdjWgtVec* adjInfo)
{
	for (int i = 1; i <= n; i++)
	{
		status[i] = UNSEEN; // initializing all vertices as unseen
		parent[i] = -1;		// initializing all vertices to have parents of -1
	}

	MinPQ pq = createPQ(n, status, fringeWgt, parent);

	insertPQ(pq, s, 0, -1);
	while (isEmptyPQ(pq) != 0)
	{
		int v = getMin(pq);
		delMin(pq);
		updateFringe(pq, v, adjInfo);
	}
	printOutput(pq);
}

void updateFringe(MinPQ pq, int v, AdjWgtVec* adjInfo)
{
	while (adjWgtSize(adjInfo[v]) != 0) // loops until no more fringe vertices on vertex v
	{
		AdjWgt wInfo = adjWgtTop(adjInfo[v]);
		int w = wInfo.to;
		double priority = calcPriority(pq, wInfo, v);

		if (getStatus(pq, w) == UNSEEN)
			insertPQ(pq, w, priority, v);

		else if (getStatus(pq, w) == FRINGE)
			if (priority < getPriority(pq, w))
				decreaseKey(pq, w, priority, v);

		adjWgtVecPop(adjInfo[v]);
	}
}

// finds weight/distance depending on chosen algorithm
double calcPriority(MinPQ pq, AdjWgt wInfo, int v)
{
	if (task == 'P')
		return (wInfo.wgt);

	else if (task == 'D')
		return (getPriority(pq, v) + wInfo.wgt);

	return 0;
}

// prints all the arrays
int printOutput(MinPQ pq)
{
	printf("Vertex\tStatus\tPriority\tParent\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d\t", i);
		if (getStatus(pq, i) == UNSEEN)
			printf("unseen\t");
		else if (getStatus(pq, i) == FRINGE)
			printf("fringe\t");
		else if (getStatus(pq, i) == INTREE)
			printf("in tree\t");
		printf("%lf\t%d\n", getPriority(pq, i), getParent(pq, i));
	}
	return 0;
}

