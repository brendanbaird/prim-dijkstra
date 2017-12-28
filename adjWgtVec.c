#include <stdlib.h>
#include <stdio.h>
#include "adjWgtVec.h"

struct AdjWgtVecNode
{
	AdjWgt* data;
	int sz;
	int capacity;
};

AdjWgt adjWgtTop(AdjWgtVec myVec)
{
	return myVec->data[(myVec->sz)-1];
}

AdjWgt adjWgtData(AdjWgtVec myVec, int i)
{
	return myVec->data[i];
}

int adjWgtSize(AdjWgtVec myVec)
{
	return myVec->sz;
}

int adjWgtCapacity(AdjWgtVec myVec)
{
	return myVec->capacity;
}

AdjWgtVec adjWgtMakeEmptyVec(void)
{
	AdjWgtVec newVec = malloc(sizeof(struct AdjWgtVecNode));
	newVec->data = calloc(adjWgtInitCap, sizeof(AdjWgt));
	newVec->sz = 0;
	newVec->capacity = adjWgtInitCap;
	return newVec;
}

void adjWgtVecPush(AdjWgtVec myVec, AdjWgt newE)
{
	int newCap;
	AdjWgt* newData;

	myVec->sz = adjWgtSize(myVec)+1;
	myVec->data[adjWgtSize(myVec)-1] = newE;
	if (adjWgtSize(myVec)+1 > myVec->capacity)
	{
		newCap = 2 * myVec->capacity;
		newData = realloc(myVec->data, newCap * sizeof(AdjWgt));
		if (newData != myVec->data) { myVec->data = newData; }
		myVec->capacity = newCap;
	}
}

void adjWgtVecPop(AdjWgtVec myVec)
{
	myVec->sz = myVec->sz-1;
}

