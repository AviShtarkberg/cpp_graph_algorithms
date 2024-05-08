// id:322530080 mail:avishb1213@gmail.com
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
namespace ariel
{
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

        // inline methodes:
        vector<vector<int>> get_adjacencyMatrix()
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

        bool get_directed()
        {
            return this->_directed;
        }
    };
}