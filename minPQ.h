/* minPQ.h (what is the purpose of this file? Replace this question with your comment.)
*/

#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* ***************** Access functions */

/** isEmpty 
*	precondition: MinPQ has been constructed
*/
int isEmptyPQ(MinPQ pq);

/** getMin 
*	precondition: MinPQ has been constructed
*/
int getMin(MinPQ pq);

/** getStatus 
*	precondition: MinPQ has been constructed and status array has been initialized
*/
int getStatus(MinPQ pq, int id);

/** getParent 
*	precondition: MinPQ constructed and parent array initialized
*/
int getParent(MinPQ pq, int id);

/** getPriority 
*	precondition: MinPQ constructed and priority array initialized
*/
double getPriority(MinPQ pq, int id);


/* ***************** Manipulation procedures */

/** delMin 
*	precondition: MinPQ constructed
*	postcondition: min vertex status is INTREE
		minVertex = -1
		numPQ = numPQ -1
*/
void delMin(MinPQ pq);

/** insertPQ 
*	precondition: MinPQ constructed
*	postcondition: parent[id] = par
		fringeWgt[id] = priority
		status[id] = FRINGE
		minVertex = -1
		numPQ = numPQ +1
*/
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey 
*	precondition: MinPQ constructed
*	postcondition: parent[id] = par
		fringeWgt[id] = priority
		minVertex = -1
*/
void decreaseKey(MinPQ pq, int id, double priority, int par);


/* ***************** Constructors */

/** createPQ
*	precondition: none.
*	postcondition: parent, status, and fringeWgt arrays initialized
		numVertices = n
		numPQ = 0
		minVertex = -1
		oo = essentially infinity
		returns MinPQ
*/
MinPQ createPQ(int n, int status[], double priority[], int parent[]);


#endif
