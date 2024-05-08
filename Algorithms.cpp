//id:322530080 mail:avishb1213@gmail.com
#include "Algorithms.hpp"
using namespace ariel;

    // was taken from : "https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/":
    // will run a regular dfs and will return the number of vertexes that was visited.
    void Algorithms::dfs_for_connected(int start, vector<bool> &visited, vector<vector<int>> matrix, int &visited_size)
{
    // will hold the number of nodes that been visited.
    visited_size++;
    // Set current node as visited.
    visited[start] = true;
    // For every node of the graph.
    for (size_t i = 0; i < matrix[start].size(); i++)
    {
        // If some node is adjacent to the current node.
        // and it has not already been visited.
        if (matrix[start][i] != 0 && (!visited[i]))
        {
            dfs_for_connected(i, visited, matrix, visited_size);
        }
    }
}

// Helper function for DFS traversal to check connectivity in an undirected graph
int Algorithms::isConnectedUndirected(vector<vector<int>> &matrix, vector<bool> &visited, int num_of_ver)
{
    int visted_size = 0;
    dfs_for_connected(0, visited, matrix, visted_size);
    return num_of_ver == visted_size;
}

// Helper function for DFS traversal to check connectivity in a directed graph
// the differance is that it will run from each vertex in a diracted graph.
int Algorithms::isConnectedDirected(vector<vector<int>> &matrix, int num_of_ver)
{
    for (int i = 0; i < num_of_ver; i++)
    {
        vector<bool> visited(num_of_ver, false);
        int visted_size = 0;
        dfs_for_connected(i, visited, matrix, visted_size);
        if (num_of_ver != visted_size)
        {
            return 0;
        }
    }
    return 1;
}

/*This method will check if the graph is connected.
 will be splited into 2 cases, if the graph is not directed will run one
 dfs, else will run dfs from each vertex.
*/
int Algorithms::isConnected(Graph graph)
{
    vector<vector<int>> matrix = graph.get_adjacencyMatrix();
    int num_of_ver = matrix.size();
    vector<bool> visited(num_of_ver, false);
    if (!graph.get_directed())
    {
        return isConnectedUndirected(matrix, visited, num_of_ver);
    }
    return isConnectedDirected(matrix, num_of_ver);
}

/*this method will run a dfs and will check if there is a back edge in the dfs forest.
will use a stack to store the current path of the dfs.
if vertex is not inside a cycle but was in the dfs traverse, it will pop it in the
end of the recurssiun from the stack to make sure that only ver that are part of
the cycle remains in the stack that will be returnd.
*/
bool Algorithms::dfs_for_cycle(Graph g, int start, vector<int> &visited,
                                vector<vector<int>> &matrix, vector<int> &is_in_path, stack<int> &path, size_t parent)
{
    visited[start] = true;
    is_in_path[start] = true;
    path.push(start);
    for (size_t i = 0; i < matrix[start].size(); i++)
    {
        if (matrix[start][i] != 0 && !visited[i])
        {
            {
                if (dfs_for_cycle(g, i, visited, matrix, is_in_path, path, start))
                {
                    return true;
                }
            }
        }
        else if (matrix[start][i] != 0 && is_in_path[i])
        {
            if (g.get_directed() || i != parent)
            {
                path.push(i);
                return true;
            }
        }
    }
    path.pop();
    is_in_path[start] = false;
    return false;
}

// sometimes the string of the path is reversed, this function will reveres that string
// and return the rigth one.
string Algorithms::return_path(vector<int> &reversed_path)
{
    if (reversed_path.empty())
    {
        return "0";
    }
    string p = "";
    for (int i = reversed_path.size() - 1; i >= 0; i--)
    {
        p += to_string(reversed_path[i]);
        if (i > 0)
            p += "->";
    }
    return p;
}

// will return the path that is inside the stack in reversed order.
vector<int> Algorithms::create_array_from_stack(stack<int> stack)
{
    vector<int> reversed_path(stack.size());
    int j = 0;
    while (!stack.empty())
    {
        reversed_path[j] = stack.top();
        j++;
        stack.pop();
    }
    return reversed_path;
}

/* this funciton will use the dfs_for_cycle method to return the cycle.
 will check if the stack that is filled in the dfs travese is not empty
 if so, the dfs_for_cycle method returnd true and the path need to be returnd,
 else will return 0 detecting that there is no cycle in the graph.
 */
string Algorithms::isContainsCycle(Graph graph)
{
    vector<vector<int>> matrix = graph.get_adjacencyMatrix();
    int num_of_ver = matrix.size();
    vector<int> visited(num_of_ver, false);
    for (int i = 0; i < num_of_ver; i++)
    {
        stack<int> path;
        vector<int> is_in_path(num_of_ver, false);
        dfs_for_cycle(graph, i, visited, matrix, is_in_path, path, i);
        if (!path.empty())
        {
            vector<int> p = create_array_from_stack(path);
            return return_path(p);
        }
    }
    return "0";
}

