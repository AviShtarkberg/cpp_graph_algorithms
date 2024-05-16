// id:322530080 mail:avishb1213@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
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
    for (long unsigned int i = 0; i < matrix.size(); i++)
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
    if (!directed)
    {
        for (long unsigned int i = 0; i < matrix.size(); ++i)
        {
            for (long unsigned int j = 0; j < matrix.size(); ++j)
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

/*will check that the graphs have the same size and both directed or undirected.
will throw an exception if the values are not the same.
 */
void ariel::check_arg_for_operator(size_t size1, size_t size2, bool dir1, bool dir2)
{
    if (size1 != size2)
    {
        throw runtime_error("ERROR: cant add two matrixes with diffrent size");
    }
    if (dir1 != dir2)
    {
        throw runtime_error("ERROR: cant add directed to undirected graphs");
    }
}

/* after the multiplication of 2 matrixes will be used to
set the main diagonal of the matrix to be all zeros because we dont allow
self edges.
*/
void ariel::set_diagonal_zeros(vector<vector<int>> &m1, size_t size1)
{
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            if (i == j)
                m1[i][j] = 0;
        }
    }
}

/* will be used in + operator to add 2 matrixes, will run a nested for loop
that will add each cell of the 2 matrixes.
 */
vector<vector<int>> ariel::matrix_adder(const vector<vector<int>> m1, const vector<vector<int>> m2, size_t size1)
{
    vector<vector<int>> result_matrix(size1, vector<int>(size1, 0));
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            result_matrix[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result_matrix;
}

/* will be used in - operator to subtract 2 matrixes, will run a nested for loop
that will subtract each cell of the 2 matrixes.
 */
vector<vector<int>> ariel::matrix_subtractr(const vector<vector<int>> m1, const vector<vector<int>> m2, size_t size1)
{
    vector<vector<int>> result_matrix(size1, vector<int>(size1, 0));
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            result_matrix[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return result_matrix;
}

/* will be used in * operator to multiply 2 matrixes, will run a nested for loop
that will multiply the 2 matrxises.
 */
vector<vector<int>> ariel::matrix_multiplication(const vector<vector<int>> m1, const vector<vector<int>> m2, size_t size1)
{
    vector<vector<int>> result_matrix(size1, vector<int>(size1, 0));
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            result_matrix[i][j] = 0;
            for (size_t k = 0; k < size1; k++)
            {
                result_matrix[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    set_diagonal_zeros(result_matrix, size1);
    return result_matrix;
}

/* the + operator main function, will use the above check_arg_for_operator function to
check that the addtion of the 2 graphs is ligal. after that will use the matrix_adder function to
add the 2 matrixes.
*/
Graph ariel::operator+(const Graph &graph1, const Graph &graph2)
{
    {
        vector<vector<int>> m1 = graph1.get_adjacencyMatrix();
        vector<vector<int>> m2 = graph2.get_adjacencyMatrix();
        size_t size1 = m1.size();
        size_t size2 = m2.size();
        bool dir1 = graph1.get_directed();
        bool dir2 = graph2.get_directed();
        check_arg_for_operator(size1, size2, dir1, dir2);
        Graph res;
        vector<vector<int>> result_matrix = matrix_adder(m1, m2, size1);
        res.loadGraph(result_matrix, dir1);
        return res;
    }
}
/* += operator main function, will use the check_arg_for_operator function the check the
the matrix that we try to add will be legal to addtion with the matrix that we are working now.
will run a nested for loop to add this 2 graphs.
 */
void Graph::operator+=(Graph const &graph)
{
    vector<vector<int>> m1 = this->adjacencyMatrix;
    vector<vector<int>> m2 = graph.get_adjacencyMatrix();
    size_t size1 = m1.size();
    size_t size2 = m2.size();
    bool dir1 = this->_directed;
    bool dir2 = graph.get_directed();
    check_arg_for_operator(size1, size2, dir1, dir2);
    for (size_t i = 0; i < this->adjacencyMatrix.size(); i++)
    {
        for (size_t j = 0; j < this->adjacencyMatrix.size(); j++)
            this->adjacencyMatrix[i][j] += m2[i][j];
    }
}

/* unary plus, will return the graph as it is. will return it as addres
of the graph.
*/
Graph &Graph::operator+()
{
    static Graph result;
    result.loadGraph(this->adjacencyMatrix, this->_directed);
    return result;
}

/*minus operator: works same as + operator.
 */
Graph ariel::operator-(const Graph &graph1, const Graph &graph2)
{
    {
        vector<vector<int>> m1 = graph1.get_adjacencyMatrix();
        vector<vector<int>> m2 = graph2.get_adjacencyMatrix();
        size_t size1 = m1.size();
        size_t size2 = m2.size();
        bool dir1 = graph1.get_directed();
        bool dir2 = graph2.get_directed();
        check_arg_for_operator(size1, size2, dir1, dir2);
        Graph res;
        vector<vector<int>> result_matrix = matrix_subtractr(m1, m2, size1);
        res.loadGraph(result_matrix, dir1);
        return res;
    }
}

// works same as += operator.
void Graph::operator-=(Graph const &graph)
{
    vector<vector<int>> m1 = this->adjacencyMatrix;
    vector<vector<int>> m2 = graph.get_adjacencyMatrix();
    size_t size1 = m1.size();
    size_t size2 = m2.size();
    bool dir1 = this->_directed;
    bool dir2 = graph.get_directed();
    check_arg_for_operator(size1, size2, dir1, dir2);
    for (size_t i = 0; i < this->adjacencyMatrix.size(); i++)
    {
        for (size_t j = 0; j < this->adjacencyMatrix.size(); j++)
            this->adjacencyMatrix[i][j] -= m2[i][j];
    }
}

/*the unary - operator will return tha address of the graph that is multiplied by -1.
 */
Graph &Graph::operator-()
{
    static Graph result;
    result.loadGraph(this->adjacencyMatrix, this->_directed);
    for (size_t i = 0; i < this->adjacencyMatrix.size(); i++)
    {
        for (size_t j = 0; j < this->adjacencyMatrix.size(); j++)
            result.adjacencyMatrix[i][j] = this->adjacencyMatrix[i][j] * -1;
    }
    return result;
}

/* will use the check_arg_for_operator ahd matrix_multiplication to do the multiplication.
 */
Graph ariel::operator*(const Graph &graph1, const Graph &graph2)
{
    vector<vector<int>> m1 = graph1.get_adjacencyMatrix();
    vector<vector<int>> m2 = graph2.get_adjacencyMatrix();
    size_t size1 = m1.size();
    size_t size2 = m2.size();
    bool dir1 = graph1.get_directed();
    bool dir2 = graph2.get_directed();
    check_arg_for_operator(size1, size2, dir1, dir2);
    Graph res;
    vector<vector<int>> result_matrix = matrix_multiplication(m1, m2, size1);
    res.loadGraph(result_matrix, true);
    return res;
}

/* ++ operator, will run a nested for loop and increase each cell of the matrix by 1.
this funciton will firstly return reffrence of the graph and than do the increasment .
*/
Graph &Graph::operator++()
{
    vector<vector<int>> m1 = this->adjacencyMatrix;
    size_t size1 = m1.size();
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            if (m1[i][j] != 0)
                this->adjacencyMatrix[i][j]++;
        }
    }
    return *this;
}

/* same as above but here we return the graph it self and we firstly do the increasment
and than we return the graph.
 */
Graph Graph::operator++(int k)
{
    vector<vector<int>> m1 = this->adjacencyMatrix;
    Graph copy = *this;
    size_t size1 = m1.size();
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            if (m1[i][j] != 0)
                this->adjacencyMatrix[i][j]++;
        }
    }
    return copy;
}
// same function as above.
Graph &Graph::operator--()
{
    vector<vector<int>> m1 = this->adjacencyMatrix;
    size_t size1 = m1.size();
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            if (m1[i][j] != 0)
                this->adjacencyMatrix[i][j]--;
        }
    }
    return *this;
}

