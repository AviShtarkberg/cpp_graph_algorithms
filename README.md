# cpp_graph_algorithms

In this repository, you will find a variety of graph algorithms.
A graph in this project will be represented as an adjacency matrix.

The files for this project and explanations about the implementation: 

Graph.hpp and Graph.cpp will hold the graph class with all the declarations and implementations of the methods that are going to be done on a graph. Some of the functions will be in this class. The main method in this class is the load graph method, in which the matrix will be passed and a boolean variable will be used to determine if the graph is directed. Inside this method, only a squerd matrix can be passed, and self-edges are not allowed (meaning that the diagonal of the matrix must be zeros). If you want to pass a directed graph, the matrix must be symetric (exceptions will be thrown). Other functions will be used to check if there is a negative edge in the matrix and will set the number of edges automatically as the matrix is passed to the load graph method.

Algorithms.hpp and Algorithms.cpp will be responsible for all the algorithms that are going to be done on a graph:

1) isConnected: will run a DFS function that will check if all the vertexes are visited. will be split into two: If the graph is directed, it will run DFS from a single point; if all the vertices are visible, then the graph is connected. If the graph is undircted, it will run dfs from each vertex to check for connectivity components.

2) isContainsCycle: will run a dfs and will check if a visited vertex is visited again, while the dfs runs will hold a stack that holds the current path and an array that holds the visited vertexes. If a vertex is visited again inside the same path, there is a cycle, and the function will return the path of this cycle.

3) shortestPath: will be split into two:

a. If the matrix does not contain negative edges, it will run a simple Dijkstra algorithm.

b. If there is a negative edge, even just one, will run the Bellman-Ford algorithm.

If there is no path between the two asked vertexes or there is a negative cycle in the graph (which will be detected by the Bellman Ford algorithm), it will return -1. If there is a path, it will return it as a string.

4) isBipartite: will run the BFS algorithm to check if the graph is 2-colered. To do so, a map will be used to determine the relationship between the vetex (int) and the color (boolean). While running the DFs, if a vertex is connected to two vertex with different colors the function will return 0, detecting that the graph is not bipartite. If it is, it will return the parttion into two groups.

5) negativeCycle: will use the same Bellman Ford function as the shortest path. Will run the relaxation process n-1 times, and then if there was a change in the nth time, will return the negative cycle itself, track back through the parents of the vertex, which was the one that made the change in the nth time, and at the end will return the negative cycle as a string.

All this function will get as arguments the graph after being loaded. The shortest path will also get start and end vertex.



Inside the repository, you can also find a test.cpp file that will run varius tests to test the graph class and the agorithms class, and a demo file that will demonstrate the running part of the code. 

Use the comman "make run" to run the tests and the demo file. 