/*was taken from: https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
 this function will return the parents of each node in the shortest path,
*/
vector<int> Algorithms::dijkstra(vector<vector<int>> adjacencyMatrix, int startVertex)
{

    int nVertices = adjacencyMatrix.size();

    // shortestDistances[i] will hold the
    // shortest distance from src to i
    vector<int> shortestDistances(nVertices,0);

    // added[i] will true if vertex i is
    // included / in shortest path tree
    // or shortest distance from src to
    // i is finalized
    vector<bool> added(nVertices,false);

    // Initialize all distances as
    // INFINITE and added[] as false
    for (int vertexIndex = 0; vertexIndex < nVertices;
         vertexIndex++)
    {
        shortestDistances[vertexIndex] = INT_MAX;
        added[vertexIndex] = false;
    }

    // Distance of source vertex from
    // itself is always 0
    shortestDistances[startVertex] = 0;

    // Parent array to store shortest
    // path tree
    vector<int> parents(nVertices, -1);

    // The starting vertex does not
    // have a parent
    parents[startVertex] = INT_MIN;

    // Find shortest path for all
    // vertices
    for (int i = 1; i < nVertices; i++)
    {

        // Pick the minimum distance vertex
        // from the set of vertices not yet
        // processed. nearestVertex is
        // always equal to startNode in
        // first iteration.
        int nearestVertex = -1;
        int shortestDistance = INT_MAX;
        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++)
        {
            if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance)
            {
                nearestVertex = vertexIndex;
                shortestDistance = shortestDistances[vertexIndex];
            }
        }
        if (nearestVertex == -1)
            break;

        // Mark the picked vertex as
        // processed
        added[nearestVertex] = true;

        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++)
        {
            int edgeDistance = adjacencyMatrix[nearestVertex]
                                              [vertexIndex];

            if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex]))
            {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
            }
        }
    }
    return parents;
}

/*bellman ford method that is mostly simmilar to the above dijkstras algorithm.
    will run V-1 time relaxation and then another time to detect a negatice cycle
    if exists. if there is a negative cycle will run a loop to track the path of the cycle.
*/
vector<int> Algorithms::bellmanFord(Graph g, int startVertex, stack<int> &cycle)
{
    vector<vector<int>> adjacencyMatrix = g.get_adjacencyMatrix();
    int nVertices = adjacencyMatrix[0].size();
    vector<int> distances(nVertices, numeric_limits<int>::max());
    vector<int> parents(nVertices, -1);
    parents[startVertex] = INT_MIN;
    distances[startVertex] = 0;
    for (int i = 0; i < nVertices - 1; ++i)
    {
        for (int u = 0; u < nVertices; ++u)
        {
            for (int v = 0; v < nVertices; ++v)
            {
                if (adjacencyMatrix[u][v] != 0 && distances[u] != numeric_limits<int>::max() && distances[u] + adjacencyMatrix[u][v] < distances[v])
                {
                    if (g.get_directed() || parents[u] != v)
                    {
                        distances[v] = distances[u] + adjacencyMatrix[u][v];
                        parents[v] = u;
                    }
                }
            }
        }
    }
    for (int u = 0; u < nVertices; ++u)
    {
        for (int v = 0; v < nVertices; ++v)
        {
            int cur = adjacencyMatrix[u][v];
            int max = numeric_limits<int>::max();
            int u_dist = distances[u];
            if (cur != 0 && u_dist != max && u_dist + cur < distances[v])
            {
                if (g.get_directed() || parents[u] != v)
                {
                    // Negative cycle found
                    int temp = u;
                    while (parents[u] != temp)
                    {
                        cycle.push(u);
                        u = parents[u];
                    }
                    cycle.push(u);
                    cycle.push(parents[u]);
                    return vector<int>();
                }
            }
        }
    }
    return parents;
}

// will return the path of the shortest path between the requsted vertexes.
string Algorithms::end_shortest_path(vector<int> parents, int end)
{
    stack<int> path;
    Path(path, end, parents);
    if (path.empty())
    {
        return "-1";
    }
    return return_path(path);
}

// will recursivlly call the perenets array to create the path, based on
// that, that the shortesrt path contain only good edges.
void Algorithms::Path(stack<int> &path, int end, vector<int> &parents)
{
    if (end == INT_MIN)
    {
        return;
    }
    if (parents[end] == -1)
    {
        stack<int> empty;
        path = empty;
        return;
    }
    path.push(end);
    Path(path, parents[end], parents);
}

