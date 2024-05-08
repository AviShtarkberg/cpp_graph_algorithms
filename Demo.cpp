// id:322530080 mail:avishb1213@gmail.com
#include "Algorithms.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using ariel::Algorithms;
int main()
{
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false); // Load the graph to the object.
    cout << "graph1 print:" << endl;
    g.printGraph();
    cout << endl;

    cout << "algorithems on graph1:     " << endl;
    cout << "isConnected:";
    cout << Algorithms::isConnected(g) << endl; // Should print: "1" (true).
    cout << "shortestPath:";
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << "isContainsCycle:";
    cout << Algorithms::isContainsCycle(g) << endl; // Should print: "0" (false).
    cout << "isBipartite:";
    cout << Algorithms::isBipartite(g) << endl; // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    cout << endl;
    cout << endl;
    cout << endl;

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2, false); // Load the graph to the object.
    cout << "graph2 print:" << endl;
    g.printGraph();
    cout << endl;
    cout << "algorithems on graph2:     " << endl;
    cout << "isConnected:";
    cout << Algorithms::isConnected(g) << endl; // Should print: "0" (false).
    cout << "shortestPath:";
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << "isContainsCycle:";
    cout << Algorithms::isContainsCycle(g) << endl; // Should print: "The cycle is: 0->1->2->0".
    cout << "isBipartite:";
    cout << Algorithms::isBipartite(g) << endl; // Should print: "0" (false).

    cout << endl;
    cout << endl;
    cout << endl;

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3, false); // Load the graph to the object.
    cout << "graph3 print:" << endl;
    g.printGraph();
    cout << endl;
    cout << "algorithems on graph3:     " << endl;
    cout << "isConnected:";
    cout << Algorithms::isConnected(g) << endl; // Should print: "1" (true).
    cout << "shortestPath:";
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
    cout << "isContainsCycle:";
    cout << Algorithms::isContainsCycle(g) << endl; // Should print: "0->1->2->0" (false).
    cout << "isBipartite:";
    cout << Algorithms::isBipartite(g) << endl; // Should print: "The graph is bipartite: 0."
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "graph with negative cycle:";
    vector<vector<int>> negative_cycle =
        {{0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 99},
         {0, 0, -100, 0}};
    g.loadGraph(negative_cycle, true);
    cout << "graph3 print:" << endl;
    g.printGraph();
    cout << "the negative cycle:";
    cout << Algorithms::negativeCycle(g);
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}