## Navigating the repository

The main code can be found in directly in the **home** directory. 
The data used in this project can be found under **home/data**.
The output is printed to the command line, but a copy can also
be found under **home/results**.

***
## Instructions for building and executing the main program

To make and execute the main program - finding the shortest path 
between airports - copy the following lines into the command prompt
after cloning the repository:

```bash
make main
./main
```

You will be prompted to enter the source/starting airport, and then
the destination airport. *Make sure your spelling and capitalization
of the names is right!*


***
# Instructions for building and executing the testing suite

To make and execute the testing suite, copy the following lines:

```bash
make tests
./tests
```

The 3 tests - BFS, Dijkstra's, and Betweenness Centrality - will be 
run automatically with Catch. The BFS test checks to ensure that
BFS traverses the entirity of the graph. The Dijkstra's test checks
the path between 2 nodes against its known shortest value. The 
Betweenness Centrality test also checks the centrality of a node
against its known value.