// the main function of the shortestPath method.
// will be splited into 2 cases - if the graph contain a negative edge or not.
string Algorithms::shortestPath(Graph graph, int start, int end)
{
    int size = graph.get_adjacencyMatrix().size();
    if (start < 0 || end > size)
    {
        throw runtime_error("ERROR: vertexes not in the graph!");
    }
    if (!graph.get_has_negative_edge()) // will use dijkstra
    {
        vector<vector<int>> matrix = graph.get_adjacencyMatrix();
        vector<int> parents = dijkstra(matrix, start);
        return end_shortest_path(parents, end);
    }
    else // will use bellman ford
    {
        stack<int> n;
        vector<int> parents = bellmanFord(graph, start, n);
        if (parents.empty())
        {
            return "-1";
        }
        return end_shortest_path(parents, end);
    }
    return "-1";
}

/* based on bfs from: "https://www.tutorialspoint.com/implementation-of-bfs-using-adjacency-matrix".
 this function will run bfs on the graph such that after visiting a new vertex
 its colored with a diffrent color from it parent. in this way will be checked if the graph is
 2-colored, if so the graph is bipartite.
*/
unordered_map<int, bool> Algorithms::bfs_for_bipartite(vector<bool> &visited, vector<vector<int>> matrix, int start, unordered_map<int, bool> &colors_map)
{
    int numVertices = matrix.size();
    queue<int> q;
    q.push(start);
    if (visited[start] == false)
    {
        colors_map[start] = true;
    }
    visited[start] = true;
    while (!q.empty())
    {
        // Dequeue a vertex from the queue
        int currentVertex = q.front();
        q.pop();

        // Iterate through all vertices
        for (int i = 0; i < numVertices; i++)
        {
            // Check if there is an edge between currentVertex and vertex i
            // and if vertex i is not visited
            if (matrix[currentVertex][i] != 0 && !visited[i])
            {
                // Enqueue the vertex i and mark it as visited
                q.push(i);
                visited[i] = true;
                colors_map[i] = !colors_map[currentVertex];
            }
            bool both_t = colors_map[i] && colors_map[currentVertex];
            bool both_f = !colors_map[i] && !colors_map[currentVertex];
            if (matrix[currentVertex][i] != 0 && (both_t || both_f))
            {
                unordered_map<int, bool> empty;
                return empty;
            }
        }
    }
    return colors_map;
}

/*This function will get the map from the bfs_for_bipartite method and will make a string that
splits the graph into 2 groups if possible.
*/
string Algorithms::return_partion(unordered_map<int, bool> umap)
{
    string first_side;
    string second_side;
    for (auto x : umap)
    {
        if (x.second)
        {
            first_side += to_string(x.first) + " ";
        }
        else
        {
            second_side += to_string(x.first) + " ";
        }
    }
    return "vertexes on first side-( " + first_side + ")   vertexes on second side- ( " + second_side + ")";
}

/*
will use the above function to ditect if the graph is bipartite
*/
string Algorithms::isBipartite(Graph graph)
{
    vector<vector<int>> matrix = graph.get_adjacencyMatrix();
    int num_of_ver = matrix.size();
    vector<bool> visited(num_of_ver, false);
    unordered_map<int, bool> colors_map;
    for (int i = 0; i < num_of_ver; i++)
    {
        unordered_map<int, bool> temp = bfs_for_bipartite(visited, matrix, i, colors_map);
        bool all = allVisited(visited);
        if (!temp.empty() && all)
        {
            return return_partion(colors_map);
        }
        if (temp.empty())
        {
            return "0";
        }
    }
    return "0";
}

// this function will return the negative cycle if one exist.
//  will be splited into 2- if the graph is connectet or not, will be checked with- isConnected().
string Algorithms::negativeCycle(Graph graph)
{
    int size = graph.get_adjacencyMatrix().size();
    stack<int> cycle;
    if (!isConnected(graph))
    {
        for (int i = 0; i < size; i++)
        {
            vector<int> parents = bellmanFord(graph, i, cycle);
            if (parents.empty())
            {
                return return_path(cycle);
            }
        }
    }
    else
    {
        vector<int> parents = bellmanFord(graph, 0, cycle);
        if (parents.empty())
        {
            return return_path(cycle);
        }
    }
    return "there is no negative cycle!";
}
// will creat the path string from a stack that holds the path.
string Algorithms::return_path(stack<int> &reversed_path)
{
    if (reversed_path.empty())
    {
        return "0";
    }
    string p = "";
    for (int i = reversed_path.size() - 1; i >= 0; i--)
    {
        p += to_string(reversed_path.top());
        if (i > 0)
            p += "->";
        reversed_path.pop();
    }
    return p;
}

// will check if all vertexes are visited.
bool Algorithms::allVisited(vector<bool> &ver)
{
    for (size_t i = 0; i < ver.size(); i++)
    {
        if (ver[i] == false)
            return false;
    }
    return true;
}
