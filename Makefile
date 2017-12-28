CC = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

greedy04: greedy04.o adjWgtVec.o loadWgtGraph.o minPQ.o
	${CC} 	-o greedy04 ${CFLAGS} greedy04.o adjWgtVec.o loadWgtGraph.o minPQ.o

greedy04.o: greedy04.c adjWgtVec.h loadWgtGraph.h minPQ.h
	${CC} 	-c ${CFLAGS} greedy04.c

adjWgtVec.o: adjWgtVec.c adjWgtVec.h
	${CC} 	-c ${CFLAGS} adjWgtVec.c

loadWgtGraph.o: loadWgtGraph.c loadWgtGraph.h
	${CC}	-c ${CFLAGS} loadWgtGraph.c

minPQ.o: minPQ.c minPQ.h
	${CC}	-c ${CFLAGS} minPQ.c
