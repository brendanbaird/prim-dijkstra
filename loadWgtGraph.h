#ifndef C101loadWgtGraph
#define C101loadWgtGraph

#include <stdio.h>
#include <stdlib.h>
#include "adjWgtVec.h"

//Contructs a list of empty vectors
AdjWgtVec* initAdjInfo(int n);

// Loads edges into data for connected vectors
int loadAdjInfo(FILE *fp, AdjWgtVec * adjInfo);

// Loads undirected edges into data
int loadAdjInfoU(FILE *fp, AdjWgtVec * adjInfo);

//Reads the first line of the text file and returns number of vertices
int parseN(char line[]);

#endif