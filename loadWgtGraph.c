#include "loadWgtGraph.h"

AdjWgt parseEdge(char line[]);

static int from;

AdjWgtVec* initAdjInfo(int n)
{
	AdjWgtVec *adjInfo = calloc((n+1), sizeof(AdjWgtVec));

	for (int i = 1; i <= n; i++)
	{
		adjInfo[i] = adjWgtMakeEmptyVec();
	}
	return adjInfo;
}

int loadAdjInfoU(FILE *fp, AdjWgtVec * adjInfo)
{
	int m;
	char* lPtr;
	char line[1024];

	m = 0;
	lPtr = fgets(line, 1024, fp);
	while (lPtr != NULL)
	{
		AdjWgt e = parseEdge(lPtr);
		adjWgtVecPush(adjInfo[from], e);
		int temp = e.to;
		e.to = from;
		from = temp;
		adjWgtVecPush(adjInfo[from], e);
		lPtr = fgets(line, 1024, fp);
		m++;
	}
	return m;
}

int loadAdjInfo(FILE *fp, AdjWgtVec * adjInfo)
{
	int m;
	char* lPtr;
	char line[1024];

	m = 0;
	lPtr = fgets(line, 1024, fp);
	while (lPtr != NULL)
	{
		AdjWgt e = parseEdge(lPtr);
		adjWgtVecPush(adjInfo[from], e);
		lPtr = fgets(line, 1024, fp);
		m++;
	}
	return m;
}

//Scans the line for edges
AdjWgt parseEdge(char line[])
{
	AdjWgt newE;
	int numFields;
	numFields = sscanf(line, "%d %d %lf", &from, &newE.to, &newE.wgt);
	if (numFields < 2 || numFields > 3)
	{
		printf("Bad edge: %s\n", line);
		exit(2);
	}

	if (numFields == 2)
		newE.wgt = 0.0;
	return newE;
}

int parseN(char line[])
{
	int n;
	int numFields;
	numFields = sscanf(line, "%d %*s", &n);
	if (numFields != 1)
	{
		printf("Bad line 1: %s\n", line);
		exit(3);
	}
	return n;
}