// same function as above.
Graph Graph::operator--(int k)
{
    vector<vector<int>> m1 = this->adjacencyMatrix;
    Graph copy = *this;
    size_t size1 = m1.size();
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            if (m1[i][j] != 0)
                this->adjacencyMatrix[i][j]--;
        }
    }
    return copy;
}

/*an output operator,  will be used to print the graph.
will use ostream to print the graph to the terminal.
will print all the neighbors of each vertex in the graph.
*/
ostream &ariel::operator<<(ostream &os, const Graph &g)
{
    vector<vector<int>> matrix = g.get_adjacencyMatrix();
    os << "The graph has: " << matrix.size() << " vertexes" << endl;
    for (long unsigned int i = 0; i < matrix.size(); i++)
    {
        string vertex = "vertex " + to_string(i) + " neighbors:";
        for (long unsigned int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] != 0)
            {
                vertex += to_string(j) + " ";
            }
        }
        os << vertex << endl;
    }
    return os;
}

// will be used to multiply all the edges by and int.
// will run a nested for loop that will multiply each cell of the
// matrix by the value that we want to multiply by.
Graph Graph::operator*(int m)
{
    vector<vector<int>> m1 = this->adjacencyMatrix;
    size_t size1 = m1.size();
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            this->adjacencyMatrix[i][j] *= m;
        }
    }
    return *this;
}

