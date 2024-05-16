// id:322530080 mail:avishb1213@gmail.com

// demo class to run the code.
#include "Algorithms.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace ariel;

// will print 3 new lines
void print_space()
{
    cout << endl;
    cout << endl;
    cout << endl;
}
int main()
{
    print_space();
    Graph g1;
    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g1.loadGraph(graph1, true);
    cout << g1; // usege of cout operator.
    cout << endl;
    cout << "algorithems on graph1:     " << endl;
    cout << "isConnected:";
    cout << Algorithms::isConnected(g1) << endl; // Should print: "0" (false).
    cout << "shortestPath:";
    cout << Algorithms::shortestPath(g1, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << "isContainsCycle:";
    cout << Algorithms::isContainsCycle(g1) << endl; // Should print: "The cycle is: 0->1->2->0".
    cout << "isBipartite:";
    cout << Algorithms::isBipartite(g1) << endl; // Should print: "0" (false).

    print_space();

    Graph nc;
    cout << "graph with negative cycle:";
    vector<vector<int>> negative_cycle =
        {{0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 99},
         {0, 0, -100, 0}};
    nc.loadGraph(negative_cycle, true);
    cout << "graph3 print:" << endl;
    nc.printGraph();
    cout << "the negative cycle:";
    cout << Algorithms::negativeCycle(nc);
    print_space();


    // 5x5 matrix that reprsents a connected weighted graph.
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g2.loadGraph(graph2, true);
    cout << g2; // usege of cout operator.
    print_space();
    Graph g3;
    cout << "operators usege:" << endl;

    g3 = g1 + g2;
    cout << "+ operator: graph1 + graph2" << endl;
    g3.print_adjacencyMatrix();
    print_space();

    g3 = g1 - g2;
    cout << "- operator: graph1 - graph2" << endl;
    g3.print_adjacencyMatrix();
    print_space();

    g3 = ++g1;
    cout << "++ operator: ++graph1" << endl;
    g3.print_adjacencyMatrix();
    print_space();

    g1 += g2;
    cout << "+= operator: graph1 += g2" << endl;
    g1.print_adjacencyMatrix();
    print_space();

    g1 -= g2;
    cout << "-= operator: graph1 -= g2" << endl;
    g1.print_adjacencyMatrix();
    print_space();

    g3 = --g1;
    cout << "-- operator: --graph1" << endl;
    g3.print_adjacencyMatrix();
    print_space();

    g3 = +g1;
    cout << "unary + operator: +graph1" << endl;
    g3.print_adjacencyMatrix();
    print_space();

    g3 = -g1;
    cout << "unary - operator: -graph1" << endl;
    g3.print_adjacencyMatrix();
    print_space();

    g3 = g1 * 3;
    cout << "*(int) operator: graph1*3" << endl;
    g3.print_adjacencyMatrix();
    print_space();

    g3 = g1 * g2;
    cout << "* operator: graph1 * graph2" << endl;
    g3.print_adjacencyMatrix();
    print_space();

    cout << "graph1 == graph2 ? ";
    cout << (graph1 == graph2);
    print_space();

    cout << "graph1 != graph2 ? ";
    cout << (graph1 != graph2);
    print_space();

    cout << "graph1 < graph2 ? ";
    cout << (graph1 < graph2);
    print_space();

    cout << "graph1 <= graph2? ";
    cout << (graph1 <= graph2);
    print_space();

    cout << "graph1 > graph2 ? ";
    cout << (graph1 > graph2);
    print_space();

    cout << "graph1 >= graph2 ? ";
    cout << (graph1 >= graph2) << endl;
    return 0;
}
