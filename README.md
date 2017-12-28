# prim-dijkstra
The program greedy04 includes a number of files, including the main file (greedy04.c), adjWgtVec.c/.h, loadWgtGraph.c/.h, minPQ.c/.h, Makefile, and 3 test files (graph1.txt, graph2.txt, graph3.txt). The main file, greedy04.c, runs Prim's or Dijkstra's algorithm depending on whether the user input -P or -D in the command prompt. The major difference difference between the algorithms is how the priority is handled, which greedy04.c does in calcPriority(). Prim's algorithm simply looks considers the fringe weights, while Dijkstra's considers the total path weight (distance). The algorithms are handled in the greedyTree() function, which also creates a priority queue using the MinPQ.c file, and uses its functions to insert and delete priorities. The updateFringe() function uses the MinPQ to compare priorities. Once the algorithms are finished, the parent, status, and priority arrays will be filled and printed out. The program handles stdin file input.