// funciton to check if one graph conatin the second one.
//  will be checked that all the edges in the first graph exist in the second one
// that will contain him.
bool ariel::check_contains(const vector<vector<int>> m1, const vector<vector<int>> m2, size_t size1)
{
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            if (m2[i][j] != 0 && m1[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

/* one graph is bigger than the other one if:
option 1) one contain the other one.
option 2) one graph has more edges than the other one.
option 3) one has more vertexes than the other one.
*/
bool ariel::operator>(const Graph &graph1, const Graph &graph2)
{
    Graph g1 = graph1;
    Graph g2 = graph2;
    vector<vector<int>> m1 = g1.get_adjacencyMatrix();
    vector<vector<int>> m2 = g2.get_adjacencyMatrix();
    size_t size1 = m1.size();
    size_t size2 = m2.size();
    int number_of_e1 = g1.get_number_of_edges();
    int number_of_e2 = g2.get_number_of_edges();
    if (size1 < size2)
    {
        return false;
    }
    if (check_contains(m1, m2, size2))
    {
        return true;
    }
    if (number_of_e1 > number_of_e2)
    {
        return true;
    }
    if (size1 > size2)
    {
        return true;
    }
    return false;
}

// will be used in == operators to check if the 2 graphs are the same.
bool ariel::check_equals(const vector<vector<int>> m1, const vector<vector<int>> m2, size_t size1)
{
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++)
        {
            if (m2[i][j] != m1[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

// 2 graphs will be equals if they have the same edges with same whieghts or
// if graph1 is not bigger than graph2 and graph2 is not bigger than graph1
bool ariel::operator==(const Graph &graph1, const Graph &graph2)
{
    Graph g1 = graph1;
    Graph g2 = graph2;
    vector<vector<int>> m1 = g1.get_adjacencyMatrix();
    vector<vector<int>> m2 = g2.get_adjacencyMatrix();
    size_t size1 = m1.size();
    size_t size2 = m2.size();
    if (size1 == size2 && (check_equals(m1, m2, size1)))
    {
        return true;
    }
    if (!(graph1 > graph2) && !(graph2 > graph1))
    {
        return true;
    }
    return false;
}

// will check if graph1 bigger than graph2 or graph1 equals to graph2
bool ariel::operator>=(const Graph &graph1, const Graph &graph2)
{
    if (graph1 > graph2 || graph1 == graph2)
    {
        return true;
    }
    return false;
}

// will check that graph1 not bigger than graph2 and graph1 not equals to graph2
bool ariel::operator<(const Graph &graph1, const Graph &graph2)
{
    if (!(graph1 > graph2) && !(graph1 == graph2))
    {
        return true;
    }
    return false;
}

// will check if graph1 < graph2 or graph1 == graph2
bool ariel::operator<=(const Graph &graph1, const Graph &graph2)
{
    if (graph1 < graph2 || graph1 == graph2)
    {
        return true;
    }
    return false;
}

// will check that graph a not equals to graph 2.
bool ariel::operator!=(const Graph &graph1, const Graph &graph2)
{
    if (!(graph1 == graph2))
    {
        return true;
    }
    return false;
}

// will print the matrix of the graph.
void Graph::print_adjacencyMatrix()
{
    size_t size = this->adjacencyMatrix.size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout << this->adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
