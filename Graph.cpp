//id:322530080 mail:avishb1213@gmail.com
#include "Graph.hpp"

using namespace ariel;
/* will creat the graph from the matrix that is given as n input.
   will be created with a boolean to determine if the graph
   is directed or not.
   if the matrix that is given is not squared will throw an exception.
*/
void Graph::loadGraph(vector<vector<int>> &matrix, bool directed)
{
    matrix_is_squared(matrix);
    is_symetric(matrix, directed);
    allDiagonalZeros(matrix);
    this->adjacencyMatrix = matrix;
    this->_directed = directed;
    set_has_negative_edge();
    set_number_of_edges();
}

/*will itarate the matrix and will check if there is a negative edge.
  will be useful for the algorithms.
*/
void Graph::set_has_negative_edge()
{
    vector<vector<int>> &matrix = this->adjacencyMatrix;
    for (long unsigned int i = 0; i < matrix.size(); i++)
    {
        for (long unsigned int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] < 0)
            {
                this->_has_negative_edge = true;
            }
        }
    }
}

// checks if the given matrix is squared and good to become a graph.
void Graph::matrix_is_squared(vector<vector<int>> &matrix)
{
    size_t numRows = matrix.size();
    size_t numCols = matrix[0].size();
    if (numRows != numCols)
    {
        throw runtime_error("ERROR: Matrix is not squared!");
    }
}

// will print the graph with the neighbors of each vertex.
void Graph::printGraph()
{
     vector<vector<int>> &matrix = this->adjacencyMatrix;
    cout << "The graph has: " << matrix.size() << " vertexes" << endl;
    for (long unsigned int  i = 0; i < matrix.size(); i++)
    {
        string vertex = "vertex " + to_string(i) + " neighbors:";
        for (long unsigned int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] != 0)
            {
                vertex += to_string(j) + " ";
            }
        }
        cout << vertex << endl;
    }
}

/*this function will set the number if edges to the graph.
  will be splited to 2 cases: if the graph is directed or not.
*/
void Graph::set_number_of_edges()
{
     vector<vector<int>> &matrix = this->adjacencyMatrix;
    int edge = 0;
    for (long unsigned int i = 0; i < matrix.size(); i++)
    {
        for (long unsigned int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] != 0)
            {
                edge++;
            }
        }
    }
    if (get_directed())
    {
        this->number_of_edges = edge;
    }
    else
    {
        this->number_of_edges = edge / 2;
    }
}

// will be checked for not directed graphs.
void Graph::is_symetric(vector<vector<int>> matrix, bool directed)
{
    if (directed)
    {
        vector<vector<int>> &matrix = this->adjacencyMatrix;
        for (long unsigned int i = 0; i < matrix.size(); ++i)
        {
            for (long unsigned int j = 0; j < i; ++j)
            {
                if (matrix[i][j] != matrix[j][i])
                    throw runtime_error("ERROR: Matrix is not symmetric and not directed!");
            }
        }
    }
}

// will be checked that all the diagonal edges are zeros.
void Graph::allDiagonalZeros(vector<vector<int>> matrix)
{
    long unsigned int n = matrix.size();
    for (long unsigned int i = 0; i < n; ++i)
    {
        if (matrix[i][i] != 0)
            throw runtime_error("ERROR: self edges are not allowed!");
    }
}
