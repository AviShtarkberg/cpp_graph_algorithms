// id:322530080 mail:avishb1213@gmail.com
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
namespace ariel
{
    void check_arg_for_operator(size_t size1, size_t size2, bool dir1, bool dir2);

    vector<vector<int>> matrix_adder(vector<vector<int>> m1, vector<vector<int>> m2, size_t size1);

    vector<vector<int>> matrix_subtractr(vector<vector<int>> m1, vector<vector<int>> m2, size_t size1);

    vector<vector<int>> matrix_multiplication(vector<vector<int>> m1, vector<vector<int>> m2, size_t size1);

    vector<vector<int>> matrix_multiplication(vector<vector<int>> m1, vector<vector<int>> m2, size_t size1);

    bool check_contains(vector<vector<int>> m1, vector<vector<int>> m2, size_t size1);

    bool check_equals(vector<vector<int>> m1, vector<vector<int>> m2, size_t size1);

    void set_diagonal_zeros(vector<vector<int>> &m1, size_t size1);

    class Graph
    {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        bool _directed;
        bool _has_negative_edge;
        int number_of_edges;
        // outline methods:
        void set_number_of_edges();
        void allDiagonalZeros(vector<vector<int>> matrix);
        void set_has_negative_edge();
        void is_symetric(vector<vector<int>> matrix, bool directed);

    public:
        // outline methods:
        void loadGraph(std::vector<std::vector<int>> &matrix, bool directed);

        void matrix_is_squared(std::vector<std::vector<int>> &matrix);

        void printGraph();

        void operator+=(Graph const &graph);

        Graph &operator+();

        void operator-=(Graph const &graph);

        Graph &operator-();

        Graph &operator++();

        Graph operator++(int k);

        Graph &operator--();

        Graph operator--(int k);

        Graph operator*(int a);

        friend Graph operator+(const Graph &graph1, const Graph &graph2);

        friend Graph operator-(const Graph &graph1, const Graph &graph2);

        friend Graph operator*(const Graph &graph1, const Graph &graph2);

        friend ostream &operator<<(ostream &os, const Graph &g);

        friend bool operator>(const Graph &graph1, const Graph &graph2);

        friend bool operator==(const Graph &graph1, const Graph &graph2);

        friend bool operator>=(const Graph &graph1, const Graph &graph2);

        friend bool operator<(const Graph &graph1, const Graph &graph2);

        friend bool operator<=(const Graph &graph1, const Graph &graph2);

        friend bool operator!=(const Graph &graph1, const Graph &graph2);

        void print_adjacencyMatrix();
        
        // inline methodes:
        vector<vector<int>>
        get_adjacencyMatrix() const
        {
            return this->adjacencyMatrix;
        }

        int get_number_of_edges()
        {
            return this->number_of_edges;
        }

        bool get_has_negative_edge()
        {
            return this->_has_negative_edge;
        }

        bool get_directed() const
        {
            return this->_directed;
        }
    };

    ostream &operator<<(ostream &os, const Graph &g);

    Graph operator+(const Graph &graph1, const Graph &graph2);

    Graph operator-(const Graph &graph1, const Graph &graph2);

    Graph operator*(const Graph &graph1, const Graph &graph2);

    bool operator>(const Graph &graph1, const Graph &graph2);

    bool operator==(const Graph &graph1, const Graph &graph2);

    bool operator>=(const Graph &graph1, const Graph &graph2);

    bool operator<(const Graph &graph1, const Graph &graph2);

    bool operator<=(const Graph &graph1, const Graph &graph2);

    bool operator!=(const Graph &graph1, const Graph &graph2);
}
