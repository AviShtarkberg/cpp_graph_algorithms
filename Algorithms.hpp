// id:322530080 mail:avishb1213@gmail.com
#include "Graph.hpp"
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
namespace ariel
{
    class Algorithms
    {
    private:
        // used in isConnected.
        static int isConnectedUndirected(vector<vector<int>> &matrix, vector<bool> &visited, int num_of_ver);

        // used in isConnected.
        static int isConnectedDirected(vector<vector<int>> &matrix, int num_of_ver);

        // used in isConnected.
        static void dfs_for_connected(int start, vector<bool> &visited, vector<vector<int>> matrix, int &visited_size);

        // used in isContainsCycle.
        static bool dfs_for_cycle(Graph g, int start, vector<int> &visited,  vector<vector<int>> &matrix, vector<int> &is_in_path, stack<int> &path, size_t parent);

        // used in isContainsCycle.
        static vector<int> create_array_from_stack(stack<int> stack);

        // used in shortestPath, isContainsCycle, negative cycle.
        static string return_path(vector<int> &reversed_path);

        // will be used in negativeCycle.
        static string return_path(stack<int> &reversed_path);

        // used in shortestPath.
        static void Path(stack<int> &path, int end, vector<int> &parents);

        // used in shortestPath.
        static string end_shortest_path(vector<int> parents, int end);

        // used in shortestPath and negativecycle.
        static vector<int> bellmanFord(Graph g, int startVertex, stack<int> &cycle);

        // used in shortestPath.
        static vector<int> dijkstra(vector<vector<int>> adjacencyMatrix, int startVertex);

        // used for isBipartite.
        static unordered_map<int, bool> bfs_for_bipartite(vector<bool> &visited, vector<vector<int>> matrix, int start, unordered_map<int, bool> &colors_map);

        // used for isBipartite.
        static string return_partion(unordered_map<int, bool> umap);

        // used for isBipartite.
        static bool allVisited(vector<bool> &ver);

    public:
        static int isConnected(Graph graph);

        static string isContainsCycle(Graph graph);

        static string shortestPath(Graph graph, int start, int end);

        static string isBipartite(Graph graph);

        static string negativeCycle(Graph graph);
    };
}
